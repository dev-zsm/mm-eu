#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0063.h"

s16 func_800B6A58(u8 *, s32);                     /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6004680;
extern M2C_UNK D_8086B18C;

void func_80001C40(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6004680, 0x40C00000);
    M2C_FIELD(arg0, s16 *, 0x2B6) = 6;
    M2C_FIELD(arg0, u8 *, 0x396) = (u8) (M2C_FIELD(arg0, u8 *, 0x396) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x395) = (u8) (M2C_FIELD(arg0, u8 *, 0x395) & 0xFFFE);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0xBE) = func_800B6A58(arg0, M2C_FIELD(arg0, s32 *, 0x124));
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x1C) = 8;
    func_800B8C4C(arg0, 0x395C);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086B18C;
}
