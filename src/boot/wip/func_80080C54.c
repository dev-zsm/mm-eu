// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 pad0C[8];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Node;

extern s32 D_80096D00;
extern u8 D_8009B690[];

void osSendMesg(void *a, void *b, s32 c);

s32 DmaMgr_RequestAsync(Node *p, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    if (D_80096D00 >= 2) {
        p->unk0 = a2;
        return -2;
    }
    p->unk0 = a2;
    p->unk4 = a1;
    p->unk8 = a3;
    p->unk14 = 0;
    p->unk18 = a5;
    p->unk1C = a6;
    osSendMesg(D_8009B690, p, 1);
    return 0;
}
