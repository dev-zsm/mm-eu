// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_stk.h"

void ref_func_80BF0DE0(EffStk* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_512)) {
        switch (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_512)]->id) {
            case 2:
                this->actor.draw = EffStk_Draw;
                if (this->unk146 < 0x3C00) {
                    this->unk146 += 0x400;
                    this->unk148 = Math_SinS(this->unk146) * -630.0f;
                }
                this->unk144++;
                break;

            case 3:
                this->actor.draw = EffStk_Draw;
                if (this->unk146 < 0x3C00) {
                    this->unk146 += 0x400;
                    this->unk148 = Math_SinS(this->unk146) * -630.0f;
                }
                this->unk144--;
                break;

            default:
                this->actor.draw = NULL;
                this->unk146 = 0;
                this->unk148 = 0.0f;
                break;
        }
    }
}
