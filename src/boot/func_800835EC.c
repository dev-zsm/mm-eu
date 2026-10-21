// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct Node800835EC {
    struct Node800835EC *next;
    void (*fn)(s32, s32);
    s32 unk8;
    s32 unkC;
} Node800835EC;

extern void func_80082138(void);
extern void func_800843FC(s32 a0, s32 a1);
extern void func_8008482C(void *a0, s32 a1, Node800835EC *a2, s32 a3, s32 sp10);
extern void func_8008209C(void);
extern void func_8008352C(void);
extern u8 D_80098CB0[];
extern void *D_8009C220;

void func_800835EC(void) {
    Node800835EC *node;
    s32 i;

    i = 0;
    node = *(Node800835EC **)((u8 *)D_8009C220 + 0x7D8);
    while (node != NULL) {
        if (node->fn != NULL) {
            func_80082138();
            func_800843FC(-2, 0);
            func_8008482C(D_80098CB0, i++, node, node->unk8, node->unkC);
            func_800843FC(0, 0);
            node->fn(node->unk8, node->unkC);
            func_8008209C();
            func_8008352C();
        }
        node = node->next;
    }
}
