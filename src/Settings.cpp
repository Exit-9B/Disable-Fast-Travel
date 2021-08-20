#include "Settings.h"
#include <SimpleIni.h>

Settings* Settings::GetSingleton()
{
	static Settings singleton{};
	return std::addressof(singleton);
}

void Settings::LoadSettings()
{
	CSimpleIniA ini;
	ini.SetUnicode();
	ini.LoadFile(fmt::format(R"(.\Data\SKSE\Plugins\{}.ini)", Version::PROJECT).c_str());

	FastTravelDisabled = ini.GetBoolValue("FastTravel", "bFastTravelDisabled", true);
	FlyingMountCruiseEnabled = ini.GetBoolValue("FastTravel", "bFlyingMountCruiseEnabled", true);
}
