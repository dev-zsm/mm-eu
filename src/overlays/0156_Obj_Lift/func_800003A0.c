#include "types.h"
extern u8 D_80922290[];
extern u8 D_80922750[];
extern s16 D_80922840[];
typedef struct { u8 pad0[0x1C]; s16 x1C; u8 pad1[0x13C - 0x1E]; void *x13C; u8 pad2[0x15C - 0x140]; void *x15C; u8 pad3[6]; s16 x166; } A;
void func_800003A0(A *a0) {
    a0->x166 = D_80922840[(a0->x1C >> 8) & 7];
    a0->x15C = D_80922290;
    a0->x13C = D_80922750;
}
