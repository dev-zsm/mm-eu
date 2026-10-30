#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 unk1C; } A;
typedef struct { u8 pad0[0x1F34]; u16 unk1F34; } G;
void func_800B8C4C();
void func_80000320(A *a0, G *a1) {
    if (a0->unk1C == 0) {
        if (a1->unk1F34 == 0x14) {
            func_800B8C4C(a0, 0x281B);
        }
    }
}
