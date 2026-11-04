#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 unk2;
} Entry;

extern u8 D_801E6EF0[];

s32 MsgEvent_UnsetEventInf(s32 arg0, s32 arg1, Entry **arg2, s32 arg3) {
    Entry *e = *arg2;
    u8 *p = D_801E6EF0 + e->unk1;

    p[0x100C] &= e->unk2 ^ 0xFF;
    return 0;
}
