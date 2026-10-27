#include "types.h"

typedef struct {
    u8 unk0;
    u8 pad1[0xB];
    s32 unkC;
} Out;

s32 Schedule_ReturnValueL(s32 arg0, u8 **arg1, Out *arg2) {
    u8 *p = *arg1;

    arg2->unk0 = p[2] | (p[1] << 8);
    return arg2->unkC = 1;
}
