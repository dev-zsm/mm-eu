#include "types.h"
typedef struct { u8 pad0[0x278]; void* a278; s16 a27C; u8 pad1[0xA]; s16 a288; } A;
extern u8 D_80994180[];
void func_80992908();
void func_80001B1C(A *this) {
    func_80992908(this, 8);
    this->a27C = 0xA;
    this->a288 = 0x1E;
    this->a278 = D_80994180;
}
