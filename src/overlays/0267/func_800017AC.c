// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_600BCF4;
extern M2C_UNK D_600C384;
extern M2C_UNK D_80998698;

void func_800017AC(u8 *arg0, M2C_UNK arg1) {
    if (func_8008704C() < 0.5f) {
        func_80137828(arg0 + 0x194, &D_600C384, 0xC0000000);
        M2C_FIELD(arg0, f32 *, 0x1D8) = (f32) func_80134AE8(&D_600C384);
    } else {
        func_80137828(arg0 + 0x194, &D_600BCF4, 0xC0000000);
        M2C_FIELD(arg0, f32 *, 0x1D8) = (f32) func_80134AE8(&D_600BCF4);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80998698;
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x14;
}
