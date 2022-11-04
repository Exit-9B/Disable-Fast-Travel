#include "Patches.h"
#include <xbyak/xbyak.h>

bool Patch::InstallMarkerClickPatch(MarkerClickCallback* a_callback)
{
	// SkyrimSE 1.6.318.0: 0x913140
	constexpr REL::ID MapMenu_MarkerClick_offset(53095);
	static REL::Relocation<std::uintptr_t> hook{ MapMenu_MarkerClick_offset, 0x31F };

	constexpr auto pattern = REL::make_pattern<"33 D2 48 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ??">();
	if (!pattern.match(hook.address())) {
		logger::critical("Assembly did not match, failed to install"sv);
		return false;
	}

	struct Patch : Xbyak::CodeGenerator
	{
		Patch()
		{
			mov(rcx, r14);
		}
	};

	Patch patch{};
	if (patch.getSize() > 8) {
		logger::critical("Patch was too large, failed to install"sv);
		return false;
	}

	auto& trampoline = SKSE::GetTrampoline();

	REL::safe_fill(hook.address(), REL::NOP, 0xE);
	REL::safe_write(hook.address(), patch.getCode(), patch.getSize());
	trampoline.write_call<6>(hook.address() + patch.getSize(), a_callback);

	logger::info("Installed marker click hook"sv);
	return true;
}
