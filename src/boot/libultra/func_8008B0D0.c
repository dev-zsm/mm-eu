// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 *D_80098010;

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
} Obj14;

s32 osGetThreadId(Obj14 *arg0) {
    if (arg0 == NULL) {
        arg0 = (Obj14 *)D_80098010;
    }
    return arg0->unk14;
}
