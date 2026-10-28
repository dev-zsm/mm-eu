// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C604C(s32, s32, s32);               /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_800F0308(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80B804EC(u8 *, s32);                 /* extern */
M2C_UNK func_80B80768(u8 *, s32);                 /* extern */
s32 func_80B80D1C(u8 *);                          /* extern */
extern M2C_UNK D_80B80F14;
extern M2C_UNK D_80B80F40;

void func_8000099C(u8 *arg0, s32 arg1) {
    if (func_80B80D1C(arg0) != 0) {
        if (!(M2C_FIELD(arg0, s16 *, 0x1C) & 0x80)) {
            func_80B804EC(arg0, arg1);
        } else {
            func_80B80768(arg0, arg1);
        }
        func_800F0308(arg1, arg0 + 0x24, 0x14, 0x28AA);
        if (M2C_FIELD(arg0, s16 *, 0x1C) & 0x80) {
            M2C_FIELD(arg0, M2C_UNK **, 0x1A8) = &D_80B80F40;
            return;
        }
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
        func_800C604C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
        M2C_FIELD(arg0, s32 *, 0x13C) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x1A8) = &D_80B80F14;
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) < 600.0f) {
        func_800E2500(arg1, arg1 + 0x18884, arg0 + 0x15C);
    }
}
