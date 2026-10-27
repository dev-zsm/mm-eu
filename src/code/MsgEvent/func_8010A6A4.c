#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 unk14B;
} Unk14B;
typedef struct {
    u8 pad0[0x1CCC];
    Unk14B *unk1CCC;
} Play;
s32 MsgEvent_CheckHuman(s16 a0, Play *play, u8 **msgPtr, s16 offset) {
    Unk14B *player = play->unk1CCC;
    int new_var;
    u8 *msg = *msgPtr;
    int new_var2;
    u8 new_var3;
    int new_var4;
    new_var2 = 1;
    offset = msg[2] | (msg[new_var2] << 8);
    new_var = 4; if (player->unk14B == new_var) {
        *msgPtr = (*msgPtr) + offset;
    }
    return 0;
    offset = (((((((new_var4 = (((new_var3 = msg[new_var2]) << 8) | msg[2]) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF;
}
