#include "FastTravelManager.h"
#include "Extensions.h"
#include "Patches.h"
#include "Settings.h"

void FastTravelManager::InstallHooks()
{
	Patch::InstallMarkerClickPatch(FastTravelMarkerClick);
}

bool FastTravelManager::FastTravelMarkerClick(RE::MapMenu* a_mapMenu)
{
    auto playerCharacter = RE::PlayerCharacter::GetSingleton();

	bool disabled = Settings::GetSingleton()->FastTravelDisabled;

	if (!disabled || Actor::IsOnFlyingMount(playerCharacter)) {
		if (Actor::CanFastTravel(playerCharacter, 0)) {
			return true;
		}
	}

	MapMenu::MapClick(a_mapMenu);
	return false;
}
