#include "types.h"
typedef struct { u8 pad0[0x14F]; u8 i; u8 pad1[0xB64-0x150]; u8 f; } A;
extern s32 D_8085B5A4[];
extern s32 D_8085B5BC[];
s32 func_80001450(A *a) {
    if (a->f != 0) {
        return D_8085B5BC[a->i];
    }
    return D_8085B5A4[a->i];
}
