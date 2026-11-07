#include "types.h"
#include "m2c_compat.h"
typedef struct { s32 x, y, z; } V;

s32 func_80000338(u8 *a, u8 *play) {
    u8 *p;

    for (p = M2C_FIELD(play, u8 **, 0x1CC0); p != NULL; p = M2C_FIELD(p, u8 **, 0x12C)) {
        if (M2C_FIELD(p, s16 *, 0) == 0xA7) {
            M2C_FIELD(a, s16 *, 0x394) = M2C_FIELD(p, s16 *, 0xBE);
            M2C_FIELD(a, V *, 0x398) = M2C_FIELD(p, V *, 0x24);
            return 1;
        }
    }
    return 0;
}
