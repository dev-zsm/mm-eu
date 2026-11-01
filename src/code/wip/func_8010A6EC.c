#include "types.h"

typedef struct {
    /* 0x00000 */ u8 pad0[0x1692D];
    /* 0x1692D */ u8 unk1692D;
} Struct_8010A6EC;

s32 MsgEvent_CheckTextChoice(s32 arg0, Struct_8010A6EC *arg1, u8 **arg2, s32 arg3) {
    s16 offset;
    s32 script;
    u8 *cur;
    u8 type;

    type = arg1->unk1692D;
    script = (s32)*arg2;
    offset = 0;
    cur = (u8 *)script;
    switch (type) {
    case 0:
        offset = (cur[2]) | (cur[1] << 8);
        break;
    case 1:
        offset = (cur[4]) | (cur[3] << 8);
        break;
    case 2:
        offset = (cur[6]) | (cur[5] << 8);
        break;
    }
    *arg2 = (u8 *)(script + offset);
    return 0;
}
