#include "types.h"

typedef struct {
    u8 pad0[0x1A4];
    void *unk1A4;
} S;

extern void func_809235A0();
extern u8 D_80926CFC[];

void func_80003940(S *s) {
    s->unk1A4 = D_80926CFC;
    func_809235A0(s, 0);
}
