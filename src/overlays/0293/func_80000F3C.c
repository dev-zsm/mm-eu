#include "types.h"

typedef struct {
    u8 pad0[0x2EC];
    s32 unk2EC[1];
} S;

s32 func_80000F3C(S *s, u8 a1) {
    if (s->unk2EC[a1] != 0) {
        return a1;
    }
    return 0xFF;
}
