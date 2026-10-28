// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80B78BC0();                                /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B7923C;

void func_8000130C(u8 *arg0) {
    if (func_80B78BC0() == 0) {
        M2C_FIELD(arg0, s16 *, 0x116) = 0x103C;
        M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_80B7923C;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x02000000);
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF53) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF53) | 2);
    }
    if ((M2C_FIELD(arg0, s16 *, 0x304) == 0xB) && ((s32) M2C_FIELD(arg0, f32 *, 0x1A8) >= 0x37)) {
        M2C_FIELD(arg0, u16 *, 0x30A) = (u16) (M2C_FIELD(arg0, u16 *, 0x30A) | 2);
    }
}
