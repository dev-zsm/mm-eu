// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0328.h"

typedef struct E {
    /* 0x0 */ void (*unk0)(s32, s32);
    /* 0x4 */ s32 unk4;
} E;

extern E D_80A263DC[];
void func_80A23530();

s32 func_8000002C(s32 arg0, s32 arg1, s32 arg2) {
    E *e = &D_80A263DC[arg2];

    e->unk0(arg0, arg1);
    if (e->unk4 == 0) {
        return 0;
    }
    func_80A23530(arg0, e->unk4);
    return 1;
}
