#include "types.h"
#include "m2c_compat.h"
u8 *func_80000270(u8 *a) {
    u8 *p;

    for (p = M2C_FIELD(a, u8 **, 0x1CE4); p != NULL; p = M2C_FIELD(p, u8 **, 0x12C)) {
        if (M2C_FIELD(p, s16 *, 0) == 0x1BD && !(M2C_FIELD(p, s16 *, 0x1C) & 1)) {
            return p;
        }
    }
    return NULL;
}
