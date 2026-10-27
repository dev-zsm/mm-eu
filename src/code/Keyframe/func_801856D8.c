#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 frameCount;
} AnimHeader;

typedef struct {
    u8 pad0[0x18];
    void *skeleton;
} KeyframeSkeleton;

extern AnimHeader *func_80100304(void *segmentedAddr);
extern s32 Keyframe_StandardChangeAnim(void *arg0, void *arg1, void *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8, s32 arg9);

void Keyframe_StandardPlayOnce(KeyframeSkeleton *skel, void *anim, s32 arg) {
    Keyframe_StandardChangeAnim(skel, skel->skeleton, anim, 1.0f, func_80100304(anim)->frameCount, 1.0f, 1.0f, 0.0f, 0, arg);
}
