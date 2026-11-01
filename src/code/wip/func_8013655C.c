// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad0[0xA2]; u8 unkA2; } Play;
typedef struct {
    u8 unk0;
    u8 pad1[7];
    s32 unk8;
    u8 pad_c[0x18 - 0xC];
    f32 unk18;
    u8 pad1c[4];
    s32 unk20;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
} Anim;
extern void AnimTaskQueue_AddLoadPlayerFrame(Play *play, s32 a, s32 b, u8 c, s32 d);
extern void AnimTaskQueue_AddInterp(f32 z, u8 b, s32 c, s32 d, f32 e);
void PlayerAnimation_AnimateFrame(Play *play, Anim *a) {
    AnimTaskQueue_AddLoadPlayerFrame(play, a->unk8, (s32)a->unk18, a->unk0, a->unk20);
    if (a->unk28 != 0.0f) {
        a->unk28 -= a->unk2C * ((s32)play->unkA2 * 0.5f);
        if (a->unk28 <= 0.0f) {
            a->unk28 = 0.0f;
        } else {
            AnimTaskQueue_AddInterp(0.0f, a->unk0, a->unk20, a->unk24, a->unk28);
        }
    }
}
