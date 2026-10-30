#include "types.h"

extern void func_80C08B00();
extern u8 D_80C08BB8[];

typedef struct { u8 pad0[0x278]; void *unk278; s32 unk27C; s32 unk280; u8 pad284[0xC]; s16 unk290; } A;

void func_8000014C(A *this) {
    func_80C08B00(this, this->unk280);
    this->unk290 = 1;
    this->unk278 = D_80C08BB8;
}
