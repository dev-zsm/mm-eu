// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fireobj_ctx.h"

void FireObj_UpdateStateTransitions(PlayState* play, FireObj* fire) {
    Player* player = GET_PLAYER(play);
    WaterBox* waterBox;
    f32 waterY;
    s32 sp40 = false;
    u8 nextState;
    Vec3f dist;

    FireObj_StepSize(fire);
    fire->timer++;
    if (fire->ignitionDelay > 0) {
        fire->ignitionDelay--;
    } else if (fire->ignitionDelay == 0) {
        fire->ignitionDelay = -1;
        if ((fire->state == FIRE_STATE_NOT_LIT) || (fire->state == FIRE_STATE_SHRINKING)) {
            nextState = FIRE_STATE_GROWING;
        } else {
            nextState = FIRE_STATE_SHRINKING;
        }
        FireObj_SetState(fire, fire->dynamicSizeStep, nextState);
    }

    if ((fire->flags & FIRE_FLAG_WATER_EXTINGUISHABLE) && (fire->state != FIRE_STATE_NOT_LIT) &&
        BgCheck_GetWaterSurfaceNoBgId(play, &play->colCtx, fire->position.x, fire->position.z, &waterY, &waterBox) &&
        ((waterY - fire->position.y) > (6500.0f * fire->yScale))) {
        FireObj_SetState(fire, fire->dynamicSizeStep, FIRE_STATE_NOT_LIT);
    }
    if ((fire->flags & FIRE_FLAG_INTERACT_STICK) && (player->heldItemAction == PLAYER_IA_DEKU_STICK)) {
        Math_Vec3f_Diff(&player->meleeWeaponInfo[0].tip, &fire->position, &dist);
        if (Math3D_Vec3fMagnitudeSq(&dist) < SQ(20.0f)) {
            sp40 = true;
        }
    }

    if (sp40) {
        if (fire->state == FIRE_STATE_NOT_LIT) {
            if (player->unk_B28 > 0) {
                FireObj_SetState(fire, fire->dynamicSizeStep, FIRE_STATE_GROWING);
            }
        } else if (player->unk_B28 == 0) {
            player->unk_B28 = 210;
            SoundSource_PlaySfxAtFixedWorldPos(play, &fire->position, 20, NA_SE_EV_FLAME_IGNITION);
        } else if (player->unk_B28 < 200) {
            player->unk_B28 = 200;
        }
    }
}
