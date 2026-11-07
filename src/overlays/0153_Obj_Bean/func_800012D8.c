// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80937FC8(ObjBean* this, PlayState* play) {
    this->unk_1E8(this);

    if (Actor_TalkOfferAccepted(&this->dyna.actor, &play->state)) {
        if (Player_GetExchangeItemAction(play) == PLAYER_IA_MAGIC_BEANS) {
            ref_func_809383B4(this);
            Flags_SetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 0));
        }

        if (Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_1(&this->dyna.actor, 0))) {
            this->unk_1E4 = 5;
        } else {
            s32 pad;

            this->unk_1E4 = 0;
        }
    } else if (this->unk_1E4 == 1) {
        this->unk_1DF = 16;
        ref_func_809381B0(this);
    } else if (((this->collider.base.acFlags & AC_HIT) && (this->collider.base.ac != NULL) &&
                (this->collider.base.ac->id == ACTOR_OBJ_AQUA)) ||
               ((this->unk_1FF != 0) && (this->unk_1FE & 4) && (this->dyna.actor.xzDistToPlayer < 300.0f) &&
                ref_func_800FE9B4(play))) {
        ref_func_809375C8(this, play);
        Flags_SetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 1));
        this->unk_1E4 = 6;
        ref_func_80938670(this);
    } else if (this->unk_1FF != 0) {
        if (this->unk_1FE & 4) {
            this->collider.base.acFlags &= ~AC_HIT;
            if (this->dyna.actor.xzDistToPlayer < 150.0f) {
                CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
            }
        } else {
            Actor_OfferTalkExchangeEquiCylinder(&this->dyna.actor, play, 28.0f, PLAYER_IA_MAGIC_BEANS);
        }
    }
}
