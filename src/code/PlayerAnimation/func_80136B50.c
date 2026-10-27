#include "types.h"

typedef struct {
    u8 type;
    u8 pad1[0x1F];
    s32 unk20;
} LinkAnimationHeader;

extern void AnimTaskQueue_AddLoadPlayerFrame(void *a0, s32 a1, s32 a2, s32 a3, s32 a4);

void PlayerAnimation_LoadToJoint(void *play, LinkAnimationHeader *anim, s32 a2, f32 frame) {
    AnimTaskQueue_AddLoadPlayerFrame(play, a2, (s32)frame, anim->type, anim->unk20);
}
