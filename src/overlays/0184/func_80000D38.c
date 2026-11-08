#include "types.h"
typedef struct { u8 pad0[0x4]; u32 flags; u8 pad1[0x2BC]; void* a2C4; } A;
extern u8 D_8094EBF4[];
void func_80147CC4();
void func_80000D38(A *thisx, s32 play) {
    A *this = thisx;
    func_80147CC4(play);
    this->flags &= ~0x100;
    this->a2C4 = D_8094EBF4;
}
