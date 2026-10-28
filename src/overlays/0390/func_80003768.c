// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80A9D5A8;

void func_80003768(u8 *arg0, s32 arg1) {
    u16 temp_v0;

    func_80137070(arg0 + 0x148);
    func_80137070(arg0 + 0x2A0);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x3E4);
        if (temp_v0 & 0x800) {
            M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (temp_v0 & 0xF7FF);
            func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
        }
        func_80147CC4(arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9D5A8;
        func_800B701C(arg1, 0, 6);
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF4B) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4B) & 0xF7);
    }
}
