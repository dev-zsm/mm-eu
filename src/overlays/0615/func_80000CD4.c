// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFBF8(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80BE6EA8(u8 *);                      /* extern */
extern f32 D_80BE805C;

void func_80000CD4(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v1;
    u8 *temp_v0;

    func_800FFBF8(arg0 + 0x70, 0x40C00000, 0x3F000000, 0x40000000);
    temp_v1 = M2C_FIELD(arg0, u8 *, 0x2F9);
    if ((temp_v1 & 2) || (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        temp_v0 = M2C_FIELD(arg0, u8 **, 0x2E4);
        M2C_FIELD(arg0, u8 *, 0x2F9) = (u8) (temp_v1 & 0xFFFD);
        if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x138) != 0)) {
            M2C_FIELD(temp_v0, f32 *, 0x2C4) = (f32) D_80BE805C;
        }
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, u8 **, 0x2E4) = NULL;
        M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
        func_80BE6EA8(arg0);
    }
}
