#include "types.h"
typedef struct { u8 pad0[0x14E]; s16 a14E; u8 pad1[0x314]; void* a464; } A;
extern u8 D_809B9194[];
void func_800BC8F4();
void func_80003EEC(A *this, s32 play) {
    this->a464 = D_809B9194;
    this->a14E = 0x28;
    func_800BC8F4(this, 0, 0x78, 0, 0x28);
}
