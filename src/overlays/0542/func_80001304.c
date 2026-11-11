#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                          /* extern */
M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80B8D60C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B8E68C;

void func_80001304(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80B8D60C(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80B8E68C;
        return;
    }
    func_800B8364(arg0, arg1, 0x43C80000, -1);
}
