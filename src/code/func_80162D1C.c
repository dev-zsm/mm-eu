#include "types.h"

typedef struct {
    u8 pad0[6];
    s16 unk6;
} State;

extern State *D_801EE3E0;

s16 func_80162D1C(void) {
    return (D_801EE3E0->unk6 == 2) || (D_801EE3E0->unk6 == 1);
}
