#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E0F5C(s32, s32);                    /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK, M2C_UNK *);  /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80BB518C(u8 *);                      /* extern */
M2C_UNK func_80BB523C(u8 *);                      /* extern */
extern M2C_UNK D_600B644;
extern M2C_UNK D_6012A58;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BB5CE8;
extern M2C_UNK D_80BB5D14;

void func_80000000(u8 *arg0, s32 arg1) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x42100000);
    func_80136ED0(arg1, arg0 + 0x190, &D_6012A58, &D_600B644, arg0 + 0x21C, arg0 + 0x28E, 0x13);
    temp_a1 = arg0 + 0x144;
    sp34 = temp_a1;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_80BB5CE8);
    func_800E731C(arg0 + 0xA0, 0, &D_80BB5D14);
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    M2C_FIELD(arg0, s16 *, 0x30C) = 0;
    M2C_FIELD(arg0, s16 *, 0x30E) = 0;
    M2C_FIELD(arg0, s16 *, 0x314) = 0;
    M2C_FIELD(arg0, s16 *, 0x310) = 0;
    M2C_FIELD(arg0, s16 *, 0x312) = 0;
    if ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF43) & 0x20) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF2C) & 0x20)) {
        func_80BB523C(arg0);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    func_80BB518C(arg0);
}
