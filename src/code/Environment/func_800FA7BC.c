#include "types.h"

typedef struct { u8 pad[0x14C]; s16 flags; } Cam;
typedef struct {
    u8 pad0[0x800];
    Cam *cams[4];
    s16 camId;
    u8 pad812[0x170F8 - 0x812];
    u8 unk170F8;
    u8 unk170F9;
    u8 unk170FA;
} PlayState;

void Environment_DrawRainImpl(PlayState *play, s32 a1, s32 a2);
s32 Environment_GetStormState(PlayState *play);

void func_800FA7BC(PlayState *play, s32 a1, s32 a2) {
    if (!(play->cams[play->camId]->flags & 0x100) && (play->unk170F8 == 0)) {
        if (play->unk170FA != 0) {
            if (play->unk170F8 == 0) {
                Environment_DrawRainImpl(play, a1, a2);
            }
        } else if (!(play->cams[play->camId]->flags & 0x100)) {
            if (Environment_GetStormState(play) != 0) {
                if (play->unk170F8 == 0) {
                    Environment_DrawRainImpl(play, a1, a2);
                }
            }
        }
    }
}
