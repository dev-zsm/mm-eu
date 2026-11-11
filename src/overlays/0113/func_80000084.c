#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                      /* extern */
s32 func_808D6FF8();                                /* extern */
extern M2C_UNK D_808D76CC;

void func_80000084(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    M2C_FIELD(arg0, s16 *, 0x148) = (s16) ((temp_v0 >> 0xC) & 0xF);
    M2C_FIELD(arg0, s16 *, 0x14A) = (s16) ((temp_v0 >> 8) & 7);
    M2C_FIELD(arg0, s16 *, 0x14C) = (s16) ((temp_v0 >> 5) & 3);
    M2C_FIELD(arg0, s16 *, 0x14E) = (s16) (temp_v0 & 0x1F);
    if (M2C_FIELD(arg0, s16 *, 0x14A) >= 4) {
        func_800B6490();
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x14E) >= 5) {
        func_800B6490();
        return;
    }
    if (func_808D6FF8() == 0) {
        func_800B6490();
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808D76CC;
}
