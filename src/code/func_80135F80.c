// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    s32 unk8;
    f32 unkC;
} AnimTaskEntry;

AnimTaskEntry *AnimTaskQueue_NewTask(s32, s32);

void AnimTaskQueue_AddActorMovement(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    AnimTaskEntry *temp_v0;
    temp_v0 = AnimTaskQueue_NewTask(arg0 + 0x17104, 5);
    if (temp_v0 != NULL) {
        temp_v0->unk4 = arg1;
        temp_v0->unk8 = arg2;
        temp_v0->unkC = arg3;
    }
}
