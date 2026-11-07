#include "types.h"
typedef struct { u8 pad0[0x68]; f32 a68; u8 pad1[0xA3E]; s16 aAAA; u8 pad2[0x24]; f32 aD0; u8 pad3[0x74]; f32 aB48; } A;
f32 func_800FEB44(s16);
f32 func_800FEB84(s16);
void func_8002315C(A *thisx) {
    A *this = thisx;
    this->aD0 = func_800FEB44(this->aAAA) * this->aB48;
    this->a68 = -func_800FEB84(this->aAAA) * this->aB48;
}
