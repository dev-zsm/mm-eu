// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A80(s16, u8 *);                 /* extern */
s16 func_800F1E68(s8);                              /* extern */
s16 func_800F1F68(s16);                             /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A2A324(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80A2B6F0;

void func_8000156C(u8 *arg0, M2C_UNK arg1) {
    s16 sp2E;
    s16 temp_v0;

    temp_v0 = func_800F1E68(M2C_FIELD(arg0, s8 *, 0x38));
    sp2E = temp_v0;
    if (func_800F1984(temp_v0) == 0) {
        func_800F1944(sp2E);
        return;
    }
    func_800F1A80(sp2E, arg0);
    M2C_FIELD(arg0, s16 *, 0x74E) = func_800F1F68(sp2E);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x100000);
    func_80A2A324(arg0, 2, 0);
    M2C_FIELD(arg0, s16 *, 0x3B0) = 2;
    M2C_FIELD(arg0, s32 *, 0x744) = 1;
    M2C_FIELD(arg0, s16 *, 0x3BC) = 0;
    func_800FFCBC(arg0 + 0x3C2, 0xFF, 1, 5, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x3AC) = &D_80A2B6F0;
}
