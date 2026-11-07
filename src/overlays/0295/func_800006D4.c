#include "types.h"
typedef struct { u8 pad0[0x230]; void* a230; u8 pad1[0x18E]; s16 a3C2; u8 pad2[0x2]; s16 a3C6; } A;
extern u8 D_809FC194[];
void func_809FBD90();
void func_800B8C4C();
void func_800006D4(A *this) {
    func_809FBD90(this, 1);
    this->a3C2 = 1;
    func_800B8C4C(this, 0x3992);
    this->a3C6 = 1;
    this->a230 = D_809FC194;
}
