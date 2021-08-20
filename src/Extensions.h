#pragma once

namespace Actor
{
	bool IsOnFlyingMount(RE::Actor* a_actor)
	{
		using func_t = decltype(&IsOnFlyingMount);
		static REL::Relocation<func_t> func{ REL::ID(36877) };
		return func(a_actor);
	}

	bool CanFastTravel(RE::Actor* a_actor, bool a_arg2)
	{
		using func_t = decltype(&CanFastTravel);
		static REL::Relocation<func_t> func{ REL::ID(39372) };
		return func(a_actor, a_arg2);
	}
}

namespace MapMenu
{
	void MapClick(RE::MapMenu* a_mapMenu)
	{
		using func_t = decltype(&MapClick);
		REL::Relocation<func_t> func{ REL::ID(52226) };
		return func(a_mapMenu);
	}
}
