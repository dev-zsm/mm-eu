#include "types.h"

typedef struct {
    s32 unk0;
    u8 limbCount;
} Header;
typedef struct {
    u8 limbCount;
    u8 pad1[3];
    Header *skeleton;
    u8 pad8[0x18];
    s32 jointTable;
    s32 morphTable;
} Skin;
Header *func_80100304(s32 a);
s32 ZeldaArena_Malloc(s32 size);
void Animation_PlayLoop(Skin *skin, s32 anim);
void SkelAnime_InitSkin(s32 unused, Skin *skin, s32 skeletonHeader, s32 anim) {
    Header *h;
    s32 t;
    s32 a;
    h = func_80100304(skeletonHeader);
    skin->limbCount = h->limbCount + 1;
    if (1) {
        skin->skeleton = func_80100304(h->unk0);
        skin->jointTable = ZeldaArena_Malloc(skin->limbCount * 6);
        t = ZeldaArena_Malloc(skin->limbCount * 6);
        a = anim;
        skin->morphTable = t;
    }
    if (a != 0) {
        Animation_PlayLoop(skin, a);
    }
}
