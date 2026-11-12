#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0267.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6009538;
extern u8 *D_801EB7E0;
extern M2C_UNK D_8099BC80;

void func_80004DD8(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f6;

    func_80137828(arg0 + 0x194, &D_6009538, 0xC0A00000, arg0);
    temp_f6 = (f32) func_80134AE8(&D_6009538);
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_8099BC80;
    M2C_FIELD(arg0, s8 *, 0x148) = 0;
    M2C_FIELD(arg0, f32 *, 0x1D8) = temp_f6;
    M2C_FIELD(arg0, s16 *, 0x14A) = (s16) (M2C_FIELD(D_801EB7E0, s16 *, 0xA46) + 0x96);
    M2C_FIELD(arg0, s16 *, 0x160) = 0;
}
