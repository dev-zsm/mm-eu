#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0660.h"

s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_80137788(u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
extern u32 D_80C08FC4[];

void func_800000D0(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    M2C_FIELD(arg0, s32 *, 0x27C) = arg1;
    temp_f0 = (f32) func_80134AE8(D_80C08FC4[arg1]);
    M2C_FIELD(arg0, f32 *, 0x28C) = temp_f0;
    func_80137788(arg0 + 0x144, D_80C08FC4[M2C_FIELD(arg0, s32 *, 0x27C)], 0x3F800000, 0.0, temp_f0, 0, 0.0f);
}
