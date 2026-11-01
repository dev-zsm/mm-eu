#include "types.h"
#include "generated/code_funcs.h"
u16 Entrance_GetTransitionFlags(u16 a0) {
    return ((u16 *)Entrance_GetTableEntry(a0))[1];
}
