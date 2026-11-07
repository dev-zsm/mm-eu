#include "types.h"
typedef struct { u8 pad0[0x24]; u8 pos; } Q;
typedef struct { u8 pad0[0x1CCC]; Q* q; } P;
typedef struct { u8 pad0[0x32]; s16 a32; u8 pad1[0x8A]; s16 aBE; u8 pad2[0x128]; u32 a1E8; } A;
void func_8087AEA4();
void func_80001FDC(A *this, P *play) {
    func_8087AEA4(this, play, (u8 *)play->q + 0x24, 0x320);
    if (this->a1E8 & 0x4000) {
        this->a32 += 0x640;
    }
    this->aBE = this->a32;
}
