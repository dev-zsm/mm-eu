// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80937DEC(ObjBean* this, PlayState* play) {
    s32 pad;
    s32 sp20 = OBJBEAN_GET_C000(&this->dyna.actor);

    if (sp20 == ENOBJBEAN_GET_C000_1) {
        s32 pad2;

        if (ref_func_809374F8(this, play) == NULL) {
            this->unk_1FF = false;
        } else {
            this->unk_1FF = true;
        }
    } else {
        this->unk_1FF = false;
    }

    if (this->unk_1FF && !Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 1)) &&
        Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 0)) && ref_func_800FE9B4(play)) {
        Flags_SetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 1));
    }

    if (this->unk_1FF && Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 1))) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if (sp20 == ENOBJBEAN_GET_C000_2) {
        this->dyna.actor.draw = ref_func_80938F50;
    } else {
        this->dyna.actor.draw = ref_func_80938E00;
    }

    if (this->unk_1FF && Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 0))) {
        this->unk_1FE |= 5;
        ref_func_80937C30(this);
    } else {
        this->unk_1FE |= 1;
        ref_func_80937C10(this);
    }

    if (Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_1(&this->dyna.actor, 0))) {
        this->unk_1E4 = 5;
    } else {
        this->unk_1E4 = 0;
    }

    ref_func_80937FB0(this);
}
