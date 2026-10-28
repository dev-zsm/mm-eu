// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A0D3F0();                            /* extern */
extern f32 D_80A0E4E0;
extern f32 D_80A0E4E4;

void func_8000114C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x2A8) = (f32) (M2C_FIELD(arg0, f32 *, 0x2A8) + D_80A0E4E0);
    if (D_80A0E4E4 < M2C_FIELD(arg0, f32 *, 0x2A8)) {
        func_80A0D3F0();
    }
}
