// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct Node { struct Node *next; struct Node *prev; u32 start; u32 end; u32 fill; s32 limit; s32 unk18; } Node;
extern s32 D_80096DE0;
extern s32 D_80096DE4;

void func_80085468(Node *arg0) {
    if (arg0->prev == NULL) {
        if (arg0 == *(Node **)&D_80096DE0) {
            *(Node **)&D_80096DE0 = arg0->next;
        }
    } else {
        arg0->prev->next = arg0->next;
    }
    if (arg0->next == NULL && arg0 == *(Node **)&D_80096DE4) {
        *(Node **)&D_80096DE4 = arg0->prev;
    }
}
