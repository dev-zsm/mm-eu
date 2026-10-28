// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A3F5C(M2C_UNK);                     /* extern */
M2C_UNK func_8082D210(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_8082DFD0(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80830E10(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400D228;
extern M2C_UNK D_8084A378;

void func_8000BF10(s32 arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u16 *, 0x90) & 1) {
        M2C_FIELD(arg1, s8 *, 0x14A) = 0x14;
        func_80830E10(arg0, arg1, &D_8084A378, 0);
        func_8082D210(arg0, arg1, &D_400D228);
        func_8082DFD0(arg0, arg1, 0x204);
        M2C_FIELD(arg1, s32 *, 0xA74) = (s32) (M2C_FIELD(arg1, s32 *, 0xA74) | 0x20000000);
        M2C_FIELD(arg1, f32 *, 0xB48) = (f32) M2C_FIELD(arg1, f32 *, 0xAD0);
        func_801A3F5C(0x53);
    }
}
