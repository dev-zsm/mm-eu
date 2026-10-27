// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0x10];
    u8 r, g, b;
    u8 pad13[1];
} Pt;
typedef struct {
    u8 pad0[0xC];
    u8 unkC[0x38];
    f32 unk44;
    s16 unk48;
    u8 pad4A[6];
    Pt pts[3];
} Ret;
extern u8 D_801AF7B4[][8];
void Math_Vec3f_Copy(void *, void *);
void Attention_SetReticlePos(Ret *, s32, f32, f32, f32);
void Attention_InitReticle(Ret *ret, s32 type, u8 *src) {
    u8 *c;
    Pt *p;
    s32 i;
    Math_Vec3f_Copy(&ret->unkC, src + 0xE0);
    ret->unk48 = 0x100;
    p = ret->pts;
    c = D_801AF7B4[type];
    ret->unk44 = 500.0f;
    for (i = 0; i < 3; i++) {
        Attention_SetReticlePos(ret, i, 0.0f, 0.0f, 0.0f);
        p->r = c[0];
        p->g = c[1];
        p->b = c[2];
        p++;
    }
}
