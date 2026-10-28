// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E26E8(s32, s32, u8 *, u8 *);    /* extern */

void func_80000184(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x18A) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x3C);
    M2C_FIELD(arg0, s16 *, 0x18C) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x28);
    M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x44);
    func_800E26E8(arg1, arg1 + 0x18884, arg0 + 0x144, arg0);
}
