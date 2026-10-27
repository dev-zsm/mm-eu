// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct ListAlloc {
    struct ListAlloc *prev;
    struct ListAlloc *next;
} ListAlloc;

void func_80086EC0(void *ptr);

void ListAlloc_Free(ListAlloc *this, void *data) {
    ListAlloc *node = &((ListAlloc *)data)[-1];

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    if (node == this->prev) {
        this->prev = node->next;
    }
    if (node == this->next) {
        this->next = node->prev;
    }
    func_80086EC0(node);
}
