#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0074.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, f32, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_60009C4;
extern M2C_UNK D_80896DFC;
extern M2C_UNK D_80897B74;

void func_80000718(u8 *arg0) {
    if (&D_80897B74 != M2C_FIELD(arg0, M2C_UNK **, 0x2A8)) {
        func_80137788(arg0 + 0x144, &D_60009C4, 0.0f, 0x40400000, (f32) func_80134AE8(&D_60009C4), 2, 0.0f);
    }
    M2C_FIELD(arg0, s16 *, 0x2B0) = 0x10;
    func_800B8C4C(arg0, 0x3954);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80896DFC;
}
