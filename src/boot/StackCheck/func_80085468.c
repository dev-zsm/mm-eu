// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct Node { struct Node *next; struct Node *prev; u32 start; u32 end; u32 fill; s32 limit; s32 unk18; } Node;
extern Node *D_80096DE0;
extern Node *D_80096DE4;

void StackCheck_Cleanup(Node *e) {
    s32 bad = 0;

    if (e->prev == NULL) {
        if (D_80096DE0 == e) {
            D_80096DE0 = e->next;
        } else {
            bad = 1;
        }
    } else {
        e->prev->next = e->next;
    }
    if (e->next == NULL) {
        if (D_80096DE4 == e) {
            D_80096DE4 = e->prev;
        } else {
            bad = 1;
        }
    }
    if (bad) {
        /* the original reported the inconsistent list here (empty in this build); kept for the register allocation */
    }
}
