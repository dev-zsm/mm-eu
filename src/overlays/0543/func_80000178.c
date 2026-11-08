#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0543.h"
u8 * func_80000178(PlayState *play, s16 b) {
    u8 *p;

    for (p = M2C_FIELD(play, u8 **, 0x1CE4); p != NULL; p = M2C_FIELD(p, u8 **, 0x12C)) {
        if (b == M2C_FIELD(p, s16 *, 0)) {
            return p;
        }
    }
    return NULL;
}
