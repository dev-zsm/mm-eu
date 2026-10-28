// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A80(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80115540(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_80AC9368;
extern M2C_UNK D_80AC9558;
extern M2C_UNK D_80AC974C;

void func_800022DC(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x368) == 0) {
        if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x36A)) != 0) {
            func_800F1A80(M2C_FIELD(arg0, s16 *, 0x36A), arg0);
            M2C_FIELD(arg0, s16 *, 0x368) = 2;
            if (M2C_FIELD(arg0, u8 *, 0x378) == 0) {
                M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC9368;
                return;
            }
            if (M2C_FIELD(arg0, u16 *, 0x116) != 0x29D6) {
                M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC9558;
                return;
            }
            func_80115540(arg1, 6);
            M2C_FIELD(arg0, s32 *, 0x400) = 0;
            M2C_FIELD(arg0, s32 *, 0x438) = 1;
            M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC974C;
            return;
        }
        if (func_800F1E2C() == 0x7C) {
            func_800F1D6C(0x7C);
        }
        if (M2C_FIELD(arg0, u8 *, 0x378) == 0) {
            M2C_FIELD(arg0, s16 *, 0x36A) = (s16) M2C_FIELD(arg0, s16 *, 0x372);
        } else {
            M2C_FIELD(arg0, s16 *, 0x36A) = (s16) M2C_FIELD(arg0, s16 *, 0x36C);
        }
        func_800F1944(M2C_FIELD(arg0, s16 *, 0x36A));
    }
}
