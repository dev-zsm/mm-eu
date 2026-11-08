// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    s32 unk8;
    f32 unkC;
} AnimTaskEntry;

AnimTaskEntry *AnimTaskQueue_NewTask(s32, s32);

void AnimTaskQueue_AddActorMovement(struct PlayState *play, struct Actor *actor, struct SkelAnime *skelAnime, f32 moveDiffScale) {
    AnimTaskEntry *temp_v0;
    temp_v0 = AnimTaskQueue_NewTask((u8 *)play + 0x17104, 5);
    if (temp_v0 != NULL) {
        temp_v0->unk4 = actor;
        temp_v0->unk8 = skelAnime;
        temp_v0->unkC = moveDiffScale;
    }
}
