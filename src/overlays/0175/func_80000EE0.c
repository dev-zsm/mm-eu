#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0175.h"

s32 func_8012FA08(s32, s8, u8 *, s32);            /* extern */
M2C_UNK func_8094313C(u8 *);                      /* extern */
extern M2C_UNK D_8094410C;
extern M2C_UNK D_80944144;

void func_80000EE0(u8 *arg0, s32 arg1) {
    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, s8 *, 0x196), arg0, arg1) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s8 *, 0x196);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x10);
        if (!(((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 3) & 1)) {
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_8094410C;
        } else {
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80944144;
        }
        func_8094313C(arg0);
    }
}
