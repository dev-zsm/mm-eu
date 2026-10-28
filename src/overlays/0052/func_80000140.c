// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013F2A4(u8 *, s32);                 /* extern */
M2C_UNK func_80161E10();                            /* extern */
M2C_UNK func_80174568(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801811F0(u8 *);                      /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80803EE0;
extern M2C_UNK D_80803F2C;

void func_80000140(u8 *arg0) {
    func_80174568(arg0, 1);
    func_801811F0(arg0);
    func_80161E10();
    func_8013F2A4(arg0 + 0xA8, M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, M2C_UNK **, 4) = &D_80803EE0;
    M2C_FIELD(arg0, M2C_UNK **, 8) = &D_80803F2C;
    M2C_FIELD(&D_801E6EF0, s32 *, 0x3CB0) = 0;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x3D44) = 0xFF;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x3D64) = 0xFF;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x3D84) = 0xFF;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x3DA4) = 0xFF;
}
