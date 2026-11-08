// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0374.h"

typedef struct G {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ u8 pad4[0x3DD0];
    /* 0x3DD4 */ u8 unk3DD4;
} G;

extern G D_801E6EF0;
void func_800E0FAC();

void func_80000A34(s32 arg0, s32 arg1) {
    if (D_801E6EF0.unk0 != 0x8E10) {
        D_801E6EF0.unk3DD4 = 5;
    }
    func_800E0FAC(arg1, arg0 + 0x18C, arg0);
}
