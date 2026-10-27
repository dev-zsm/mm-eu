#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 unk14B;
} Struct_8010A65C_B;
typedef struct {
    u8 pad0[0x1CCC];
    Struct_8010A65C_B *unk1CCC;
} Struct_8010A65C;
s32 MsgEvent_CheckDeku(s32 a0, Struct_8010A65C *play, u8 **script, s32 a3) {
    Struct_8010A65C_B *b = play->unk1CCC;
    u8 *cmd = *script;
    s16 offset = cmd[2] | (cmd[1] << 8);
    if (b->unk14B == 3) {
        *script = (*script) + offset;
    }
    return 0;
}
