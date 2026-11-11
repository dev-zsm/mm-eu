#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0465.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_600119C;
extern M2C_UNK D_80B004EC;

void func_8000135C(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_600119C, 0x3FC00000, 0.0f, (f32) func_80134AE8(&D_600119C), 2, -3.0f);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x194) = 0x64;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, u8 *, 0x191) = (u8) (M2C_FIELD(arg0, u8 *, 0x191) & 0xFFFA);
    func_800B8C4C(arg0, 0x3874);
    func_800B8C4C(arg0, 0x38EF);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B004EC;
}
