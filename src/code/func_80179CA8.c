#include "types.h"

extern s16 D_801F344C;

extern u16 *func_80179C88(void);

u16 func_80179CA8(s32 x, u32 y) {
    u16 *table = func_80179C88();
    u16 value;

    if (table != NULL) {
        value = table[x + y * D_801F344C];
    } else {
        value = 0;
    }
    return value;
}
