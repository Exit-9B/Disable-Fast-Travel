#include "Hooks.h"
#include "FastTravelManager.h"

namespace Hooks
{
	void Install()
	{
		FastTravelManager::InstallHooks();
		logger::info("Installed all hooks"sv);
	}
}
