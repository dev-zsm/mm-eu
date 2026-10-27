#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
} Hdr;

extern s32 func_80100304(s32);

void CollisionHeader_SegmentedToVirtual(Hdr *a0) {
    a0->unk10 = func_80100304(a0->unk10);
    a0->unk18 = func_80100304(a0->unk18);
    if (a0->unk1C != 0) {
        a0->unk1C = func_80100304(a0->unk1C);
    }
    if (a0->unk20 != 0) {
        a0->unk20 = func_80100304(a0->unk20);
    }
    if (a0->unk28 != 0) {
        a0->unk28 = func_80100304(a0->unk28);
    }
}
