#include "types.h"

typedef struct Node {
    u8 *data;
    s32 pad4;
    struct Node *next;
} Node;

extern void (*D_801BF600[])();
extern void (*D_801BF60C[])();

void Lights_BindAll(u8 *a0, Node *a1, s32 a2, s32 a3) {
    if (a1 != NULL) {
        if (a2 == 0 && *a0 == 1) {
            do {
                D_801BF600[*a1->data](a0, a1->data + 2, a3);
                a1 = a1->next;
            } while (a1 != NULL);
            return;
        }
        do {
            D_801BF60C[*a1->data](a0, a1->data + 2, a2);
            a1 = a1->next;
        } while (a1 != NULL);
    }
}
