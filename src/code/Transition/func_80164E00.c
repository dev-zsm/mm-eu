#include "types.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
} Src;
typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0xC];
    Src *unk14;
    u8 pad18[4];
} Trans;
typedef struct {
    u8 pad0[2];
    s8 unk2;
    u8 pad3[0x22D];
    u32 unk230;
    u32 unk234;
    u32 unk238;
    u32 unk23C;
    u32 unk240;
    u32 unk244;
    u32 unk248;
    u32 unk24C;
    u32 unk250;
} Dst;
extern Trans D_801C9490[];
extern void TransitionOverlay_Load();
extern s32 Lib_PhysicalToVirtual();
void Transition_Init(Dst *a0) {
    Trans *t = &D_801C9490[a0->unk2];
    s32 pad;
    Src *s;
    Src **ps = &s;
    Src *base;
    s32 d;
    TransitionOverlay_Load(t, a0);
    d = Lib_PhysicalToVirtual(t->unk0 & 0xFFFFFF) - t->unk4;
    s = 0;
    base = t->unk14;
    if (base != ((void *) 0)) {
        s = (Src *) (((u8 *) base) + d);
    } else {
        s = (void *) 0;
    }
    a0->unk230 = s->unk0;
    a0->unk234 = s->unk4;
    a0->unk240 = s->unk10;
    a0->unk250 = s->unk20;
    a0->unk23C = s->unkC;
    a0->unk238 = s->unk8;
    a0->unk244 = s->unk14;
    a0->unk248 = s->unk18;
    a0->unk24C = s->unk1C;
}
