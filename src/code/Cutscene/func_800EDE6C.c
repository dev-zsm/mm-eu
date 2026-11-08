#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn800EDE6CVec;

typedef struct {
    u8 pad0[2];
    u16 unk2;
    u16 unk4;
    u8 pad6[6];
    s32 unkC;
    u8 pad10[4];
    s32 unk14;
    s32 unk18;
    u8 pad1C[4];
    s32 unk20;
} Fn800EDE6CKey;

typedef struct {
    u8 pad0[0x24];
    f32 unk24;
    u8 pad28[4];
    f32 unk2C;
    u8 pad30[2];
    s16 unk32;
    u8 pad34[0x8A];
    s16 unkBE;
} Fn800EDE6CCam;

typedef struct {
    u8 pad0[0x1F34];
    u16 unk1F34;
    u8 pad1F36[0x16];
    Fn800EDE6CKey *unk1F4C;
} Fn800EDE6CCtx;

extern f32 Environment_LerpWeight(u16, u16, u16, Fn800EDE6CCtx *);
extern s16 Math_Vec3f_Yaw(Fn800EDE6CVec *, Fn800EDE6CVec *);
extern void Math_SmoothStepToS(s16 *, s16, s32, s32, s32);

void Cutscene_ActorTranslateXZAndYawSmooth(Fn800EDE6CCam *arg0, Fn800EDE6CCtx *arg1, s32 arg2) {
    Fn800EDE6CVec sp44;
    Fn800EDE6CVec sp38;
    f32 t;
    Fn800EDE6CCtx *p;

    p = (Fn800EDE6CCtx *)((u8 *)arg1 + arg2 * 4);
    sp44.x = p->unk1F4C->unkC;
    sp44.z = p->unk1F4C->unk14;
    sp38.x = p->unk1F4C->unk18;
    sp38.z = p->unk1F4C->unk20;
    t = Environment_LerpWeight(p->unk1F4C->unk4, p->unk1F4C->unk2, arg1->unk1F34, arg1);
    arg0->unk24 = (sp38.x - sp44.x) * t + sp44.x;
    arg0->unk2C = (sp38.z - sp44.z) * t + sp44.z;
    Math_SmoothStepToS(&arg0->unk32, Math_Vec3f_Yaw(&sp44, &sp38), 0xA, 0x3E8, 1);
    arg0->unkBE = arg0->unk32;
}
