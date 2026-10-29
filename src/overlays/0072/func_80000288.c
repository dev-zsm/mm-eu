#include "types.h"

typedef struct {
    u8 pad0[0x2A2];
    s16 unk2A2;
    u8 pad2A4[0x6C];
    u8 unk310;
} Ovl0072Actor;

extern void func_800E0FAC();

void func_80000288(Ovl0072Actor *a, s32 b) {
    if (a->unk2A2 == 0) {
        func_800E0FAC(b, &a->unk310);
    }
}
