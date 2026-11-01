// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0286.h"

M2C_UNK func_800B695C(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, M2C_UNK); /* extern */
s32 func_800FFCBC(u8 *, s16, M2C_UNK, s16, s32);  /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_809C7490(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809C817C(u8 *, u8 *);              /* extern */
M2C_UNK func_809C9640(u8 *, u8 *);              /* extern */
extern f32 D_809CDF8C;

void func_80001FFC(u8 *arg0, u8 *arg1) {
    s32 pad;
    u8 *sp28;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    sp28 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(arg0, s16 *, 0x24E) != 0) {
        func_809C7490(arg0 + 0xEC, 0x32AB);
    }
    func_800FFDD8(arg0 + 0x2A0, (s16) (s32) ((f32) func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 0xA, M2C_FIELD(arg0, s16 *, 0x274), 0) * D_809CDF8C), 5, 0x200);
    func_800FFDD8(arg0 + 0x274, 0x800, 1, 0x100);
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 2, 0x1000);
    func_800FFDD8(arg0 + 0x30, 0, 0xA, 0x200);
    func_800FFDD8(arg0 + 0xBC, 0, 0xA, 0x200);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x258) - 70.0f;
    if (temp_f0 < M2C_FIELD(arg0, f32 *, 0x28)) {
        func_800FFBF8(arg0 + 0x28, temp_f0, 0x3D4CCCCD, 0x40A00000);
    }
    func_80137070(arg0 + 0x148);
    temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x258);
    temp_f2 = M2C_FIELD(sp28, f32 *, 0x28);
    if ((temp_f0_2 < temp_f2) && (M2C_FIELD(sp28, u16 *, 0x90) & 1)) {
        if (M2C_FIELD(arg0, s16 *, 0x24C) == 0) {
            func_809C9640(arg0, arg1);
        }
    } else if (temp_f2 <= temp_f0_2) {
        func_809C817C(arg0, arg1);
        M2C_FIELD(arg0, s16 *, 0x24E) = 0x14;
    }
    func_800FFBF8(arg0 + 0x70, -3.0f, 0x3F800000, 0x3F000000);
    func_800B695C(arg0);
}
