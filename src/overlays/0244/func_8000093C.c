// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_809818A8;

void func_8000093C(u8 *arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        func_80147CC4(arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x274) = &D_809818A8;
        func_800B87A0(arg0, arg1, 0x92, 0x461C4000, 100.0f);
    }
}
