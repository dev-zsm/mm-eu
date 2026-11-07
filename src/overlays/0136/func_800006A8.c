#include "types.h"
typedef struct { u8 p[0x14]; } E14;
typedef struct { u8 pad0[0x248]; void* a248; u8 pad1[0x2]; u8 a24E; } A;
extern E14 D_80901E14[];
extern u8 D_80901284[];
void func_80900B90();
void func_800006A8(A *this) {
    func_80900B90(this, &D_80901E14[this->a24E]);
    this->a248 = D_80901284;
}
