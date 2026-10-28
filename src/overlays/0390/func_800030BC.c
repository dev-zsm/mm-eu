// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80A9C350(u8 *, s32);                     /* extern */
extern M2C_UNK D_80A9C7F8;

void func_800030BC(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x148);
    func_80137070(arg0 + 0x2A0);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9C7F8;
        M2C_FIELD(arg0, s32 *, 0x3E0) = 0;
        return;
    }
    if (func_80A9C350(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s16 *, 0x116) = 0x8E2;
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}
