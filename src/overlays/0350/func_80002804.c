// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A42728;
extern M2C_UNK D_80A43714;
extern M2C_UNK D_80A43854;
extern M2C_UNK D_80A4385C;
extern M2C_UNK D_80A43864;

void func_80002804(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A43714;
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80A42728;
    M2C_FIELD(&D_80A43854, s16 *, 0) = 0;
    M2C_FIELD(&D_80A43854, s16 *, 2) = 0;
    M2C_FIELD(&D_80A43854, s16 *, 4) = 0;
    M2C_FIELD(&D_80A4385C, s16 *, 0) = 0;
    M2C_FIELD(&D_80A4385C, s16 *, 2) = 0;
    M2C_FIELD(&D_80A4385C, s16 *, 4) = 0;
    M2C_FIELD(&D_80A43864, s16 *, 0) = 0;
    M2C_FIELD(&D_80A43864, s16 *, 2) = 0;
    M2C_FIELD(&D_80A43864, s16 *, 4) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D0) = 0x1E;
}
