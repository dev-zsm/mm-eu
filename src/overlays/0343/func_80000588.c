#include "types.h"

typedef struct {
    u8 pad0[0x260];
    s32 unk260[1];
} Obj343;

s32 func_80000588(s32 a0, s32 a1, s32 *a2, s32 a3, s32 a4, Obj343 *a5) {
    a5->unk260[a1] = *a2;
    *a2 = 0;
    return 0;
}
