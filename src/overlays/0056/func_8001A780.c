#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_80832628(u8 *, f32 *, s16 *, f32, s32); /* extern */
M2C_UNK func_80846B80(u8 *, u8 *, f32, s16);    /* extern */

void func_8001A780(s32 arg0, u8 *arg1, f32 arg2) {
    f32 sp2C;
    s16 sp2A;

    func_80832628(arg1, &sp2C, &sp2A, 0, arg0);
    func_80846B80(arg1, arg1 + 0xAD0, sp2C * 0.5f, sp2A);
    func_80846B80(arg1, arg1 + 0x68, arg2, M2C_FIELD(arg1, s16 *, 0xAD4));
}
