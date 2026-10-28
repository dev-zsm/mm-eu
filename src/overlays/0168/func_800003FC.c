// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, s32, s32, s32);  /* extern */
M2C_UNK func_80151E7C(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_809372E8;

void func_800003FC(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151E7C(arg1, 0x936);
        M2C_FIELD(arg0, M2C_UNK **, 0x1F4) = &D_809372E8;
        return;
    }
    func_800B8284(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x98), M2C_FIELD(arg0, s32 *, 0x9C), -1);
}
