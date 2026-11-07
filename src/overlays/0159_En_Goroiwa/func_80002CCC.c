// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

s32 ref_func_8094156C(EnGoroiwa* this, PlayState* play) {
    Actor* actor = &this->actor;
    s32 params = ENGOROIWA_GET_C000(&this->actor);
    EnGoroiwaStruct* ptr;
    s32 i;
    s32 phi_s0_2 = false;
    Vec3f sp80;

    if ((this->collider.base.acFlags & AC_HIT) && ((params == ENGOROIWA_C000_1) || (params == ENGOROIWA_C000_2))) {
        if (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x4000) {
            s16 sp7E = BINANG_SUB(actor->yawTowardsPlayer, this->actor.world.rot.y);
            f32 temp;
            f32 temp2;
            f32 temp3;

            this->unk_1CC = 50;
            this->unk_1E8[0].unk_1E = BINANG_SUB(this->actor.yawTowardsPlayer, 0x4000);
            this->unk_1E8[0].unk_24 = Rand_ZeroOne() * -600.0f;
            this->unk_1E8[1].unk_1E = BINANG_ADD(this->actor.yawTowardsPlayer, 0x4000);
            this->unk_1E8[1].unk_24 = Rand_ZeroOne() * 600.0f;

            for (i = 0; i < ARRAY_COUNT(this->unk_1E8); i++) {
                ptr = &this->unk_1E8[i];

                ptr->unk_00.x = this->actor.world.pos.x;
                ptr->unk_00.y = this->actor.world.pos.y + this->unk_1DC;
                ptr->unk_00.z = this->actor.world.pos.z;

                temp = Rand_ZeroOne();
                temp2 = Math_SinS(ptr->unk_1E);
                temp3 = Math_SinS(this->actor.world.rot.y);

                ptr->unk_0C = ((1.0f / ref_D_80942DFC[this->unk_1E4]) * (temp3 * 14.0f * this->actor.speed)) +
                              (temp2 * (temp + 5.0f));

                ptr->unk_10 = (Rand_ZeroOne() * 11.0f) + 20.0f;

                temp = Rand_ZeroOne();
                temp2 = Math_CosS(ptr->unk_1E);
                temp3 = Math_CosS(this->actor.world.rot.y);
                ptr->unk_14 = ((1.0f / ref_D_80942DFC[this->unk_1E4]) * ((temp3 * 14.0f) * this->actor.speed)) +
                              (temp2 * (temp + 5.0f));

                ptr->unk_1C = 0;
                ptr->unk_20 = 0;
                ptr->unk_22 = (s32)(Rand_ZeroOne() * 400.0f) + 1100;

                temp3 = Rand_ZeroOne();
                temp2 = Math_CosS(sp7E);
                ptr->unk_26 = (s32)(temp2 * 3000.0f) + (s32)(600.0f * (temp3 - 0.5f));
                ptr->unk_2D = 0;
                ptr->unk_2C = 0;
            }

            ref_func_809421E0(this);
            sp80.x = this->actor.world.pos.x;
            sp80.y = this->actor.world.pos.y + this->unk_1DC;
            sp80.z = this->actor.world.pos.z;
            ref_func_80940588(play, &sp80, ref_D_80942E0C[params], &ref_D_80942E30[params], &ref_D_80942E3C[params],
                          this->actor.scale.x);
            ref_func_80941274(this, play);
            phi_s0_2 = true;
        } else if (((params == ENGOROIWA_C000_1) &&
                    (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & (0x400 | 0x100))) ||
                   ((params == ENGOROIWA_C000_2) && (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags &
                                                     (0x80000000 | 0x800 | 0x400 | 0x100 | 0x8)))) {
            this->unk_1CC = 50;
            if ((params == ENGOROIWA_C000_2) &&
                (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x800)) {
                this->unk_1E6 = true;
            }
            ref_func_80940090(this, play);
            ref_func_80941274(this, play);
            ref_func_809425CC(this);
            phi_s0_2 = true;
        } else if ((params == ENGOROIWA_C000_2) && (this->unk_1E7 <= 0)) {
            ref_func_80941060(this, play);
            this->unk_1E7 = 10;
        }
    }

    if (params == ENGOROIWA_C000_2) {
        if (this->unk_1E7 > 0) {
            this->unk_1E7--;
        }

        if (phi_s0_2) {
            Item_DropCollectibleRandom(play, NULL, &this->actor.world.pos, 0x20);
        }
    }
    return phi_s0_2;
}
