#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0232.h"

s32 func_800B8254();                                /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_8096EA78(u8 *, s32);                 /* extern */
extern M2C_UNK D_80970994;

void func_80002AAC(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        func_8096EA78(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80970994;
        return;
    }
    func_800B8398(arg0, arg1, 0x42C80000);
}
