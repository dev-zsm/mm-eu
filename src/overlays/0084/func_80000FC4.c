#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0084.h"

M2C_UNK func_800B8284(u8 *, s32, f32, f32, s32); /* extern */
s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_808A3164(u8 *);                      /* extern */
M2C_UNK func_808A3224(u8 *);                      /* extern */
extern M2C_UNK D_808A3CC8;

void func_80000FC4(u8 *arg0, s32 arg1) {
    func_808A3224(arg0);
    func_808A3164(arg0);
    if (func_800B877C(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 0x120) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_808A3CC8;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
        func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, 0);
        return;
    }
    func_800B87A0(arg0, arg1, 0xC, 0x461C4000, 50.0f);
}
