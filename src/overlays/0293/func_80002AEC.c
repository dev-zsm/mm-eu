#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0293.h"

f32 func_8008704C();                                /* extern */
extern M2C_UNK D_809F3FF8;

void func_80002AEC(u8 *arg0) {
    f32 temp_f6;
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2E4) - 1;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2E4) = temp_v0;
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x2E2) + 1;
    if (temp_v0_2 >= 3) {
        M2C_FIELD(arg0, s16 *, 0x2E2) = 0;
        temp_f6 = func_8008704C() * 60.0f;
        M2C_FIELD(arg0, s16 *, 0x2E4) = (s16) ((s32) temp_f6 + 0x14);
        M2C_FIELD(arg0, M2C_UNK **, 0x2E8) = &D_809F3FF8;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x2E2) = temp_v0_2;
    M2C_FIELD(arg0, s16 *, 0x2E4) = 1;
}
