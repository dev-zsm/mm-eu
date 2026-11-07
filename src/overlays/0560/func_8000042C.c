#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BABE08[];

void func_8000042C(u8 *a, u8 *play) {
    u8 *p = M2C_FIELD(play, u8 **, 0x1CCC);
    u8 s;

    if (M2C_FIELD(a, s16 *, 0x268) != 0) {
        s = M2C_FIELD(p, u8 *, 0x14B);
        if (s == 4 || s == 3) {
            M2C_FIELD(a, s16 *, 0x252) = 0x1388;
        }
    }
    M2C_FIELD(a, s16 *, 0x266) = 1;
    M2C_FIELD(a, s16 *, 0x272) = 1;
    M2C_FIELD(a, void **, 0x248) = D_80BABE08;
}
