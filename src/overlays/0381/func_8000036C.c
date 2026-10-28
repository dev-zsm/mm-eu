// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A8FC5C(u8 *, s32);                 /* extern */
extern s8 D_801E6F10;

void func_8000036C(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, s32 *, 0x2F0) = (s32) M2C_FIELD(arg0, s32 *, 0x2F0);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x290)(arg0, arg1);
    if (func_800B877C(arg0, arg1) == 0) {
        func_800B87A0(arg0, arg1, 0x4C, 0x41F00000, 80.0f);
    } else {
        D_801E6F10 = 4;
        func_800B6490(arg0);
    }
    func_80A8FC5C(arg0, arg1);
}
