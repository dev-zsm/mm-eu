// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Node {
    s16 type;
    s16 flag;
    u32 val;
    struct Node *next;
} Node;

extern void func_800871FC(void);
extern void func_80087224(void);

s32 func_8008795C(Node **head) {
    Node *node;
    s32 ret;

    ret = 0;
    func_800871FC();
    node = *head;
    if (node != NULL) {
        do {
            if (node->type != 0x7373) {
                ret = 1;
                break;
            }
            node = node->next;
        } while (node != NULL);
    }
    func_80087224();
    return ret;
}
