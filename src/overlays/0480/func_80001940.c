#include "types.h"
extern void func_80181D88();
typedef struct { u8 pad[0x2E8]; s16 x2E8; } A;
s32 func_80001940(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, A *a5) {
    if (a1 == 2) {
        func_80181D88(a5->x2E8, 1);
    }
    return 0;
}
