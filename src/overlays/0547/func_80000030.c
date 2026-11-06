// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kinoko.h"

void ObjKinoko_Update(Actor* thisx, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 pad;

    if (player->currentMask != PLAYER_MASK_SCENTS) {
        thisx->draw = NULL;
        thisx->hintId = TATL_HINT_ID_NONE;
        thisx->flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    } else {
        thisx->draw = ObjKinoko_Draw;
        thisx->hintId = TATL_HINT_ID_MUSHROOM;
        thisx->flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        if (Actor_HasParent(thisx, play)) {
            Flags_SetCollectible(play, OBJ_KINOKO_GET_FLAG(thisx));
            Actor_Kill(thisx);
            return;
        }
        Actor_OfferGetItem(thisx, play, GI_MAX, 20.0f, 10.0f);
        if (Math_SmoothStepToF(&thisx->speed, 0.0f, 0.04f, 2.0f, 0.5f) < 0.5f) {
            thisx->scale.x = 0.0f;
            thisx->speed = 110.0f;
            thisx->velocity.x = 0.2f;
        }
        if (Math_SmoothStepToF(&thisx->scale.x, thisx->velocity.x, 0.04f, 0.004f, 0.001f) <
            ((thisx->velocity.x == 0.0f) ? 0.0f : 0.05f)) {
            thisx->velocity.x = 0.0f;
        }
        thisx->scale.y = thisx->scale.x;
        thisx->scale.z = thisx->scale.x;
        thisx->shape.rot.y = Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) + 0x8000;
    }
}
