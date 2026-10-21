// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x18];
    s32 fwd_queue; /* OSMesgQueue to forward to, or 0 */
    s32 fwd_msg;
} Node;

extern u8 D_8009B690[];

void func_80088070(void *a, Node **out, s32 c);
void func_80080A58(Node *node);
void func_80087CB0(s32 a, s32 b, s32 c);

// Message loop on queue D_8009B690: blocking receive (likely osRecvMesg), handle each
// node with func_80080A58, and if fwd_queue is set, forward fwd_msg to it (likely
// osSendMesg, non-blocking). Loops forever; the NULL check is a defensive break.
void func_80080BD4(s32 unused) {
    Node *node;
    Node *p;

    for (;;) {
        func_80088070(D_8009B690, &node, 1);
        if (node == NULL) {
            break;
        }
        p = node;
        func_80080A58(p);
        if (p->fwd_queue != 0) {
            func_80087CB0(p->fwd_queue, p->fwd_msg, 0);
        }
    }
}
