// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    u32 unk8;
    u32 unkC;
    u32 hi;
    u32 lo;
    u32 unk18;
    u32 unk1C;
} Node;

extern Node *D_80098160;
extern s32 D_8009E980;
extern s32 D_8009E984;
extern s32 D_8009E988;
extern s32 D_8009E98C;

void func_8008F540(void) {
    D_8009E984 = 0;
    D_8009E980 = 0;
    D_80098160->prev = D_80098160;
    D_8009E988 = 0;
    D_8009E98C = 0;
    D_80098160->next = D_80098160->prev;
    D_80098160->hi = 0;
    D_80098160->lo = 0;
    D_80098160->unk8 = D_80098160->hi;
    D_80098160->unkC = D_80098160->lo;
    D_80098160->unk18 = 0;
    D_80098160->unk1C = 0;
}
