#include "types.h"

typedef struct {
    u8 pad0[0x90];
} Elem_80198D18;

typedef struct {
    /* 0x0000 */ u8 pad0[0x4BC0];
    /* 0x4BC0 */ s32 unk4BC0;
    /* 0x4BC4 */ s32 pad4BC4;
    /* 0x4BC8 */ void *unk4BC8;
} Part_80198D18;

typedef struct {
    u8 pad0[0x7928];
    void *unk7928;
    void *unk792C;
    s32 unk7930;
    s32 unk7934;
} Head_80198D18;

extern Head_80198D18 D_801F84B0;
extern Elem_80198D18 D_801FCFF0[];
extern Elem_80198D18 D_801FD070[];
extern Elem_80198D18 D_801FFD70[];
extern u8 D_801FFDD8[];
extern void AudioList_PushBack(void *, void *);

void AudioScript_InitLayerFreelist(void) {
    Elem_80198D18 *s2;
    Elem_80198D18 *s1;
    Elem_80198D18 *s0;

    D_801F84B0.unk7928 = D_801FFDD8;
    D_801F84B0.unk792C = D_801FFDD8;
    D_801F84B0.unk7930 = 0;
    D_801F84B0.unk7934 = 0;
    s2 = D_801FCFF0;
    s1 = D_801FD070;
    s0 = (Elem_80198D18 *)&D_801F84B0;
    do {
        ((Part_80198D18 *)s0)->unk4BC8 = s2;
        ((Part_80198D18 *)s0)->unk4BC0 = 0;
        AudioList_PushBack(D_801FFDD8, s1);
        s1++;
        s0++;
        s2++;
    } while (s1 != D_801FFD70);
}
