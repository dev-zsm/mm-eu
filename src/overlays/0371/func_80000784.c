#include "types.h"

typedef struct {
    u8 pad0[0x340];
    s32 unk340[1];
} Actor371;

s32 func_80000784(Actor371 *a, u8 i) {
    if (a->unk340[i] != 0) {
        return i;
    }
    return 0xFF;
}
