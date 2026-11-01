#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 padD;
    s16 unkE;
} AnimEntry;

extern AnimEntry D_801BCDD0[];
extern s16 Animation_GetLastFrame(s32 a, s16 b);
extern void Animation_Change(s32 a, s32 b, s32 c, f32 d, f32 e, s32 f, f32 g);

s32 EnHy_ChangeAnim(s32 arg0, s16 arg1) {
    s16 frames;
    s16 pad;
    s32 ret = 0;
    AnimEntry *e;

    if (arg1 >= 0 && arg1 < 0x15) {
        e = &D_801BCDD0[arg1];
        ret = 1;
        frames = e->unkA;
        if (frames < 0) {
            frames = Animation_GetLastFrame(e->unk0, arg1);
        }
        Animation_Change(arg0, e->unk0, e->unk4, e->unk8, frames, e->unkC, e->unkE);
    }
    return ret;
}
