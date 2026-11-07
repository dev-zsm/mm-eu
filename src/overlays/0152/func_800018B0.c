#include "types.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x14]; Vec3s home; u8 pad1[0xA2]; Vec3s shape; u8 pad2[0x82]; void* a144; u8 pad3[0x4F]; u8 a197; } A;
extern u8 D_8091ADC8[];
void func_80919C6C();
void func_800018B0(A *this) {
    this->a144 = D_8091ADC8;
    func_80919C6C(this);
    this->a197 = 0;
    this->shape = this->home;
}
