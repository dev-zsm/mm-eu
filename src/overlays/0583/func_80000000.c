#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, s32, s32); /* extern */
s32 func_800B5B20();                        /* extern */
M2C_UNK func_800B6490();                 /* extern */
M2C_UNK func_800B6564();             /* extern */
M2C_UNK func_800E1134(); /* extern */
M2C_UNK func_80136E1C(); /* extern */
s32 func_8013D9F8();               /* extern */
M2C_UNK func_801A5F50();                     /* extern */
M2C_UNK func_80BC0008();                      /* extern */
extern M2C_UNK D_60023B8;
extern M2C_UNK D_60024CC;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BC0E70;

void func_80000000(u8 *arg0, s32 arg1) {
    s16 temp_a1;
    s16 temp_v1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136E1C(arg1, arg0 + 0x144, &D_60023B8, &D_60024CC, arg0 + 0x188, arg0 + 0x1C4, 0xA);
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x1F) = 0;
    func_800E1134(arg1, arg0 + 0x234, arg0, &D_80BC0E70);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x1C);
    M2C_FIELD(arg0, s16 *, 0x21E) = (s16) ((temp_v1 >> 7) & 0x1F);
    M2C_FIELD(arg0, s16 *, 0x21C) = (s16) (temp_v1 & 0x7F);
    if (M2C_FIELD(arg0, s16 *, 0x21C) == 0x7F) {
        M2C_FIELD(arg0, s16 *, 0x21C) = -1;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x21C) >= 0) && (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x21C)) != 0)) {
        func_800B6490(arg0);
        return;
    }
    temp_a1 = M2C_FIELD(arg0, s16 *, 0x21E);
    if (temp_a1 == 0x1F) {
        func_800B6490(arg0, temp_a1);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x204) = func_8013D9F8(arg1, temp_a1, 0x3F);
    M2C_FIELD(arg0, s16 *, 0x226) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
    func_801A5F50(2);
    func_80BC0008(arg0);
}
