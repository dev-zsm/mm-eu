#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
s32 func_809B4080(s32);                             /* extern */
s32 func_809B40C4(s32);                             /* extern */
s32 func_809B43AC(u8 *, u8 *);                  /* extern */
M2C_UNK func_809B461C(u8 *, u8 *);              /* extern */
M2C_UNK func_809B4680(u8 *, u8 *);              /* extern */
s32 func_809B48F4(u8 *);                          /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_809B4AC8;

void func_800008E8(u8 *arg0, u8 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    s32 temp_s0_t;
    temp_s0_t = M2C_FIELD(arg1, s32 *, 0x1CCC);
    temp_s0 = temp_s0_t + 0x24;
    if (func_809B4080(temp_s0) != 0) {
        M2C_FIELD(&D_801E6EF0, s8 *, 0x3DD4) = 6;
        func_8019FF78(0x4835);
        func_801A9868(0x803F);
        M2C_FIELD(arg0, s16 *, 0x15A) = 0x37;
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) | 2);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809B4AC8;
        return;
    }
    if (func_809B48F4(arg0) != 0) {
        M2C_FIELD(&D_801E6EF0, s8 *, 0x3DD4) = 6;
        func_8019FF78(0x4835);
        func_801A9868(0x803F);
        M2C_FIELD(arg0, s16 *, 0x15A) = 0x37;
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) | 4);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809B4AC8;
        return;
    }
    temp_v0 = func_809B40C4(temp_s0);
    if (temp_v0 != 0) {
        if (temp_v0 == 1) {
            M2C_FIELD(arg0, s32 *, 0x164) = 1;
        } else {
            M2C_FIELD(arg0, s32 *, 0x164) = 0;
        }
        func_809B461C(arg0, arg1);
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) | 8);
        return;
    }
    if ((func_809B43AC(arg0, arg1) != 0) && (M2C_FIELD(arg0, s16 *, 0x15A) == 0)) {
        func_809B4680(arg0, arg1);
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100D) | 8);
    }
}
