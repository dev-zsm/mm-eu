// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_80A3C2D0(u8 *);                      /* extern */
extern M2C_UNK D_600026C;
extern M2C_UNK D_80A3C3AC;
extern f32 D_80A3D268;

void func_800014A4(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_600026C, 0xC0A00000);
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_80A3D268;
    func_80A3C2D0(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A3C3AC;
}
