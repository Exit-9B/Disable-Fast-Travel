#pragma once

namespace Actor
{
	bool IsOnFlyingMount(RE::Actor* a_actor)
	{
		// SkyrimSE 1.6.318.0: 0x62CEA0
		using func_t = decltype(&IsOnFlyingMount);
		static REL::Relocation<func_t> func{ REL::ID(37901) };
		return func(a_actor);
	}

	bool CanFastTravel(RE::Actor* a_actor, bool a_arg2)
	{
		// SkyrimSE 1.6.318.0: 0x6C5560
		using func_t = decltype(&CanFastTravel);
		static REL::Relocation<func_t> func{ REL::ID(40444) };
		return func(a_actor, a_arg2);
	}
}

namespace MapMenu
{
	void MapClick(RE::MapMenu* a_mapMenu)
	{
		// SkyrimSE 1.6.318.0: 0x9162C0
		using func_t = decltype(&MapClick);
		REL::Relocation<func_t> func{ REL::ID(53113) };
		return func(a_mapMenu);
	}
}
