#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ u8 unk8[0xC];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
} ColliderElem;

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[3];
    /* 0x04 */ u8 unk4[8];
    /* 0x0C */ u8 unkC[8];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
} ColliderElemInit;

extern void Collider_SetElementDamageInfoAT(void *, ColliderElem *, void *);
extern void Collider_SetElementDamageInfoAC(void *, void *, void *);

s32 Collider_SetElement(void *play, ColliderElem *elem, ColliderElemInit *src) {
    elem->unk14 = src->unk0;
    Collider_SetElementDamageInfoAT(play, elem, src->unk4);
    Collider_SetElementDamageInfoAC(play, elem->unk8, src->unkC);
    elem->unk15 = src->unk14;
    elem->unk16 = src->unk15;
    elem->unk17 = src->unk16;
    return 1;
}
