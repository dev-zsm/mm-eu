// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x98];
    f32 unk98;
} Act;

s32 func_800B70A4();
s32 func_800B7164();

s32 func_800004CC(Act *this, void *play) {
    void *p = play;

    if (this->unk98 < 100.0f && func_800B70A4(this, 0x3000, p) != 0 && func_800B7164(this, 0x3000) != 0) {
        return 1;
    }
    return 0;
}
