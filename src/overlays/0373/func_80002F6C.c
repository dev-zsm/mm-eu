// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_DrawDoubleSoTCutscene(EnTest6* this, PlayState* play) {
    s32 pad1[2];
    Vec3f clockPos;
    s16 clockRotX;
    s16 clockNormalAngle;
    s32 i;
    Player* player = GET_PLAYER(play);
    s32 pad2;

    OPEN_DISPS(play->state.gfxCtx);

    this->gfx = POLY_OPA_DISP;
    this->clockAngle += TRUNCF_BINANG(this->clockSpeed);
    this->clockRingRotZ = this->clockAngle * 2;

    
    
    
    clockNormalAngle = (play->state.frames & 0x3C) * (DEG_TO_BINANG(22.5f) / 4);
    clockRotX = this->clockAngle + 0x4000;

    
    switch (player->transformation) {
        case PLAYER_FORM_DEKU:
            clockPos.x = player->actor.world.pos.y + 40.0f;
            break;

        case PLAYER_FORM_GORON:
            clockPos.x = player->actor.world.pos.y + 40.0f;
            break;

        case PLAYER_FORM_ZORA:
            clockPos.x = player->actor.world.pos.y + 40.0f;
            break;

        case PLAYER_FORM_FIERCE_DEITY:
            clockPos.x = player->actor.world.pos.y + 40.0f;
            break;

        default:
            clockPos.x = player->actor.world.pos.y + 40.0f;
            break;
    }

    
    for (i = 0; i < SOTCS_DOUBLE_NUM_CLOCKS; i++) {
        clockPos.y = Math_CosS(clockRotX) * this->clockDist;
        clockPos.z = Math_SinS(clockRotX) * this->clockDist;
        
        Matrix_RotateZS(this->clockRingRotZ, MTXMODE_NEW);

        Matrix_Translate(clockPos.x, clockPos.y, clockPos.z, MTXMODE_APPLY);
        Matrix_Scale(0.85f, 0.85f, 0.85f, MTXMODE_APPLY);
        
        Matrix_RotateXS(clockRotX, MTXMODE_APPLY);
        
        
        Matrix_RotateZS(clockNormalAngle, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(this->gfx++, play->state.gfxCtx);
        gDPSetPrimColor(this->gfx++, 0, 0xFF, this->clockColorGray, this->clockColorGray, this->clockColorGray, 255);
        gDPSetEnvColor(this->gfx++, 235, 238, 235, 255);
        gDPSetRenderMode(this->gfx++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
        gSPDisplayList(this->gfx++, gSongOfTimeClockDL);

        clockRotX += 0x10000 / SOTCS_DOUBLE_NUM_CLOCKS;
    }

    Lights_PointSetPosition(&this->lights[0].info, player->actor.world.pos.x, player->actor.world.pos.y - 10.0f,
                            player->actor.world.pos.z);
    Lights_PointSetColorAndRadius(&this->lights[0].info, 100, 250, 100, 200);

    POLY_OPA_DISP = this->gfx;

    CLOSE_DISPS(play->state.gfxCtx);
}
