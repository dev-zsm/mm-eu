#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E1134(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK, M2C_UNK *);  /* extern */
M2C_UNK func_80B06D2C(u8 *);                      /* extern */
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80B077B0;
extern M2C_UNK D_80B077DC;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x42500000);
    func_800E1134(arg1, arg0 + 0x14C, arg0, &D_80B077B0);
    func_800E72F0(arg0 + 0xA0, 0, &D_80B077DC);
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        M2C_FIELD(arg0, f32 *, 0x74) = -1.5f;
    } else {
        M2C_FIELD(arg0, u8 *, 0x15E) = (u8) (M2C_FIELD(arg0, u8 *, 0x15E) & 0xFFFB);
        M2C_FIELD(arg0, f32 *, 0x78) = -100.0f;
        M2C_FIELD(arg0, f32 *, 0x74) = -7.0f;
    }
    func_80B06D2C(arg0);
}
