#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0390.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */
s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_6008814;
extern M2C_UNK D_80A9B034;

void func_800016BC(u8 *arg0, s32 arg1) {
    u8 *temp_a0;

    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) | 4);
    }
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 2, 0xBB8, 0xC8);
    temp_a0 = arg0 + 0x148;
    if (func_80137070(temp_a0) != 0) {
        func_801378E0(temp_a0, &D_6008814);
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9B034;
    }
    if (M2C_FIELD(arg0, f32 *, 0x68) < 0.0f) {
        M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) & 0xFFFD);
    }
    if (func_80137C58(temp_a0, 0x40A00000) != 0) {
        func_800B8C4C(arg0, 0x2901);
    }
}
