// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2A32C(BgDblueMovebg* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 phi_v0;
    f32 phi_f0;
    s32 phi_v1;

    if (this->dyna.pushForce != 0.0f) {
        this->unk_18E = BINANG_SUB(this->dyna.actor.shape.rot.y, this->dyna.actor.yawTowardsPlayer);
        this->unk_184 = this->dyna.actor.xzDistToPlayer;

        if (this->dyna.pushForce >= 0.0f) {
            phi_f0 = 1.0f;
        } else {
            phi_f0 = -1.0f;
        }

        if (BINANG_SUB(this->dyna.actor.yawTowardsPlayer, player->actor.shape.rot.y) > 0) {
            phi_v0 = -1;
        } else {
            phi_v0 = 1;
        }
        this->unk_17E = phi_v0 * phi_f0;

        phi_v1 = false;
        if (this->unk_17E > 0) {
            phi_v1 = true;
        }

        if (phi_v1) {
            this->unk_180 = CutsceneManager_GetCutsceneCustomValue(this->csIdList[0]);
            this->csId = this->csIdList[0];
            this->unk_172 |= 8;
            this->actionFunc = ref_func_80A2A444;
        } else {
            player->stateFlags2 &= ~PLAYER_STATE2_10;
            this->dyna.pushForce = 0.0f;
        }
    }
}
