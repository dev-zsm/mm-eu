// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
M2C_UNK func_80151E7C(u8 *, M2C_UNK);             /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80A99DE0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A9A9A4(u8 *, u8 *);              /* extern */
extern M2C_UNK D_80A9AE2C;

void func_800014D8(u8 *arg0, u8 *arg1) {
    u16 temp_v0;

    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 2, 0xBB8, 0xC8);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        temp_v0 = M2C_FIELD(arg1, u16 *, 0x16810);
        switch (temp_v0) {                          /* irregular */
        case 0x7D9:
            func_80151E7C(arg1, 0x7DA);
            func_80A99DE0(arg0, 3);
            break;
        case 0x7DA:
            func_80151E7C(arg1, 0x7DB);
            func_80A99DE0(arg0, 2);
            break;
        case 0x7DB:
            func_80147CC4(arg1);
            func_80A9A9A4(arg0, arg1);
            M2C_FIELD(arg0, s32 *, 0x3C0) = 0;
            M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9AE2C;
            M2C_FIELD(arg0, f32 *, 0x68) = -20.0f;
            M2C_FIELD(arg0, f32 *, 0x78) = -20.0f;
            break;
        }
    }
    func_80137070(arg0 + 0x148);
}
