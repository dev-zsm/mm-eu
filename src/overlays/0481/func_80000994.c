#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0481.h"
extern u8 D_80B1C794[];

void func_80000994(u8 *a) {
    s16 v = M2C_FIELD(a, s16 *, 0x218) & 0x7FFF;
    s32 w = M2C_FIELD(a, s32 *, 0x210);

    if ((w == 5 || w == 6) && v == 0) {
        M2C_FIELD(a, s16 *, 0x21E) = 0x64;
    } else {
        M2C_FIELD(a, s16 *, 0x21E) = 0;
    }
    M2C_FIELD(a, void **, 0x144) = D_80B1C794;
}
