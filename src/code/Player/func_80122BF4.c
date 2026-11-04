#include "types.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    u32 unk4;
} OverrideInput;

s32 Player_InitOverrideInput(void *unused, OverrideInput *input, s32 arg2, u32 arg3) {
    input->unk0 = arg2;
    input->unk1 = 0;
    input->unk4 = arg3;
    return 1;
}
