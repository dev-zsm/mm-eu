#include "types.h"
typedef struct { u8 pad[0x2F4]; u8 v; } A;
extern s8 D_80910C98[];
s32 func_80001FF0(s32 a0, s32 a1, s32 *a2, s32 a3, s32 a4, A *a5) {
    if (a5->v != 0 && D_80910C98[a1] > 0) {
        *a2 = 0;
    }
    return 0;
}
