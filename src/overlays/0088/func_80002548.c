#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B8364(u8 *, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A80(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80151E7C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808A77C0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_808A9B24;

void func_80002548(u8 *arg0, u8 *arg1) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(arg0, s16 *, 0x2C2) == 0) {
        if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x2C0)) != 0) {
            func_800F1A80(M2C_FIELD(arg0, s16 *, 0x2C0), arg0);
            M2C_FIELD(temp_v1, s32 *, 0xA70) = (s32) (M2C_FIELD(temp_v1, s32 *, 0xA70) | 0x20000000);
            func_808A77C0(arg0, &D_808A9B24);
            M2C_FIELD(arg0, s16 *, 0x2C2) = 2;
        } else {
            if (func_800F1E2C() == 0x7C) {
                func_800F1D6C(0x7C);
            }
            M2C_FIELD(arg0, s16 *, 0x2C0) = (s16) M2C_FIELD(arg0, s16 *, 0x2B8);
            func_800F1944(M2C_FIELD(arg0, s16 *, 0x2C0));
        }
    }
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151E7C(arg1, 0x642);
        return;
    }
    func_800B8364(arg0, arg1, 0x43C80000, -1);
}
