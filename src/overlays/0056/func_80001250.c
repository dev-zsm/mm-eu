#include "types.h"
typedef struct { u8 pad[0x384]; s16 unk384; u8 pad386[0x7A4]; s8 unkB2A; } A;
extern u8 D_8085BAE4[];
void func_80001250(A *a) {
    s8 *p = (s8 *)(a->unk384 * 6 - 6 + (s32)D_8085BAE4);
    s8 t = p[2];
    if (t < 0) {
        a->unkB2A = -t;
        return;
    }
    a->unkB2A = t;
}
