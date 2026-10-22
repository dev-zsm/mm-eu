// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Node {
    u16 unk0;
    u16 unk2;
    u32 unk4;
    void *unk8;
    s32 unkC;
} Node;

extern Node D_80098250;
extern Node D_80098280;
extern Node *D_800982B0;
extern Node *D_800982B4;
extern u8 D_80097780[];
extern u8 D_800981B0[];
extern u8 D_80098200[];
extern s32 D_80000300;

void func_800897D0(void *arg0, s32 arg1);
void func_80091DB0(void *arg0, s32 arg1, u32 arg2);

void func_80091C90(void) {
    s32 t;
    func_800897D0(&D_80098250, 0x60);
    D_800982B0 = &D_80098250;
    D_800982B4 = &D_80098280;
    D_800982B4->unk2 = 1;
    D_800982B0->unk2 = 1;
    D_800982B4->unk4 = 0x80000000;
    D_800982B0->unk4 = 0x80000000;
    t = D_80000300;
    if (t == 0) {
        D_800982B4->unk8 = D_80097780;
    } else if (t == 2) {
        D_800982B4->unk8 = D_80098200;
    } else {
        D_800982B4->unk8 = D_800981B0;
    }
    D_800982B4->unk0 = 0x20;
    D_800982B4->unkC = ((Node *) D_800982B4->unk8)->unk4;
    if (*(volatile u32 *) 0xA4400010 >= 0xB) {
        do {} while (*(volatile u32 *) 0xA4400010 >= 0xB);
    }
    *(u32 *) 0xA4400000 = 0;
    func_80091DB0(&D_800982B4, 1, 0x80000000);
}
