#include "types.h"
typedef struct { u8 p0[0x34C]; s32 u34C; } A;
extern s32 D_80A506F4;
s32 func_80000400(A *a) {
    return D_80A506F4 >= 4 && a->u34C == 0;
}
