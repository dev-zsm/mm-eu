#include "types.h"
typedef struct { u8 pad0[0xBE]; s16 aBE; u8 pad1[0xA14]; s16 aD4; } P;
void func_80839E6C();
void func_8000CDDC(P *p, s32 b, s16 c) {
    p->aD4 = c;
    p->aBE = p->aD4;
    func_80839E6C(p, b, c);
}
