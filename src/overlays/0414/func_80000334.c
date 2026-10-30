#include "types.h"
typedef struct { u8 pad[0x1C]; s16 unk1C; } A;
extern void func_800E0FAC();
void func_80000334(A *a, s32 b) {
    if ((a->unk1C & 0xF) == 5) {
        func_800E0FAC(b, (u8 *)a + 0x1C4);
    }
}
