// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80902150(u8 *);                      /* extern */
extern M2C_UNK D_80902E3C;

void func_80000CB0(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x78) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x240) = func_800FF250(0xA, 0x28, arg0);
    M2C_FIELD(arg0, s32 *, 0x248) = 0;
    M2C_FIELD(arg0, s16 *, 0x26E) = 0x190;
    M2C_FIELD(arg0, s16 *, 0x272) = 0x190;
    M2C_FIELD(arg0, s16 *, 0x268) = 0;
    M2C_FIELD(arg0, s16 *, 0x26C) = 0;
    func_80902150(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x23C) = &D_80902E3C;
}
