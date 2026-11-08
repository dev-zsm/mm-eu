// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

u16 Entrance_Create(s32 scene, s32 spawn, s32 layer) {
    return ((scene << 9) | (spawn * 0x10) | layer) & 0xFFFF;
}
