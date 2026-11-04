#include "types.h"

typedef struct { u8 unk0; u8 pad1[0x1F]; u32 unk20; u32 unk24; } PlayerAnimArg;

s32 AnimTaskQueue_AddCopy();

s32 PlayerAnimation_CopyJointToMorph(s32 a0, PlayerAnimArg *a1) {
    return AnimTaskQueue_AddCopy(a0, a1->unk0, a1->unk24, a1->unk20);
}
