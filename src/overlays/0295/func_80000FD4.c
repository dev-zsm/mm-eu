#include "types.h"

typedef struct {
    u8 pad0[0x230];
    void *unk230;
    u8 pad234[0x3C4 - 0x234];
    s16 unk3C4;
    s16 unk3C6;
} A;

extern u8 D_809FCA84[];
void func_809FBD90();

void func_80000FD4(A *a) {
    func_809FBD90(a, 4);
    a->unk3C4 = 0;
    a->unk3C6 = 5;
    a->unk230 = D_809FCA84;
}
