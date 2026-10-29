#include "types.h"

typedef struct {
    /* 0x00 */ u32 count : 8;
    /* 0x00 */ u32 addr : 24;
    /* 0x04 */ u32 start;
    /* 0x08 */ u32 end;
    /* 0x0C */ void *loadedRamAddr;
    /* 0x10 */ void *vramStart;
} Ovl;

extern s32 Lib_PhysicalToVirtual();
extern s32 ZeldaArena_Malloc();
extern void func_80085074();
extern u32 Lib_VirtualToPhysical();

s32 TransitionOverlay_Load(Ovl *o) {
    s32 v;
    s32 addr;

    if (o->loadedRamAddr == NULL) {
        return 3;
    }
    if (Lib_PhysicalToVirtual(o->addr) == 0) {
        addr = ZeldaArena_Malloc(o->end - o->start);
        if (addr == 0) {
            return -1;
        }
        func_80085074(o->loadedRamAddr, o->vramStart, o->start, o->end, addr);
        o->addr = Lib_VirtualToPhysical(addr);
        o->count = 1;
        return 0;
    }
    v = o->count;
    if (v != 0) {
        v = v + 1;
        o->count = v;
        if (v == 0) {
            return 2;
        }
        return 1;
    }
    return 2;
}
