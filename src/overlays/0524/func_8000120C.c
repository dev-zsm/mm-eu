// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B8398(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_80B788C8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B7910C(u8 *, u8 *);              /* extern */
extern u8 D_801E6F10;
extern M2C_UNK D_80B790E0;
extern M2C_UNK D_80B79190;

void func_8000120C(u8 *arg0, u8 *arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s16 *, 0x300) = 2;
        M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_80B79190;
    } else if ((M2C_FIELD(arg1, u16 *, 0x16936) == 3) && (M2C_FIELD(arg0, f32 *, 0x98) < 120.0f)) {
        if ((M2C_FIELD(arg1, u16 *, 0x1693A) == 7) && (D_801E6F10 == 4)) {
            func_80B788C8(arg0, 2);
            M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_80B790E0;
            M2C_FIELD(arg0, s32 *, 0xC8) = 0;
        }
    } else if (M2C_FIELD(arg0, f32 *, 0x98) < 120.0f) {
        func_800B8398(arg0, arg1, 0x43160000);
    }
    func_80B7910C(arg0, arg1);
}
