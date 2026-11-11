#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_800BAE44(s32, u8 *, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */

void func_80001A90(u8 *arg0, s32 arg1) {
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 0x38, M2C_FIELD(arg0, f32 *, 0x24) + 80.0f, M2C_FIELD(arg0, f32 *, 0x88), M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, 0x201);
}
