// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_turret.h"

void ObjTokeiTurret_Draw(Actor* thisx, PlayState* play) {
    ObjTokeiTurret* this = (ObjTokeiTurret*)thisx;
    Gfx* gfx;

    if (OBJ_TOKEI_TURRET_TIER_TYPE(thisx) == TURRET_TIER_TOP) {
        OPEN_DISPS(play->state.gfxCtx);

        gfx = POLY_OPA_DISP;
        gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);
        MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
        gSPDisplayList(gfx++, gClockTownTurretPlatformTopDL);
        POLY_OPA_DISP = gfx;

        CLOSE_DISPS(play->state.gfxCtx);
    } else if (OBJ_TOKEI_TURRET_TIER_TYPE(thisx) == TURRET_TIER_BASE) {
        Gfx_DrawDListOpa(play, gClockTownTurretPlatformBaseDL);
    } else {
        Gfx_DrawDListOpa(play, gClockTownFlagsDL);
    }
}
