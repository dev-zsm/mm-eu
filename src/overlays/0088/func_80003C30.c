#include "types.h"
extern void func_80181508();
typedef struct { u8 pad0[0x2C8]; s16 v; } A;
s32 func_80003C30(s32 a, s32 b, s32 c, s32 d, s32 e2, A *e) {
    if (b == 0x10) {
        func_80181508(e->v, 1);
    }
    return 0;
}
