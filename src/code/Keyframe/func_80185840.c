#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 unk12;
} KeyframeAnim5840;

typedef struct {
    u8 pad0[0x18];
    void *unk18;
} KeyframeSkel5840;

KeyframeAnim5840 *func_80100304(void *);
void Keyframe_StandardChangeAnim(KeyframeSkel5840 *, void *, void *, f32, f32, f32, f32, f32, s32, void *);

void Keyframe_StandardPlayLoop(KeyframeSkel5840 *skel, void *anim, void *arg2) {
    Keyframe_StandardChangeAnim(skel, skel->unk18, anim, 1.0f, func_80100304(anim)->unk12, 1.0f, 1.0f, 0.0f, 1,
                                arg2);
}
