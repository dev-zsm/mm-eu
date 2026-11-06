// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ref_func_80B9D334(ObjHunsui* this, PlayState* play) {
    Vec3f sp74;
    s32 i;
    s32 phi_s2 = 0;
    s32 phi_s3;

    switch (this->unk_160) {
        case OBJHUNSUI_F000_5:
            phi_s2 = 1;
            break;

        case OBJHUNSUI_F000_6:
            break;
    }

    if (this->unk_1B4 != NULL) {
        phi_s3 = false;
        for (i = 0; i < 8; i++) {
            if (this->unk_1B4->unk_300[phi_s2][i] == (phi_s2 + 1)) {
                phi_s3 = true;
                Math_Vec3f_Copy(&sp74, &this->unk_1B4->unk_238[phi_s2][i]);
                this->unk_174 = sp74.y - this->dyna.actor.home.pos.y;
                if (this->unk_174 > 240.0f) {
                    this->unk_174 = 240.0f;
                }
                this->unk_190 = 0.0f;
                this->unk_198 = 0.0f;
                this->unk_18A = 0;
            }
        }

        if (!phi_s3) {
            this->unk_174 = 240;
        }
    } else {
        Actor* dblueMovebg = SubS_FindActorCustom(play, &this->dyna.actor, NULL, ACTORCAT_BG, ACTOR_BG_DBLUE_MOVEBG,
                                                  NULL, ref_func_80B9D288);

        if (dblueMovebg != NULL) {
            this->unk_1B4 = (BgDblueMovebg*)dblueMovebg;
            ref_func_80B9D2BC(this, play);
        }
    }
}
