#include "types.h"
typedef struct { u8 pad0[0x2BC]; s16 a2BC; } A;
void func_800B8C4C();
void func_800BC8F4();
void func_80000AE8(A *this) {
    this->a2BC = 0x28;
    func_800B8C4C(this, 0x389E);
    func_800BC8F4(this, 0, 0xFF, 0, 0x28);
}
