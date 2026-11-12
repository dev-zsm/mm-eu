#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E0F5C(s32, s32);                    /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80BF87CC(u8 *, s32);                 /* extern */
M2C_UNK func_80BF8914(u8 *);                      /* extern */
extern M2C_UNK D_6008AB8;
extern M2C_UNK D_60092FC;
extern M2C_UNK D_800B3F30;
extern s32 D_801E6EF0;
extern M2C_UNK D_80BF9E18;

void func_80000000(u8 *arg0, s32 arg1) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x42100000);
    func_80136ED0(arg1, arg0 + 0x190, &D_6008AB8, &D_60092FC, arg0 + 0x220, arg0 + 0x286, 0x11);
    temp_a1 = arg0 + 0x144;
    sp34 = temp_a1;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_80BF9E18);
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    if (D_801E6EF0 == 0x68D0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
    }
    M2C_FIELD(arg0, s16 *, 0x2F8) = 0;
    M2C_FIELD(arg0, s16 *, 0x2FA) = 0;
    M2C_FIELD(arg0, s32 *, 0x21C) = 0;
    M2C_FIELD(arg0, s16 *, 0x2FE) = 0;
    func_80BF87CC(arg0, arg1);
    func_80BF8914(arg0);
}
