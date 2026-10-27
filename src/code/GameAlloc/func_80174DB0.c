// FLAGS: -O2 -g0 -mips2
#include "types.h"
void GameAlloc_Log(void *a0) { void *v = *(void **)a0; while (a0 != v) v = *(void **)v; }
