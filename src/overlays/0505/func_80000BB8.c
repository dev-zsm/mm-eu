#include "types.h"

extern void func_800BDD44();
extern s32 D_80B554B8[];

typedef struct { u8 pad0[0x1C]; s16 unk1C; } A;

void func_80000BB8(A *this, s32 play) {
    func_800BDD44(play, D_80B554B8[this->unk1C & 1], play, this);
}
