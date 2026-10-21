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

extern Node *D_80096DE0;

s32 func_800854D8(Node *arg0);

s32 func_80085550(void) {
    Node *n;
    s32 found;

    n = D_80096DE0;
    found = 0;
    if (n != NULL) {
        do {
            if (func_800854D8(n) != 0) {
                found = 1;
            }
            n = n->next;
        } while (n != NULL);
    }
    return found;
}
