#include "Hooks.h"
#include "Settings.h"

void InitLogger()
{
#ifndef NDEBUG
	auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
#else
	auto path = logger::log_directory();
	if (!path) {
		return;
	}

	*path /= fmt::format("{}.log"sv, Version::PROJECT);
	auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
#endif

	auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));

#ifndef NDEBUG
	log->set_level(spdlog::level::trace);
#else
	log->set_level(spdlog::level::info);
	log->flush_on(spdlog::level::warn);
#endif

	spdlog::set_default_logger(std::move(log));
	spdlog::set_pattern("%s(%#): [%^%l%$] %v"s);

	logger::info("{} v{}"sv, Version::PROJECT, Version::NAME);
}

extern "C" DLLEXPORT constinit auto SKSEPlugin_Version =
[]() {
	SKSE::PluginVersionData v{};
	v.pluginVersion = Version::MAJOR;
	v.PluginName(Version::PROJECT);
	v.AuthorName("Parapets"sv);
	v.UsesAddressLibrary(true);
	return v;
}();


extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse)
{
	InitLogger();
	logger::info("{} loaded"sv, Version::PROJECT);

	SKSE::Init(a_skse);
	SKSE::AllocTrampoline(8);

	Hooks::Install();

	Settings::GetSingleton()->LoadSettings();

	auto messaging = SKSE::GetMessagingInterface();
	messaging->RegisterListener([](SKSE::MessagingInterface::Message* a_msg)
		{
			switch (a_msg->type) {
			case SKSE::MessagingInterface::kDataLoaded:
			{
				if (Settings::GetSingleton()->FlyingMountCruiseEnabled) {
					auto iniSettingCollection = RE::INISettingCollection::GetSingleton();
					if (iniSettingCollection) {
						auto cruiseSetting = iniSettingCollection->GetSetting(
							"bFlyingMountFastTravelCruiseEnabled:General");

						cruiseSetting->data.b = true;
						logger::info("Enabled flying mount cruise travel"sv);
					}
				}
				break;
			}
			}
		});

	return true;
}
