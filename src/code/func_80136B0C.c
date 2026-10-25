#include "types.h"

typedef struct {
    u8 unk0;
    u8 pad1[0x23];
    s32 unk24;
} AnimSource;

extern void AnimTaskQueue_AddLoadPlayerFrame(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void PlayerAnimation_LoadToMorph(s32 a0, AnimSource *src, s32 a2, f32 a3) {
    AnimTaskQueue_AddLoadPlayerFrame(a0, a2, (s32)a3, src->unk0, src->unk24);
}
