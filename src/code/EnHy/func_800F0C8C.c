#include "types.h"

typedef struct {
    u8 pad0[0x1E8];
    s16 timer;
} EnHy;

void EnHy_ChangeObjectAndAnim(EnHy *arg0, s32 arg1, s16 arg2);

s32 EnHy_SetPointBackwards(EnHy *arg0, s32 arg1, s16 arg2) {
    EnHy_ChangeObjectAndAnim(arg0, arg1, arg2);
    arg0->timer--;
    return 0;
}
