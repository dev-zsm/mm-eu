// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0388.h"

f32 func_800FEB84(s16);                             /* extern */

void func_800006AC(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s16 *, 0x228) = (s16) (M2C_FIELD(thisx, s16 *, 0x228) + 0xBB8);
    M2C_FIELD(thisx, s16 *, 0x22A) = (s16) (M2C_FIELD(thisx, s16 *, 0x22A) + 0x1388);
    M2C_FIELD(thisx, f32 *, 0x204) = (f32) (func_800FEB84(M2C_FIELD(thisx, s16 *, 0x228)) * 150.0f);
    M2C_FIELD(thisx, f32 *, 0x208) = (f32) (func_800FEB84(M2C_FIELD(thisx, s16 *, 0x22A)) * 150.0f);
    M2C_FIELD(thisx, f32 *, 0x20C) = (f32) (func_800FEB84(M2C_FIELD(thisx, s16 *, 0x228)) * 150.0f);
}
