#include "types.h"
extern u32 D_801EFA18;
typedef struct { u32 x; u8 pad[0x40]; } X;
typedef struct { u8 pad[0x17D98]; X arr[1]; } G;
typedef struct { u8 pad[0x1EC]; s8 i; } A;
void func_80002B8C(A *a0, G *a1) {
    D_801EFA18 = a1->arr[a0->i].x + 0x80000000;
}
