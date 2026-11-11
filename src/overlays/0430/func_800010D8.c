#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0430.h"

s32 func_800B8254(u8 *, s32);                             /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
extern M2C_UNK D_80AC5A40;

void func_800010D8(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC5A40;
        M2C_FIELD(arg0, u16 *, 0x220) = (u16) (M2C_FIELD(arg0, u16 *, 0x220) | 4);
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x114) != 0) {
        func_800B8398(arg0, arg1, 0x447A0000);
    }
}
