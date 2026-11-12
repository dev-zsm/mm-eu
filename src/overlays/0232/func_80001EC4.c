#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8096DE80(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_8096E6B4(u8 *);                      /* extern */
M2C_UNK func_8096E708(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8096EDA4(u8 *, u8 *);              /* extern */
extern M2C_UNK D_8096F888;
extern M2C_UNK D_8097109C;

void func_80001EC4(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;
    u8 *sp24;
    f32 temp_f0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 60.0f) && (M2C_FIELD(arg0, u8 *, 0x1A2) & 2)) {
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x71C);
    } else {
        sp24 = temp_v0;
        func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 4, 0xC00);
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x98);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    if (temp_f0 < 40.0f) {
        func_8096DE80(arg0 + 0x14C, &D_8097109C, 5);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096F888;
    } else if (M2C_FIELD(temp_v0, s32 *, 0xA74) & 0x20000000) {
        if ((temp_f0 > 40.0f) && (M2C_FIELD(temp_v0, f32 *, 0xAD0) == 0.0f)) {
            func_800FFBF8(arg0 + 0x70, 0x3FC00000, 0x3E4CCCCD, 0x3F800000);
        } else {
            func_800FFBF8(arg0 + 0x70, M2C_FIELD(temp_v0, s32 *, 0x70), 0x3E4CCCCD, 0x3F800000);
        }
    } else {
        func_800FFBF8(arg0 + 0x70, 0x40600000, 0x3E4CCCCD, 0x3F800000);
    }
    func_8096EDA4(arg0, arg1);
    func_800B680C(arg0);
    func_8096E6B4(arg0);
    if (!(M2C_FIELD(arg0, u16 *, 0x280) & 0x20)) {
        func_8096E708(arg0, 0x40400000);
    }
}
