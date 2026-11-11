#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0240.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_8097A18C;
extern M2C_UNK D_8097C070;

void func_80000C38(u8 *arg0) {
    func_800BD9E0(arg0 + 0x144, &D_8097C070, 6, arg0);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s16 *, 0x3DE) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_8097A18C;
    M2C_FIELD(arg0, f32 *, 0xCC) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
}
