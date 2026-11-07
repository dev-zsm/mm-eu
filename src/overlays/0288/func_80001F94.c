#include "types.h"
typedef struct { u8 pad0[0x162]; s16 a162; u8 pad1[0xC]; void* a170; } A;
extern u8 D_809D51F0[];
extern u8 D_6003448[];
void func_80137828(u8 *, u8 *, f32, void *);
void func_80001F94(A *thisx, s32 play) {
    A *this = thisx;
    this->a170 = D_809D51F0;
    func_80137828((u8 *)this + 0x3C8, D_6003448, 0, this);
    this->a162 = 0x14;
}
