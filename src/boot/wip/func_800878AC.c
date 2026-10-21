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

void func_800878AC(Node **head, u32 *a1, u32 *a2, u32 *a3) {
    Node *node;

    func_800871FC();
    *a1 = 0;
    *a2 = 0;
    *a3 = 0;
    for (node = *head; node != NULL; node = node->next) {
        if (node->flag != 0) {
            *a2 += node->val;
            if (*a1 < node->val) {
                *a1 = node->val;
            }
        } else {
            *a3 += node->val;
        }
    }
    func_80087224();
}
