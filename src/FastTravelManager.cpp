#include "FastTravelManager.h"
#include "Extensions.h"
#include "Settings.h"
#include <xbyak/xbyak.h>

void FastTravelManager::InstallHooks()
{
	InstallMarkerClickHook();
}

void FastTravelManager::InstallMarkerClickHook()
{
	constexpr REL::ID MapMenu_MarkerClick_offset{ 52208 };
	static REL::Relocation<std::uintptr_t> hook{ MapMenu_MarkerClick_offset,
#ifndef SKYRIMVR
												 0x2BC
#else
												 0x34D
#endif
	};

	struct Patch : Xbyak::CodeGenerator
	{
		Patch()
		{
#ifndef SKYRIMVR
			mov(rcx, rsi);
			nop(11, false);
#else
			mov(rcx, r14);
			nop(13, false);
#endif
		}
	};

	Patch patch{};
	int size =
#ifndef SKYRIMVR
		14
#else
		16
#endif
		;
	if (patch.getSize() != size

	) {
		RE::stl::report_and_fail(
			fmt::format("Patch size was {} bytes, expected {} bytes"sv, patch.getSize(), size));
	}

	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());

	auto& trampoline = SKSE::GetTrampoline();
	trampoline.write_call<6>(hook.address() + 0x3, FastTravelMarkerClick);

	logger::info("Installed marker click hook"sv);
}

bool FastTravelManager::FastTravelMarkerClick(RE::MapMenu* a_mapMenu)
{
	auto playerCharacter = RE::PlayerCharacter::GetSingleton();

	bool disabled = Settings::GetSingleton()->FastTravelDisabled;

	if (!disabled || ::Actor::IsOnFlyingMount(playerCharacter)) {
		if (::Actor::CanFastTravel(playerCharacter, 0)) {
			return true;
		}
	}

	::MapMenu::MapClick(a_mapMenu);
	return false;
}
