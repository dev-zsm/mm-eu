#include "types.h"
extern s32 D_80A506F4;
typedef struct { u8 pad[0x30C]; s32 flags; } A;
void func_8000039C(A *a) {
    if (!(a->flags & 0x100)) {
        a->flags |= 0x100;
        D_80A506F4 += 1;
    }
}
