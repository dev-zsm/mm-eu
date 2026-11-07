// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

s32 ObjOshihiki_MoveWithBlockUnder(ObjOshihiki* this, PlayState* play) {
    s32 pad;
    ObjOshihiki* blockUnder = ObjOshihiki_GetBlockUnder(this, play);

    if ((blockUnder != NULL) && (blockUnder->stateFlags & PUSHBLOCK_SETUP_PUSH)) {
        if (!ObjOshihiki_CheckWall(play, blockUnder->dyna.yRotation, blockUnder->direction, this)) {
            this->blockUnder = blockUnder;
        }
    }

    if (this->stateFlags & PUSHBLOCK_MOVE_UNDER) {
        if (this->blockUnder != NULL) {
            if (this->blockUnder->stateFlags & PUSHBLOCK_PUSH) {
                this->underDistX = this->blockUnder->dyna.actor.world.pos.x - this->blockUnder->dyna.actor.prevPos.x;
                this->underDistZ = this->blockUnder->dyna.actor.world.pos.z - this->blockUnder->dyna.actor.prevPos.z;
                this->dyna.actor.world.pos.x += this->underDistX;
                this->dyna.actor.world.pos.z += this->underDistZ;
                ObjOshihiki_UpdateInitPos(this);
                return true;
            }

            if (!(this->blockUnder->stateFlags & PUSHBLOCK_SETUP_PUSH)) {
                this->blockUnder = NULL;
            }
        }
    }
    return false;
}
