#include "types.h"

typedef struct {
    u8 pad0[0xC];
    u16 unkC;
} Ovl0056Sub;

typedef struct {
    u8 pad0[0x1887C];
    s8 unk1887C;
} Ovl0056Obj2;

extern Ovl0056Sub *D_80862264;

s32 func_8000350C(Ovl0056Obj2 *a) {
    return a->unk1887C > 0 && (~(D_80862264->unkC | -0x4001)) == 0;
}
