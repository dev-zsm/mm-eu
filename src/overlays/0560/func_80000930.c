#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0560.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
extern M2C_UNK D_80BABE08;

void func_80000930(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_80BABE08;
        return;
    }
    func_800B8284(arg0, arg1, 4.0e+02f, 4.0e+02f, -1);
}
