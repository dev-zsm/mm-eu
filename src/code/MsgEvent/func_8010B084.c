#include "types.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
} EventInfo;

extern u8 D_801E6EF0[];

s32 MsgEvent_SetEventInf(void *arg0, void *arg1, EventInfo **arg2, s32 arg3) {
    EventInfo *info = *arg2;

    D_801E6EF0[info->unk1 + 0x100C] |= info->unk2;
    return 0;
}
