#include "types.h"

typedef struct {
    u16 w0;
    u16 w2;
    u16 w4;
    u16 w6;
    u16 w8;
    u16 wA;
    u16 wC;
} Data;

typedef struct {
    u8 pad0[8];
    u32 bits;
    u8 pad0C[0x54];
    u8 *unk60;
} Env;

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10[4];
    Env *env;
} Inner;

typedef struct {
    Data *data;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 pad15;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
} Vib;

typedef struct {
    u8 pad0[0x34];
    u8 pad34[0x14];
    Env *env48;
    u8 pad4C[0x48];
    Vib vib;
} Chan;

extern s32 D_801CD6C8;

void AudioEffects_InitVibrato(Chan *c) {
    Inner *in;
    Vib *v;
    Data *d;
    u16 t;

    in = (Inner *)&c->pad34;
    c->vib.unk14 = 1;
    c->vib.unk8 = D_801CD6C8;
    if (((u32)(c->env48->bits << 19) >> 31) == 1) {
        in = (Inner *)&c->pad34;
        v = &c->vib;
        v->data = (Data *)(in->env->unk60 + 0x12);
    } else {
        v = &c->vib;
        v->data = (Data *)((u8 *)in->env + 0xC);
    }
    d = v->data;
    t = d->wA;
    v->unk18 = t;
    if (t == 0) {
        v->unkC = (s32)d->w6;
    } else {
        v->unkC = (s32)d->w2;
    }
    t = d->w8;
    v->unk16 = t;
    if (t == 0) {
        v->unk10 = (s32)d->w4;
    } else {
        v->unk10 = (s32)d->w0;
    }
    in->unkC = 1.0f;
    v->unk4 = 0;
    v->unk1A = d->wC;
}
