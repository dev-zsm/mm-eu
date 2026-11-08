#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0611.h"
u8 *func_80000920(u8 *a, u8 *play) {
    u8 *p;

    for (p = M2C_FIELD(play, u8 **, 0x1CE4); p != NULL; p = M2C_FIELD(p, u8 **, 0x12C)) {
        if (M2C_FIELD(p, s16 *, 0) == 0x27B && (M2C_FIELD(p, s16 *, 0x1C) & 0xF) == (M2C_FIELD(a, s16 *, 0x1C) & 0xF) && a != p) {
            return p;
        }
    }
    return NULL;
}
