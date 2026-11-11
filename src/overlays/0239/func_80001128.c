#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6005700;
extern M2C_UNK D_809761DC;

void func_80001128(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) | 1);
    func_80137934(arg0 + 0x144, &D_6005700, 0xC0800000, arg0);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_809761DC;
    M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
}
