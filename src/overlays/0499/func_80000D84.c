#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B4C94C;

void func_80000D84(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x190);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2A0) = &D_80B4C94C;
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF1A) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF1A) | 0x40);
        func_80151DF4(arg1, 0x918, arg0);
        return;
    }
    func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
}
