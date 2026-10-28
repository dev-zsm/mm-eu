// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A99B64(u8 *, M2C_UNK);             /* extern */
s32 func_80A9C350(u8 *, s32);                     /* extern */
extern u8 D_801E6F10;
extern M2C_UNK D_80A9C850;
extern M2C_UNK D_80A9CD70;

void func_800033AC(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x148);
    func_80137070(arg0 + 0x2A0);
    if (func_800B8254(arg0, arg1) != 0) {
        if ((D_801E6F10 == 0) || (D_801E6F10 == 4)) {
            func_80A99B64(arg0, 2);
            M2C_FIELD(arg0, s32 *, 0x3E0) = 5;
        } else {
            func_80A99B64(arg0, 8);
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9C850;
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x331) & 2) {
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9CD70;
        M2C_FIELD(arg0, s16 *, 0x116) = 0x8D2;
        func_80A99B64(arg0, 6);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
        return;
    }
    if (func_80A9C350(arg0, arg1) != 0) {
        if ((D_801E6F10 != 0) && (D_801E6F10 != 4)) {
            M2C_FIELD(arg0, s16 *, 0x116) = 0x8D1;
        } else {
            M2C_FIELD(arg0, s16 *, 0x116) = 0x8D0;
        }
        func_800B8398(arg0, arg1, 0x42C80000);
    }
}
