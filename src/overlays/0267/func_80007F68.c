#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0267.h"

M2C_UNK func_80137828(s32, M2C_UNK *, f32, u8 *); /* extern */
extern M2C_UNK D_6003008;
extern u8 *D_801EB7E0;
extern M2C_UNK D_8099EE0C;

void func_80007F68(u8 *arg0, M2C_UNK arg1) {
    func_80137828(arg0 + 0x194, &D_6003008, 0, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_8099EE0C;
    M2C_FIELD(arg0, s8 *, 0x148) = 0;
    M2C_FIELD(arg0, f32 *, 0x1AC) = 19.0f;
    M2C_FIELD(arg0, s16 *, 0x14C) = (s16) (M2C_FIELD(D_801EB7E0, s16 *, 0xA6E) + 0xC8);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
}
