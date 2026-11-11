#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6004A90;
extern M2C_UNK D_809774C4;

void func_800023C0(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) & 0xFFFE);
    func_80137788(arg0 + 0x144, &D_6004A90, 0xBF800000, (f32) func_80134AE8(&D_6004A90), 0.0f, 2, -3.0f);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 6.5f;
    M2C_FIELD(arg0, f32 *, 0x68) = 15.0f;
    func_800B8C4C(arg0, 0x386C);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_809774C4;
}
