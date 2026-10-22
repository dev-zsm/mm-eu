// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x18864];
    void *unk18864;
} Ctx90;

s32 func_80122990(Ctx90 *arg0, s16 arg1, s16 arg2) {
    s32 var_v1;

    if (arg1 != arg2) {
        var_v1 = (s32)arg0->unk18864 + (arg1 * 8);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}
