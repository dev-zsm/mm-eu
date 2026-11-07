#include "types.h"
typedef struct { u8 pad0[0x2A8]; void* a2A8; u8 a2AC; u8 pad1[0xAB]; s16 a358; } A;
extern u8 D_8098B3A8[];
void func_8098B264();
void func_80000358(A *this) {
    func_8098B264(this, 0);
    if (this->a2AC != 2) {
        this->a2AC = 1;
    }
    this->a358 = 4;
    this->a2A8 = D_8098B3A8;
}
