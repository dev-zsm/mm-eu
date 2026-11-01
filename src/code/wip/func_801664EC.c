// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 count : 8;
    u32 addr : 24;
} Ovl;

typedef struct {
    union { Ovl w; u8 cnt; } u;
    u8 pad4[8];
    s32 unkC;
} Overlay;

extern s32 Lib_PhysicalToVirtual(s32 a, Overlay *b);
extern void ZeldaArena_Free(s32 a, Overlay *b);
extern s32 Lib_VirtualToPhysical(s32 a);

s32 TransitionOverlay_Free(Overlay *arg0) {
    s32 v;
    s8 c;

    if (arg0->unkC == 0) {
        return 3;
    }
    v = Lib_PhysicalToVirtual(arg0->u.w.addr, arg0);
    if (v != 0) {
        if (arg0->u.cnt != 0) {
            c = arg0->u.cnt - 1;
            arg0->u.cnt = c;
            if (c == 0) {
                ZeldaArena_Free(v, arg0);
                arg0->u.w.addr = Lib_VirtualToPhysical(0);
                return 0;
            }
            return 1;
        }
        return 2;
    }
    return -1;
}
