#include "types.h"
typedef struct { void *a; void *b; } ListAlloc;
void *ListAlloc_Init(ListAlloc *p) { p->a = 0; p->b = 0; return p; }
