#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0553.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80B9FC24(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BA0314;

void func_8000101C(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        func_80B9FC24(arg0, 5, 0);
        func_80151DF4(arg1, 0x124D, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x2C0) = &D_80BA0314;
        return;
    }
    func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
}
