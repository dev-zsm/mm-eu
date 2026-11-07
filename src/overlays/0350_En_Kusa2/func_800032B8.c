// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5E418(EnKusa2* this) {
    this->actor.terminalVelocity = -4.0f;
    this->actor.velocity.x *= 0.1f;
    this->actor.velocity.y *= 0.25f;
    this->actor.velocity.z *= 0.1f;
    this->actor.draw = ref_func_80A5EA48;
    this->actor.speed *= 0.1f;
    this->actor.gravity *= 0.25f;
    this->unk_1CC = Rand_S16Offset(-800, 1600);
    this->actionFunc = ref_func_80A5E4BC;
}
