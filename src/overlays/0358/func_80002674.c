// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A4D8CC();                            /* extern */
extern M2C_UNK D_80A4FBDC;
extern f32 D_80A50800;
extern f32 D_80A50804;

void func_80002674(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x30C) = (s32) (M2C_FIELD(arg0, s32 *, 0x30C) & ~1);
    M2C_FIELD(arg0, s16 *, 0x368) = 0x64;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x78) = (f32) D_80A50800;
    M2C_FIELD(arg0, f32 *, 0x74) = (f32) D_80A50804;
    func_80A4D8CC();
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_80A4FBDC;
}
