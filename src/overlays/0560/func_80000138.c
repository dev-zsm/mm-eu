#include "types.h"
typedef struct { u8 pad[0x1C]; s16 x; } A;
extern void func_800E0FAC();
void func_80000138(A *a, s32 b) {
    if (a->x != 2) {
        func_800E0FAC(b, (u8 *)a + 0x278);
    }
}
