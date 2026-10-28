#include "types.h"

typedef struct { u8 pad[0x116]; s16 flags; } S0052;
extern S0052 *D_801EB7E0;

void func_800000B0(void *a0) {
    D_801EB7E0->flags |= 1;
}
