#include "types.h"
typedef struct { u8 pad0[0x68]; f32 a68; u8 pad1[0x4]; f32 a70; u8 pad2[0x114]; void* a188; } A;
extern u8 D_808BDADC[];
void func_800BE288();
void func_800011C8(A *this) {
    this->a70 = 0.0f;
    if (this->a68 > 0.0f) {
        this->a68 = 0.0f;
    }
    func_800BE288(this, (u8 *)this + 0x27C);
    this->a188 = D_808BDADC;
}
