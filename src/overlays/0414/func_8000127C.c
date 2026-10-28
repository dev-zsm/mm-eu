// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_80AB11A0(u8 *);                      /* extern */
M2C_UNK func_80AB18E8(u8 *, s32);                 /* extern */
extern M2C_UNK D_80AB2014;
extern M2C_UNK D_80AB25F0;

void func_8000127C(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x1D5) & 2) {
        func_80AB11A0(arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x22C) = &D_80AB2014;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AB25F0;
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + 40.0f);
        M2C_FIELD(arg0, f32 *, 0xC) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + 40.0f);
        func_800B8C4C(arg0, 0x288E);
    } else {
        func_800E2500(arg1, arg1 + 0x18884, arg0 + 0x1C4);
    }
    func_80AB18E8(arg0, arg1);
}
