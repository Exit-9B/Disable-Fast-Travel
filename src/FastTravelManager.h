#pragma once

class FastTravelManager
{
public:
	static void InstallHooks();
	static void InstallMarkerClickHook();

private:
	FastTravelManager() = default;

	static bool FastTravelMarkerClick(RE::MapMenu* a_mapMenu);
};
