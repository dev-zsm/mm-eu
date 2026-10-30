#include "types.h"
typedef struct { u8 p0[0x1C]; s16 x; } A;
extern void func_800E0FAC();
void func_80002440(A *a, s32 b) {
    if ((a->x & 1) == 1) {
        func_800E0FAC(b, (u8 *)a + 0x144);
    }
}
