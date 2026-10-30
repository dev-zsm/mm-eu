#include "types.h"

typedef struct { u8 pad0[0x238]; s16 unk238; } A;
extern s32 func_8013E684();
extern void func_80BEF1F8();

void func_80000548(A *a, s32 b) {
    if (func_8013E684(a, a->unk238, -1, 0) != 0) {
        func_80BEF1F8(a, b);
    }
}
