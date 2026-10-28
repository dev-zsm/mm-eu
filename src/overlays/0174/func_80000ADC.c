// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A3F5C(M2C_UNK);                     /* extern */
M2C_UNK func_8093F410(u8 *, s32);                 /* extern */
s32 func_8093F468(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
extern M2C_UNK D_8093FA1C;

void func_80000ADC(u8 *arg0, s32 arg1) {
    func_8093F410(arg0, arg1);
    if (func_8093F468(arg0, arg1, 0xBF6, 0x43480000, 100.0f) != 0) {
        func_801A3F5C(0x45);
        M2C_FIELD(arg0, M2C_UNK **, 0x410) = &D_8093FA1C;
        M2C_FIELD(arg0, s16 *, 0x406) = 0;
        M2C_FIELD(arg0, u16 *, 0x3E8) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E8) | 0x40);
    }
}
