// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x18];
    s32 fwd_queue; /* OSMesgQueue to forward to, or 0 */
    s32 fwd_msg;
} Node;

extern u8 D_8009B690[];

void osRecvMesg(void *a, Node **out, s32 c);
void DmaMgr_ProcessRequest(Node *node);
void osSendMesg(s32 a, s32 b, s32 c);

// Message loop on queue D_8009B690: blocking receive (likely osRecvMesg), handle each
// node with DmaMgr_ProcessRequest, and if fwd_queue is set, forward fwd_msg to it (likely
// osSendMesg, non-blocking). Loops forever; the NULL check is a defensive break.
void DmaMgr_ThreadEntry(s32 unused) {
    Node *node;
    Node *p;

    for (;;) {
        osRecvMesg(D_8009B690, &node, 1);
        if (node == NULL) {
            break;
        }
        p = node;
        DmaMgr_ProcessRequest(p);
        if (p->fwd_queue != 0) {
            osSendMesg(p->fwd_queue, p->fwd_msg, 0);
        }
    }
}
