// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_scene_proc.h"

void Scene_DrawConfigGreatBayTemple(PlayState* play) {
    static Gfx sGreatBayTempleColorSetDL[] = {
        gsDPSetPrimColor(0, 255, 255, 255, 255, 255),
        gsSPEndDisplayList(),
    };
    s32 lodFrac;
    s32 i;
    Gfx* gfx;
    Gfx* gfxHead;

    if (Flags_GetSwitch(play, 0x33) && Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35) &&
        Flags_GetSwitch(play, 0x36)) {
        BgCheck_SetContextFlags(&play->colCtx, BGCHECK_FLAG_REVERSE_CONVEYOR_FLOW);
    } else {
        BgCheck_UnsetContextFlags(&play->colCtx, BGCHECK_FLAG_REVERSE_CONVEYOR_FLOW);
    }

    gfxHead = GRAPH_ALLOC(play->state.gfxCtx, 18 * sizeof(Gfx));

    AnimatedMat_Draw(play, play->sceneMaterialAnims);

    OPEN_DISPS(play->state.gfxCtx);

    for (gfx = gfxHead, i = 0; i < 9; i++, gfx += 2) {
        lodFrac = 0;

        bcopy(sGreatBayTempleColorSetDL, gfx, sizeof(sGreatBayTempleColorSetDL));

        switch (i) {
            case 0:
                if (Flags_GetSwitch(play, 0x33) && Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35) &&
                    Flags_GetSwitch(play, 0x36)) {
                    lodFrac = 255;
                }
                break;

            case 1:
                if (Flags_GetSwitch(play, 0x37)) {
                    lodFrac = 68;
                }
                break;

            case 2:
                if (Flags_GetSwitch(play, 0x37) && Flags_GetSwitch(play, 0x38)) {
                    lodFrac = 68;
                }
                break;

            case 3:
                if (Flags_GetSwitch(play, 0x37) && Flags_GetSwitch(play, 0x38) && Flags_GetSwitch(play, 0x39)) {
                    lodFrac = 68;
                }
                break;

            case 4:
                if (!(Flags_GetSwitch(play, 0x33))) {
                    lodFrac = 68;
                }
                break;

            case 5:
                if (Flags_GetSwitch(play, 0x34)) {
                    lodFrac = 68;
                }
                break;

            case 6:
                if (Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35)) {
                    lodFrac = 68;
                }
                break;

            case 7:
                if (Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35) && Flags_GetSwitch(play, 0x36)) {
                    lodFrac = 68;
                }
                break;

            case 8:
                if (Flags_GetSwitch(play, 0x3A)) {
                    lodFrac = 68;
                }
                break;
        }

        gDPSetPrimColor(gfx, 0, lodFrac, 255, 255, 255, 255);
    }

    gSPSegment(POLY_OPA_DISP++, 0x06, gfxHead);
    gSPSegment(POLY_XLU_DISP++, 0x06, gfxHead);

    CLOSE_DISPS(play->state.gfxCtx);
}
