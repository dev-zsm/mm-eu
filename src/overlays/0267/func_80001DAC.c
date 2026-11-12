#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0267.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_60040E0;
extern M2C_UNK D_80998C4C;

void func_80001DAC(u8 *arg0, M2C_UNK arg1) {
    func_80137934(arg0 + 0x194, &D_60040E0, 0xC0A00000);
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80998C4C;
    M2C_FIELD(arg0, s16 *, 0x14A) = (s16) (s32) (func_8017A844(5.0e+01f) + 20.0f);
}
