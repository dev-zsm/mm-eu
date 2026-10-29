#include "types.h"

typedef struct {
    /* 0x00 */ u8 limbCount;
    /* 0x01 */ u8 pad1[3];
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ void *animation;
    /* 0x0C */ f32 startFrame;
    /* 0x10 */ f32 endFrame;
    /* 0x14 */ f32 animLength;
    /* 0x18 */ f32 curFrame;
    /* 0x1C */ f32 playSpeed;
    /* 0x20 */ void *morphTable;
} Skel;

extern f32 D_801C9E1C;
extern void SkelAnime_GetFrameData();
extern void SkelAnime_AnimateFrame();

s32 SkelAnime_Once(Skel *s) {
    f32 end = s->endFrame;
    f32 cur = s->curFrame;
    f32 sp = D_801C9E1C;

    if (end == cur) {
        SkelAnime_GetFrameData(s->animation, (s32)s->curFrame, s->limbCount, s->morphTable);
        SkelAnime_AnimateFrame(s);
        return 1;
    }
    s->curFrame += s->playSpeed * sp;
    if ((s->curFrame - end) * s->playSpeed > 0.0f) {
        s->curFrame = end;
    } else if (s->curFrame < 0.0f) {
        s->curFrame += s->animLength;
    } else if (s->curFrame >= s->animLength) {
        s->curFrame -= s->animLength;
    }
    SkelAnime_AnimateFrame(s);
    return 0;
}
