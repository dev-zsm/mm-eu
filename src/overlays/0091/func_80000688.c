#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0091.h"

M2C_UNK func_8013796C(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000238;
extern M2C_UNK D_808AFAA0;

void func_80000688(u8 *arg0) {
    func_8013796C(arg0 + 0x144, &D_6000238, 0x40800000, arg0);
    M2C_FIELD(arg0, s16 *, 0x236) = 3;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x230) = &D_808AFAA0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x240) = 6.0f;
}
