#include "types.h"

typedef struct { u8 pad0[2]; u8 type; u8 pad3[0xE9]; u8 pos[1]; } Obj;
typedef struct { Obj *obj; } Col;
typedef struct { u8 pad0[0x14]; u8 kind; } Info;

extern void Audio_PlaySfx_AtPos(void *, s32);

s32 CollisionCheck_SwordHitAudio(Col *col, Info *info) {
    Obj *o = col->obj;

    if (o != 0 && o->type == 2) {
        if (info->kind == 0) {
            Audio_PlaySfx_AtPos(&o->pos, 0x1811);
        } else if (info->kind == 1) {
            Audio_PlaySfx_AtPos(&o->pos, 0x1824);
        } else if (info->kind == 2) {
            Audio_PlaySfx_AtPos(&o->pos, 0);
        } else if (info->kind == 3) {
            Audio_PlaySfx_AtPos(&o->pos, 0);
        }
    }
    return 1;
}
