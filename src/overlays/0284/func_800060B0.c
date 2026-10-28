// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, M2C_UNK, u8 *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFC68(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FFDD8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern f32 D_809BCE58;
extern f32 D_809BCE5C;
extern s16 D_809BD740;

void func_800060B0(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_800B8C4C(arg0, 0x321F);
        func_800FFC68(arg0 + 0x70, 0x3F800000, 0x40000000);
        func_800FFC68(arg0 + 0x5C, 0x3F800000, 0x3A449BA6);
        func_800FFBF8(arg0 + 0xAC4, 0x3F800000, 0x3F000000, 0x3E19999A);
        if (M2C_FIELD(arg0, f32 *, 0x5C) < D_809BCE58) {
            func_800FFC68(arg0 + 0xAC8, 0x3F800000, 0x3D4CCCCD);
            if (M2C_FIELD(arg0, f32 *, 0xAC8) < D_809BCE5C) {
                func_800B6490(arg0);
                func_800A8248(arg1, 0, arg0 + 0x24, 0x60);
                D_809BD740 -= 1;
            }
        }
        func_800FFDD8(arg0 + 0xBC, 0, 1, 0x800);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (M2C_FIELD(arg0, s16 *, 0xBC) - 0x2000);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (M2C_FIELD(arg0, s16 *, 0xC0) + 0x1000);
}
