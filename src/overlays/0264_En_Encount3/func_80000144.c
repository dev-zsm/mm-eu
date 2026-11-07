// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount3.h"

void ref_func_809AD084(EnEncount3* this, PlayState* play) {
    if ((this->switchFlag > SWITCH_FLAG_NONE) && Flags_GetSwitch(play, this->switchFlag)) {
        Actor_Kill(&this->actor);
        return;
    }
    if (!(this->unk16C < this->actor.xzDistToPlayer) && (Player_GetMask(play) == PLAYER_MASK_GARO) && !ref_D_809AD810) {
        if (this->timer > 0) {
            this->timer--;
        } else {
            this->child =
                Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, this->childActorId, this->actor.world.pos.x,
                                   this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, this->childParams);
            if (this->child != NULL) {
                this->unk14E++;
                ref_D_809AD810 = true;
                this->actionFunc = ref_func_809AD194;
            }
        }
    }
}
