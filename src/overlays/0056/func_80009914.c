#include "types.h"
typedef struct { u8 pad0[0xB10]; f32 aB10; f32 aB14; } P;
extern u8 D_400E270[];
extern f32 D_8085DB00;
void func_8082DAE8();
void func_800B8BDC();
void func_80009914(s32 a, P *p) {
    func_8082DAE8(a, p, D_400E270);
    p->aB10 = D_8085DB00;
    p->aB14 = 196608.0f;
    func_800B8BDC(p, 0x9A9);
}
