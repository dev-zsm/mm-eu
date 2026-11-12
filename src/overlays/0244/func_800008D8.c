#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0244.h"

s32 func_800B877C(u8 *, s32);                             /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
extern M2C_UNK D_80981860;

void func_800008D8(u8 *arg0, s32 arg1) {
    if (func_800B877C(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 0x120) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x274) = &D_80981860;
        return;
    }
    func_800B87A0(arg0, arg1, 0x92, 0x461C4000, 100.0f);
}
