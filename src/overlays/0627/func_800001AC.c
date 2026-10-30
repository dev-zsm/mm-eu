#include "types.h"
typedef struct { u8 pad[0x194]; u32 x; } A;
extern void func_800BDD44();
extern u8 D_60004B0[];
void func_800001AC(A *a, s32 b) {
    if (!(a->x & 1)) {
        func_800BDD44(b, D_60004B0);
    }
}
