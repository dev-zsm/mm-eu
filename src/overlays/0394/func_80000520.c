#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
} A;

extern s32 D_80AA24B0[];
void func_800BDD44();

void func_80000520(A *a, void *b) {
    func_800BDD44(b, D_80AA24B0[a->unk1C & 1]);
}
