// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0220.h"

extern f32 D_80964C34;

void EffectSsFireTail_Update(PlayState *play, u32 index, void *this) {
    M2C_FIELD(this, s16 *, 0x40) = (s16) (s32) ((f32) M2C_FIELD(this, s16 *, 0x40) * D_80964C34);
}
