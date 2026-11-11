#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80BCE4AC(u8 *);                      /* extern */
extern M2C_UNK D_6003BFC;
extern M2C_UNK D_600D640;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BCE7F0;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41C80000);
    func_80136ED0(arg1, arg0 + 0x144, &D_600D640, &D_6003BFC, arg0 + 0x188, arg0 + 0x1EE, 0x11);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
    func_800E1134(arg1, arg0 + 0x274, arg0, &D_80BCE7F0);
    func_80BCE4AC(arg0);
}
