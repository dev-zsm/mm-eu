// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0390.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80A9AC9C(u8 *);                      /* extern */
M2C_UNK func_80A9DA2C(u8 *);                      /* extern */
extern u8 D_801E7DF4;

void func_8000413C(Actor *thisx, s32 arg1) {
    func_80A9AC9C(thisx);
    if (func_800B8254(thisx, arg1) != 0) {
        func_80A9DA2C(thisx);
    } else if ((M2C_FIELD(thisx, u8 *, 0x114) != 0) || (M2C_FIELD(thisx, f32 *, 0x98) < 100.0f)) {
        func_800B8398(thisx, arg1, 0x42F00000);
    }
    if (D_801E7DF4 & 8) {
        func_800B6490(thisx);
    }
}
