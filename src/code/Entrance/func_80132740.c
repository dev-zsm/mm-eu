#include "types.h"
void *Entrance_GetTableEntry(u16);
u16 Entrance_GetTransitionFlags(u16 a0) {
    return ((u16 *)Entrance_GetTableEntry(a0))[1];
}
