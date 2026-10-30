#include "types.h"

typedef struct {
    u8 pad0[0x160];
    s16 unk160;
} A;

s32 func_8013E684();
void func_80BBB548();

void func_800001E8(A *a, void *b) {
    if (func_8013E684(a, a->unk160, -1, 0) != 0) {
        func_80BBB548(a);
    }
}
