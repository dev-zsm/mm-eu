// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void Play_GetFloorSurfaceImpl();
void Play_GetFloorSurface(s32 a0, s32 a1, s32 a2) {
    s32 sp24;
    s32 sp20;
    Play_GetFloorSurfaceImpl(a0, a1, &sp24, &sp20, a2);
}
