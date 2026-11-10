// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
typedef struct { u8 p0[0x64]; f32 a64, a68, a6C, a70; u8 p1[0x328 - 0x74]; f32 a328, a32C, a330; } T;
void func_800B6730(T *);
void func_80000738(T *this) {
    this->a64 = this->a70 * this->a328;
    this->a68 = this->a70 * this->a32C;
    this->a6C = this->a70 * this->a330;
    func_800B6730(this);
}
