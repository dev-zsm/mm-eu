#include "types.h"
typedef struct { u8 pad[0x1BC]; f32 unk1BC; } A;
extern void func_808809B0(A *);
void func_80005B3C(A *a) {
    a->unk1BC = 0.0f;
    func_808809B0(a);
}
