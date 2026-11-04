// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eventmgr.h"

s16 CutsceneManager_SetHudVisibility(s16 csHudVisibility) {
    u16 hudVisibility;

    switch (csHudVisibility) {
        case CS_HUD_VISIBILITY_NONE:
            hudVisibility = HUD_VISIBILITY_NONE_ALT;
            break;

        case CS_HUD_VISIBILITY_ALL:
            hudVisibility = HUD_VISIBILITY_ALL;
            break;

        case CS_HUD_VISIBILITY_A_HEARTS_MAGIC:
            hudVisibility = HUD_VISIBILITY_A_HEARTS_MAGIC_WITH_OVERWRITE;
            break;

        case CS_HUD_VISIBILITY_C_HEARTS_MAGIC:
            hudVisibility = HUD_VISIBILITY_HEARTS_MAGIC_C;
            break;

        case CS_HUD_VISIBILITY_ALL_NO_MINIMAP:
            hudVisibility = HUD_VISIBILITY_ALL_NO_MINIMAP;
            break;

        case CS_HUD_VISIBILITY_A_B_C:
            hudVisibility = HUD_VISIBILITY_A_B_C;
            break;

        case CS_HUD_VISIBILITY_B_MINIMAP:
            hudVisibility = HUD_VISIBILITY_B_MINIMAP;
            break;

        case CS_HUD_VISIBILITY_A:
            hudVisibility = HUD_VISIBILITY_A;
            break;

        default:
            hudVisibility = HUD_VISIBILITY_ALL;
            break;
    }

    Interface_SetHudVisibility(hudVisibility);

    return hudVisibility;
}
