#include "types.h"
extern s32 func_8013E684();
extern void func_80BFD664();
typedef struct { u8 pad0[0x23A]; s16 v; } A;
void func_80000644(A *a, s32 b) {
    if (func_8013E684(a, a->v, -1, 0) != 0) {
        func_80BFD664(a, b);
    }
}
