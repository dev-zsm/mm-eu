#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_808A3164(u8 *);                      /* extern */
M2C_UNK func_808A3224(u8 *);                      /* extern */
extern M2C_UNK D_808A3E08;

void func_80000F38(u8 *arg0, s32 arg1) {
    func_808A3224(arg0);
    func_808A3164(arg0);
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151DF4(arg1, 0xD7E, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_808A3E08;
        return;
    }
    func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
}
