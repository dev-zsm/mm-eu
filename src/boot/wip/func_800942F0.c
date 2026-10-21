// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct BootNode {
    struct BootNode *next;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} BootNode;

extern BootNode *D_80098160;
extern u32 D_8009E990;

s32 func_80091C00(void);
void func_80091C70(s32 a);
u32 func_8008D460(void);
u64 func_8008F7E4(BootNode *p);
void func_8008F744(u32 hi, u32 lo);

s32 func_800942F0(BootNode *node, u64 a, u32 a4, u32 a5, u32 a6, u32 a7) {
    u64 sp30;
    BootNode *q;
    u32 now;
    u32 delta;
    s32 sp20;
    u64 *p;

    node->next = NULL;
    node->unk4 = 0;
    node->unkC = a5;
    node->unk8 = a4;
    if (a != 0) {
        *(u64 *)&node->unk10 = a;
    } else {
        node->unk10 = a4;
        node->unk14 = a5;
    }
    node->unk18 = a6;
    node->unk1C = a7;
    sp20 = func_80091C00();
    if (D_80098160->next != D_80098160) {
        q = D_80098160->next;
        now = func_8008D460();
        delta = now - D_8009E990;
        if (*(u64 *)&q->unk10 > (u64)delta) {
            p = (u64 *)&q->unk10;
            *p -= (u64)delta;
        } else {
            *(u64 *)&q->unk10 = 1;
        }
    }
    sp30 = func_8008F7E4(node);
    func_8008F744(D_80098160->next->unk10, D_80098160->next->unk14);
    func_80091C70(sp20);
    return 0;
}
