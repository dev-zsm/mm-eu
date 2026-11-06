// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808BA550(DoorWarp1* this, PlayState* play) {
    Player* player2 = GET_PLAYER(play);
    Player* player = GET_PLAYER(play);
    s16 i;
    f32 temp_f0;
    f32 temp_f2;
    s32 temp;
    s32 tempS;

    if (this->unk_1CA != 0) {
        this->unk_1CA--;
    }

    if (this->unk_1CA < 0x1F) {
        temp_f0 = 0.0f;
        switch (player2->transformation) {
            case PLAYER_FORM_FIERCE_DEITY:
                temp_f0 = -37.0f;
                break;

            case PLAYER_FORM_GORON:
                temp_f0 = -37.0f;
                break;

            case PLAYER_FORM_ZORA:
                temp_f0 = -37.0f;
                break;

            case PLAYER_FORM_DEKU:
                temp_f0 = -20.0f;
                break;

            case PLAYER_FORM_HUMAN:
                temp_f0 = -25.0f;
                break;

            default:
                break;
        }

        temp_f2 = this->dyna.actor.world.pos.y + (this->dyna.actor.shape.yOffset * 0.1f) + temp_f0;

        if (ref_D_808BC004 < temp_f2) {
            player->actor.world.pos.y = temp_f2;
        }

        if (this->unk_1CA <= 0) {
            if (this->unk_1CC < 4000) {
                this->unk_1CC += 40;
            }
            player->actor.world.rot.y -= this->unk_1CC;
            player->actor.shape.rot.y -= this->unk_1CC;
        }
        Math_SmoothStepToF(&player->actor.world.pos.x, this->dyna.actor.world.pos.x, 0.5f, 0.1f, 0.01f);
        Math_SmoothStepToF(&player->actor.world.pos.z, this->dyna.actor.world.pos.z, 0.5f, 0.1f, 0.01f);
    }

    this->unk_1D0++;
    if ((ref_D_808BC000 < this->unk_1D0) && (gSaveContext.nextCutsceneIndex == 0xFFEF)) {
        ref_func_808BA10C(this, play);
    }

    if (this->unk_1D0 > 140) {
        play->envCtx.fillScreen = true;
        temp_f0 = (this->unk_1D0 - 140) / 20.0f;
        if (temp_f0 > 1.0f) {
            temp_f0 = 1.0f;
        }
        play->envCtx.screenFillColor[0] = 160;
        play->envCtx.screenFillColor[1] = 160;
        play->envCtx.screenFillColor[2] = 160;
        play->envCtx.screenFillColor[3] = 255.0f * temp_f0;
    }

    Lights_PointNoGlowSetInfo(&this->unk_1E0, player->actor.world.pos.x + 10.0f, player->actor.world.pos.y + 10.0f,
                              player->actor.world.pos.z + 10.0f, 235, 255, 255, 255);
    Lights_PointNoGlowSetInfo(&this->unk_1F4, player->actor.world.pos.x - 10.0f, player->actor.world.pos.y - 10.0f,
                              player->actor.world.pos.z - 10.0f, 235, 255, 255, 255);
    Math_SmoothStepToF(&this->dyna.actor.shape.yOffset, 800.0f, 0.2f, 15.0f, 0.01f);
    this->dyna.actor.shape.rot.y += 0x320;
    Math_SmoothStepToF(&this->unk_1BC, 1.13f, 0.2f, 0.1f, 0.01f);
    Math_StepToF(&this->unk_1A4, 2.0f, 0.003f);
    Math_StepToF(&this->unk_1A8, 10.0f, 0.006f);
    Math_SmoothStepToF(&this->unk_1B0, 0.0f, 0.2f, 3.0f, 0.01f);
    Math_SmoothStepToF(&this->unk_1B4, 0.0f, 0.2f, 2.0f, 0.01f);
    Math_SmoothStepToF(&this->unk_1B8, 255.0f, 0.1f, 1.0f, 0.01f);

    tempS = ref_D_808BC000;
    if (1) {}
    temp_f0 = 1.0f - ((f32)(ref_D_808BC000 - this->unk_1D0) / ((ref_D_808BC000 - tempS) + 100));
    if (temp_f0 > 0.0f) {
        for (i = 0; i < ARRAY_COUNT(play->envCtx.adjLightSettings.light1Color); i++) {
            play->envCtx.adjLightSettings.ambientColor[i] = play->envCtx.adjLightSettings.fogColor[i] =
                play->envCtx.adjLightSettings.light1Color[i] = -255.0f * temp_f0;
        }

        play->envCtx.adjLightSettings.fogNear = -500.0f * temp_f0;
        if (play->envCtx.adjLightSettings.fogNear < -300) {
            play->roomCtx.curRoom.segment = NULL;
        }
    }
}
