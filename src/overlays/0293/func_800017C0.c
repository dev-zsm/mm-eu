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
M2C_UNK func_809F15DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_809F38F0;

void func_800017C0(u8 *arg0, u8 *arg1) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(arg0, s16 *, 0x39E) == 0) {
        if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x3A0)) != 0) {
            func_800F1A80(M2C_FIELD(arg0, s16 *, 0x3A0), arg0);
            M2C_FIELD(temp_v1, s32 *, 0xA70) = (s32) (M2C_FIELD(temp_v1, s32 *, 0xA70) | 0x20000000);
            func_809F15DC(arg0, &D_809F38F0);
            M2C_FIELD(arg0, s16 *, 0x39E) = 2;
        } else {
            if (func_800F1E2C() == 0x7C) {
                func_800F1D6C(0x7C);
            }
            M2C_FIELD(arg0, s16 *, 0x3A0) = (s16) M2C_FIELD(arg0, s16 *, 0x3A6);
            func_800F1944(M2C_FIELD(arg0, s16 *, 0x3A0));
        }
    }
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151E7C(arg1, 0x647);
        return;
    }
    func_800B8364(arg0, arg1, 0x43C80000, -1);
}
