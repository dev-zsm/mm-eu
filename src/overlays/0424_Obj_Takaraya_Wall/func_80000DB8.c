// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

void ObjTakarayaWall_Draw(Actor* thisx, PlayState* play) {
    Vec3f audioPos;
    ObjTakarayaWall* this = (ObjTakarayaWall*)thisx;
    MtxF* mtx;
    Gfx* gfx;
    s32 i;
    s32 j;

    OPEN_DISPS(play->state.gfxCtx);

    mtx = Matrix_GetCurrent();

    gfx = POLY_OPA_DISP;
    gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    for (i = 0; i < TAKARAYA_WALL_ROWS; i++) {
        for (j = 0; j < TAKARAYA_WALL_COLUMNS; j++) {
            if (sTakarayaWallHeights[i][j] > 0.0f) {
                mtx->xw = (i * 120) - 1620;
                mtx->yw = sTakarayaWallHeights[i][j] + (this->actor.world.pos.y - 120.0f);
                mtx->zw = (j * 120) + 60;

                MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);

                if (((i + j) % 2) != 0) {
                    gSPDisplayList(gfx++, gTreasureChestShopWallWhiteDL);
                } else {
                    gSPDisplayList(gfx++, gTreasureChestShopWallBlackDL);
                }

                if (sTakarayaWallStates[i][j] != TAKARAYA_WALL_INACTIVE) {
                    audioPos.x = mtx->xw;
                    audioPos.y = mtx->yw;
                    audioPos.z = mtx->zw;

                    SkinMatrix_Vec3fMtxFMultXYZ(&play->viewProjectionMtxF, &audioPos,
                                                &sTakarayaWallAudioPositions[i][j]);

                    if (sTakarayaWallStates[i][j] == TAKARAYA_WALL_RISING) {
                        Audio_PlaySfx_AtPos(&sTakarayaWallAudioPositions[i][j], NA_SE_EV_ROCK_CUBE_RISING - SFX_FLAG);
                    } else { 
                        Audio_PlaySfx_AtPos(&sTakarayaWallAudioPositions[i][j], NA_SE_EV_ROCK_CUBE_FALL - SFX_FLAG);
                    }
                }
            }
        }
    }

    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(play->state.gfxCtx);
}
