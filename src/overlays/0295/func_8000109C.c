#include "types.h"

extern void func_809FBD90();
extern u8 D_809FCB4C[];

typedef struct { u8 pad0[0x230]; void *unk230; u8 pad234[0x3B6 - 0x234]; s16 unk3B6; u8 pad3B8[0xE]; s16 unk3C6; } A;

void func_8000109C(A *this) {
    func_809FBD90(this, 5);
    this->unk3C6 = 6;
    this->unk3B6 = 0;
    this->unk230 = D_809FCB4C;
}
