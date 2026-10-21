// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

typedef struct Node {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[4];
    struct Node *unkC;
    u8 pad10[2];
    u16 unk12;
} Node;

extern Node *func_800913B0(void);

void *func_80082B18(void) {
    Node *tmp;
    Node *v1;
    s32 v0;

    tmp = func_800913B0();
    v1 = tmp;
    if (tmp->unk4 != -1) {
        v0 = tmp->unk4;
        do {
            if (v0 > 0 && v0 < 0x7F && (v1->unk12 & 3) != 0) {
                return v1;
            }
            v1 = v1->unkC;
            v0 = v1->unk4;
        } while (v0 != -1);
    }
    return NULL;
}
