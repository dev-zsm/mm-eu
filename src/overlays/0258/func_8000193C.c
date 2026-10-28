// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8098C9D8(u8 *);                      /* extern */
extern f32 D_8098DBB4;
extern f32 D_8098DBB8;

void func_8000193C(u8 *arg0, s32 arg1) {
    f32 sp34;
    s16 temp_v0;

    sp34 = M2C_FIELD(arg0, f32 *, 0x15C);
    func_800FFCBC(arg0 + 0x34, 0, 5, 0x3E8, 5);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2B8);
    if (((temp_v0 == 0xB) || (temp_v0 == 0xA)) && (M2C_FIELD(arg0, s16 *, 0x2B6) < 2)) {
        func_800BF550(arg1, arg0, arg0 + 0x2C4, 0xC, 2, D_8098DBB4, D_8098DBB8);
        M2C_FIELD(arg0, s16 *, 0x2B6) = 0;
        M2C_FIELD(arg0, s16 *, 0x2B8) = 0;
    }
    if (M2C_FIELD(arg0, f32 *, 0x368) <= sp34) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x10);
        func_8098C9D8(arg0);
    }
}
