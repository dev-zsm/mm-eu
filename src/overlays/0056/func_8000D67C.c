#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_801367B4(s32, u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_8084A240;
extern s32 D_8085B7CC[];
extern f32 D_8085BAD4;

void func_8000D67C(s32 arg0, u8 *arg1, s16 arg2) {
    M2C_FIELD(arg1, s16 *, 0xAD4) = arg2;
    func_80830B44(arg0, arg1, &D_8084A240, 1);
    M2C_FIELD(arg1, s16 *, 0xB4E) = 0x4B0;
    M2C_FIELD(arg1, s16 *, 0xB4E) = (s16) (s32) ((f32) M2C_FIELD(arg1, s16 *, 0xB4E) * D_8085BAD4);
    func_801367B4(arg0, arg1 + 0x240, D_8085B7CC[M2C_FIELD(arg1, u8 *, 0x14F)], 0x3F800000, 0.0f, 0.0f, 0, -6.0f);
}
