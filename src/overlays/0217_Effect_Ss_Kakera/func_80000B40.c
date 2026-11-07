// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

void ref_func_8097E7E0(EffectSs* this, PlayState* play) {
    static f32 ref_D_8097EB64[] = { 10.0f, 20.0f, 40.0f };
    Player* player = GET_PLAYER(play);

    if (this->rReg8 == 0) {
        if ((((this->rReg4 >> 4) & 1) << 4) == (1 << 4)) {
            if (this->pos.y <= (player->actor.floorHeight - ((this->rReg4 >> 2) & 3))) {
                this->rReg9 = 0;
                this->rReg0 = 0;
                this->rReg4 &= ~0x60;
                this->accel.x = this->accel.y = this->accel.z = 0.0f;
                this->velocity.x = this->velocity.y = this->velocity.z = 0.0f;
                this->rReg5 = this->rReg9;
                this->rGravity = this->rReg9;
            }
        } else {
            if (this->pos.y <= ((player->actor.floorHeight - ((this->rReg4 >> 2) & 3)) - 600.0f)) {
                this->life = 0;
            }
        }
    } else {
        switch (this->rReg4 & 3) {
            case 0:
                this->rReg8 = 0;
                break;

            case 1:
                if ((this->velocity.y < 0.0f) &&
                    (BgCheck_SphVsFirstPoly(&play->colCtx, &this->pos, ref_D_8097EB64[(this->rReg4 >> 2) & 3]))) {
                    this->velocity.x *= ref_func_8097DE30(0.9f, 0.2f);
                    this->velocity.y *= -0.8f;
                    this->velocity.z *= ref_func_8097DE30(0.9f, 0.2f);
                    if (this->rReg8 > 0) {
                        this->rReg8--;
                    }
                }
                break;

            case 2:
                if (BgCheck_SphVsFirstPoly(&play->colCtx, &this->pos, ref_D_8097EB64[(this->rReg4 >> 2) & 3])) {
                    this->rReg8 = 0;
                }
                break;
        }
    }
}
