// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9C854(BgHakuginPost* this, PlayState* play) {
    s32 pad;
    s32 sp38 = false;
    s32 pad2;
    s32 i;
    s32 pad3;
    s32 sp28;

    if (this->unk_174 != 0) {
        if (Flags_GetSwitch(play, this->dyna.actor.home.rot.z & 0x7F)) {
            sp28 = true;

            for (i = 0; i < ref_D_80A9E028.count; i++) {
                ColliderCylinder* collider = ref_D_80A9E028.unk_0000[i].collider;

                if ((collider != NULL) && Flags_GetSwitch(play, ref_D_80A9E028.unk_0000[i].switchFlag)) {
                    sp28 = false;
                    break;
                }
            }

            if (sp28) {
                sp38 = true;
            }
        }
    }

    if (sp38) {
        Flags_SetSwitch(play, BGHAKUGINPOST_GET_SWITCH_FLAG_2(&this->dyna.actor));
    } else {
        Flags_UnsetSwitch(play, BGHAKUGINPOST_GET_SWITCH_FLAG_2(&this->dyna.actor));
    }
}
