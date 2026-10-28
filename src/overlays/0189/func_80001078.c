// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
s16 func_800F1F68(s8);                              /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80152978(s32, M2C_UNK);                /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_80955480;

void func_80001078(u8 *arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_80152978(arg1, 0x35);
        M2C_FIELD(arg0, s32 *, 0x1A8) = 0;
        if (func_800F1E2C() == 0x7C) {
            func_800F1D6C(0x7C);
            func_800F1944(M2C_FIELD(arg0, s16 *, 0x1AE));
            M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80955480;
            return;
        }
        if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x1AE)) == 0) {
            func_800F1944(M2C_FIELD(arg0, s16 *, 0x1AE));
            M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80955480;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x1A8) = 1;
        func_800F1A08(M2C_FIELD(arg0, s16 *, 0x1AE), arg0);
        M2C_FIELD(arg0, s16 *, 0x208) = func_800F1F68(M2C_FIELD(arg0, s8 *, 0x38));
        func_800FF30C(arg0 + 0x22C, arg0 + 8);
        M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80955480;
    }
}
