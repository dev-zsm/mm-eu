#include "types.h"
typedef struct { u8 pad0[0x190]; void* a190; u8 pad1[0x6]; s16 a19A; u8 pad2[0x1]; u8 a19D; } A;
extern u8 D_8097D48C[];
void func_800B8C4C();
void func_80000C74(A *this, s32 play) {
    this->a19D = 0;
    this->a19A &= 0xFEFB;
    func_800B8C4C(this, 0x298C);
    this->a190 = D_8097D48C;
}
