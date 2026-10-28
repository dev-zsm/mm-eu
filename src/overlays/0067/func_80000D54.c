// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6004C20;
extern M2C_UNK D_80876B44;

void func_80000D54(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6004C20, 0xC0800000);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x302) = func_800FF250(0x1E, 0x32);
    M2C_FIELD(arg0, M2C_UNK **, 0x2FC) = &D_80876B44;
}
