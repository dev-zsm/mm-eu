#include "types.h"
u16 SSNodeList_GetNextNodeIdx(u16 *a0) { u16 v = a0[1]; a0[1] = v + 1; return v; }
