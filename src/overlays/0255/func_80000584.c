#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ s16 params;
    /* 0x01E */ u8 pad1E[0x172];
    /* 0x190 */ void *unk190;
    /* 0x194 */ u8 pad194[0x1C];
    /* 0x1B0 */ s16 unk1B0;
    /* 0x1B2 */ s16 unk1B2;
} Ovl0255Actor;

extern u8 D_809894BC[];
extern s16 D_80989A3C[];

void func_80000584(Ovl0255Actor *this) {
    this->unk190 = D_809894BC;
    this->unk1B0 = 0;
    this->unk1B2 = D_80989A3C[(this->params >> 11) & 7];
}
