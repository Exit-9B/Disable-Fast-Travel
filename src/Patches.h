#pragma once

namespace Patch
{
	using MarkerClickCallback = bool(RE::MapMenu*);

	bool InstallMarkerClickPatch(MarkerClickCallback* a_callback);
}
