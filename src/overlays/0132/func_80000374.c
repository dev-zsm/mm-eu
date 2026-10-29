#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
} Ovl0132Actor;

extern void func_800B6564();
extern s32 D_808FD340[];

void func_80000374(Ovl0132Actor *a, s32 b) {
    func_800B6564(a, D_808FD340[a->unk1C & 0xF]);
}
