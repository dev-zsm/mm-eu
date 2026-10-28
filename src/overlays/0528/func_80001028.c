// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80B7BA6C(u8 *);                      /* extern */
extern M2C_UNK D_80B7C0DC;

void func_80001028(u8 *arg0, s32 arg1) {
    func_80B7BA6C(arg0);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7C0DC;
        return;
    }
    func_800B8284(arg0, arg1, 0x461C4000, 0x447A0000, 0);
}
