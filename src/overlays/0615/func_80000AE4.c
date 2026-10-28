// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800BA9E4(s32, s32, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_80BE5EDC(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80BE6080(u8 *);                      /* extern */
extern M2C_UNK D_80BE67C4;

void func_80000AE4(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    func_80BE6080(arg0);
    temp_v0 = func_800BA9E4(arg1 + 0x1CA0, arg1, 0x11, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28) + 30.0f, M2C_FIELD(arg0, f32 *, 0x2C), 0, (s32) M2C_FIELD(arg0, s16 *, 0x32), 0, 2);
    M2C_FIELD(arg0, s32 *, 0x2E4) = temp_v0;
    if (temp_v0 != 0) {
        func_80BE5EDC(arg0, 0xB, 0x3F800000);
    }
    M2C_FIELD(arg0, s16 *, 0x2CA) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE67C4;
}
