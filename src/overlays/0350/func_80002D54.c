// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5DEB4(EnKusa2* this, PlayState* play) {
    s32 pad;
    s32 pad2;
    s16 sp24;
    s32 sp20;

    if (!ref_func_80A5BFD8(this, play)) {
        if (this->unk_1D0 > 0) {
            this->unk_1D0--;
            if (this->unk_1D0 == 0) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_KUSAMUSHI_VIBE);
            }
        }

        if (this->unk_1D1 > 0) {
            this->unk_1D1--;
            if (this->unk_1D1 == 0) {
                Actor_PlaySfx(&this->actor, NA_SE_EN_KUSAMUSHI_VIBE);
            }
        }

        Math_StepToF(&this->actor.scale.y, 0.4f, 0.032f);
        Math_StepToF(&this->actor.scale.x, 0.4f, 0.032f);
        this->unk_1C4 += 0x4650;
        this->actor.scale.z = this->actor.scale.x;
        this->actor.speed = fabsf(Math_CosS(this->unk_1C4) + 0.5f) * 1.5f;

        if (this->actor.speed < 0.0f) {
            this->actor.speed = 0.0f;
        }

        Actor_MoveWithGravity(&this->actor);

        this->actor.world.rot.y = (s32)(Math_SinS(this->unk_1C4) * 3000.0f) + this->actor.home.rot.y;
        this->actor.shape.rot.y = this->actor.world.rot.y;
        this->actor.shape.rot.x = (s32)(fabsf(Math_SinS(this->unk_1C4)) * 4000.0f) - 0x6A4;

        ref_func_80A5BAFC(this, play);
        ref_func_80A5BF38(this, 4);
        ref_func_80A5BF84(this, play);

        if (Rand_Next() < 0xFFFFFFF) {
            ref_func_80A5CD0C(this);
        }

        if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER) {
            ref_func_80A5BDB0(this, play);
            ref_func_80A5E418(this);
        } else {
            this->unk_1C8--;
            if (this->unk_1C8 <= 0) {
                ref_func_80A5CD0C(this);
                ref_func_80A5BB40(this, play, 4);
                this->actor.speed += 4.0f;
                this->actor.velocity.y = (Rand_ZeroOne() * 4.0f) + 15.0f;
                ref_func_80A5E1D8(this);
            } else if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
                this->unk_1CA--;
                if (this->unk_1CA <= 0) {
                    ref_func_80A5CD0C(this);
                    ref_func_80A5BB40(this, play, 2);
                    this->actor.velocity.y = (Rand_ZeroOne() * 6.0f) + 7.0f;
                    this->actor.speed += 2.0f;
                    if (this->actor.yawTowardsPlayer < this->actor.world.rot.y) {
                        sp20 = 10000;
                    } else {
                        sp20 = -10000;
                    }
                    sp24 = sp20 + Rand_S16Offset(-3000, 6000);
                    this->actor.home.rot.y += sp24;
                    this->actor.world.rot.y = this->actor.home.rot.y;
                    ref_func_80A5DC70(this);
                }
            }
        }
    }
}
