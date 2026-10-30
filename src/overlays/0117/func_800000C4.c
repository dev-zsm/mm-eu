#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
} A;

void func_800E0FAC();

void func_800000C4(A *a, void *b) {
    s32 v = a->unk1C & 0x300;

    if (v == 0x200) {
        func_800E0FAC(b, (u8 *)a + 0x144);
    }
}
