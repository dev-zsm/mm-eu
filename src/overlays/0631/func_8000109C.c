#include "types.h"
typedef struct { u8 pad0[0x284]; void *p284; u8 pad1[0x2A4-0x288]; s32 v; } A;
extern u8 D_80BF1104;
extern void func_80BF0030();
void func_8000109C(A *a) {
    a->v = 0;
    func_80BF0030(a, 1);
    a->p284 = &D_80BF1104;
}
