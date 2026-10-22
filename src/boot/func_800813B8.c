// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
    void *data;
} Node;

typedef struct Obj {
    u8 pad0[0x248];
    Node *list;
} Obj;

extern void osSendMesg(void *a, u32 b, u32 c);

void IrqMgr_SendMesgToClients(Obj *arg0, u32 arg1) {
    Node *n;

    n = arg0->list;
    if (n != NULL) {
        do {
            osSendMesg(n->data, arg1, 0);
            n = n->next;
        } while (n != NULL);
    }
}
