// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8013796C(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_80893138(u8 *);                      /* extern */
extern M2C_UNK D_6000A14;
extern M2C_UNK D_80894B44;

void func_80001AFC(u8 *arg0) {
    func_8013796C(arg0 + 0x144, &D_6000A14, 0x3FC00000);
    func_800B8C4C(arg0, 0x3888);
    M2C_FIELD(arg0, u8 *, 0x3BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x3BD) & 0xFFFE);
    func_80893138(arg0);
    M2C_FIELD(arg0, s8 *, 0x2B9) = 1;
    M2C_FIELD(arg0, s16 *, 0x2BC) = 0x190;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    M2C_FIELD(arg0, s8 *, 0x2B8) = (s8) (u32) (func_8008704C() * 50.0f);
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x2B4) = &D_80894B44;
    M2C_FIELD(arg0, f32 *, 0x68) = 11.0f;
}
