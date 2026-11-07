#include "types.h"

typedef struct { u8 pad0[0x144]; void (*unk144)(); } A;
extern s32 func_8095398C();

void ElfMsg2_Update(A *a, s32 b) {
    if (func_8095398C(a, b) == 0) {
        a->unk144(a, b);
    }
}
