#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0610.h"

s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8284(u8 *, M2C_UNK, f32, f32, s32); /* extern */
M2C_UNK func_80151DF4(M2C_UNK, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80BDF09C(M2C_UNK);                     /* extern */
M2C_UNK func_80BDF3D4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BDF4B0(u8 *);                      /* extern */
extern M2C_UNK D_80BDF774;

void func_80000768(u8 *arg0, M2C_UNK arg1) {
    func_80BDF3D4(arg0, arg1);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80BDF774;
        func_80151DF4(arg1, 0x147D, arg0);
        func_80BDF09C(arg1);
    } else {
        func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
    }
    func_80BDF4B0(arg0);
}
