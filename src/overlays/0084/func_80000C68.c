#include "types.h"
typedef struct { u8 pad0[0x2A8]; void* a2A8; u8 pad1[0x8]; s16 a2B4; } A;
extern u8 D_808A3934[];
void func_808A325C();
void func_808A3164();
void func_80000C68(A *this, s32 play) {
    func_808A325C(this);
    func_808A3164(this);
    if (this->a2B4 > 0) {
        this->a2B4--;
    } else {
        this->a2A8 = D_808A3934;
    }
}
