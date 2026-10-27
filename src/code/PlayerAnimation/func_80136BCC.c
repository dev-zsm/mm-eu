#include "types.h"

typedef struct {
    /* 0x00 */ u8 limbCount;
    /* 0x01 */ u8 pad1[0x1F];
    /* 0x20 */ s32 unk20;
} SkelAnime;

extern void AnimTaskQueue_AddLoadPlayerFrame(void *play, void *anim, s32 frame, u8 num, s32 dst);
extern void AnimTaskQueue_AddInterp(void *play, u8 num, s32 a, s32 dst, f32 f);

void PlayerAnimation_BlendToJoint(void *play, SkelAnime *sa, void *anim1, f32 frame1, void *anim2, f32 frame2, f32 blend, s32 buf) {
    s32 aligned;

    AnimTaskQueue_AddLoadPlayerFrame(play, anim1, frame1, sa->limbCount, sa->unk20);
    aligned = ((buf + 0xF) & ~0xF);
    AnimTaskQueue_AddLoadPlayerFrame(play, anim2, frame2, sa->limbCount, aligned);
    AnimTaskQueue_AddInterp(play, sa->limbCount, sa->unk20, aligned, blend);
}
