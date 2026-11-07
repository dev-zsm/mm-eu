#include "types.h"
typedef struct { u8 pad0[0x144]; void* a144; u8 pad1[0x6]; u8 a14E; u8 pad2[0x1]; s16 a150; u8 pad3[0x1782]; s16 a18D4; u8 pad4[0x92FA]; s16 aABD0; } A;
extern u8 D_809E4BDC[];
void func_800B8C4C();
void func_8000B4E4(A *this, s32 play) {
    this->a144 = D_809E4BDC;
    this->a14E = 0;
    this->aABD0 = 0;
    this->a150 = 0x1E;
    this->a18D4 = 0;
    func_800B8C4C(this, 0x39D4);
}
