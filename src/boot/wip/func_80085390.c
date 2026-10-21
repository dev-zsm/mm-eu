// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;  /* 0x00 */
    struct Node *prev;  /* 0x04 */
    u32 start;          /* 0x08 */
    u32 end;            /* 0x0C */
    u32 fill;           /* 0x10 */
    s32 limit;          /* 0x14 */
    s32 unk18;          /* 0x18 */
} Node;

extern s32 D_80096DE0;
extern s32 D_80096DE4;

void func_80085390(Node *arg0, u32 arg1, u32 arg2, u32 arg3, s32 arg4, s32 arg5) {
    Node *v0;
    Node *tail;
    u32 p;

    if (arg0 == NULL) {
        *(Node **)&D_80096DE0 = NULL;
        return;
    }
    arg0->start = arg1;
    arg0->end = arg2;
    arg0->fill = arg3;
    arg0->limit = arg4;
    arg0->unk18 = arg5;
    v0 = *(Node **)&D_80096DE0;
    if (v0 != NULL) {
        do {
            if (v0 == arg0) {
                return;
            }
            v0 = v0->next;
        } while (v0 != NULL);
    }
    arg0->next = NULL;
    arg0->prev = *(Node **)&D_80096DE4;
    if (*(Node **)&D_80096DE4 != NULL) {
        (*(Node **)&D_80096DE4)->next = arg0;
    }
    *(Node **)&D_80096DE4 = arg0;
    if (*(Node **)&D_80096DE0 == NULL) {
        *(Node **)&D_80096DE0 = arg0;
    }
    if (arg0->limit != -1) {
        p = arg0->start;
        if (p < arg0->end) {
            do {
                p += 4;
                *(u32 *)(p - 4) = arg0->fill;
            } while (p < arg0->end);
        }
    }
}
