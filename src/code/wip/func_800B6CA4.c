// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 7/42 instructions differ
#include "types.h"
#include "m2c_compat.h"

s32 Camera_GetInputDirYaw(s32, u8 *);                     /* extern */
f32 Math_CosS(s16);                             /* extern */
f32 Math_SinS(s16);                             /* extern */

void func_800B6CA4(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3) {
    s16 sp26;
    s16 temp_v1;

    temp_v1 = arg3 - Camera_GetInputDirYaw(M2C_FIELD((arg0 + (M2C_FIELD(arg0, s16 *, 0x810) * 4)), s32 *, 0x800), arg0);
    sp26 = temp_v1;
    M2C_FIELD(arg1, s8 *, 2) = (s8) (s32) (-Math_SinS(temp_v1) * arg2);
    M2C_FIELD(arg1, s8 *, 0x14) = (s8) M2C_FIELD(arg1, s8 *, 2);
    M2C_FIELD(arg1, s8 *, 3) = (s8) (s32) (Math_CosS(sp26) * arg2);
    M2C_FIELD(arg1, s8 *, 0x15) = (s8) M2C_FIELD(arg1, s8 *, 3);
}
