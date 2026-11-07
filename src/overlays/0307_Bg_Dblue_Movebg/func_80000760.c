// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2A1E0(BgDblueMovebg* this, PlayState* play) {
    s32 temp_v0 = ref_func_80A29A80(play, this->switchFlag, this->unk_1BC);

    if (temp_v0 != this->unk_178) {
        switch (temp_v0) {
            case 1:
            case 2:
                this->unk_17E = 40;
                break;

            case 0:
            case 3:
                this->unk_17E = 15;
                break;
        }
    }
    this->unk_178 = temp_v0;

    if (this->unk_17E <= 0) {
        this->unk_1CE = ref_D_80A2B96C[temp_v0];
    } else {
        this->unk_17E--;
    }

    Math_StepToS(&this->unk_1CC, this->unk_1CE, 12);
    this->dyna.actor.shape.rot.y += this->unk_1CC;

    if (play->roomCtx.curRoom.num == 0) {
        this->opaDList = gGreatBayTempleObjectGearShaftWithPlatformsDL;
    } else if (play->roomCtx.curRoom.num == 8) {
        this->opaDList = NULL;
    }

    if (play->roomCtx.curRoom.num != this->unk_170) {
        if (play->roomCtx.curRoom.num != this->unk_171) {
            if ((play->roomCtx.prevRoom.num != this->unk_170) && (play->roomCtx.prevRoom.num != this->unk_171)) {
                ref_D_80A2BBF4.unk_01 = 0;
                Actor_Kill(&this->dyna.actor);
            }
        }
    }
}
