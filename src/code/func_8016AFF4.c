#include "types.h"

typedef struct {
    u8 pad0[0x24];
    u8 unk24[0x9A];
    s16 unkBE;
} PlayerData;

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
    u8 padA6[0x1C26];
    PlayerData *unk1CCC;
} PlayState;

extern s32 D_801E6EF0;
extern void func_8016AF54(PlayState *play, s32 arg1, s32 arg2, s8 arg3, s32 arg4, void *arg5, s16 arg6);

void func_8016AFF4(PlayState *play, s32 arg1, s32 arg2) {
    PlayerData *player = play->unk1CCC;
    s32 value; // only here to make the compiler schedule the D_801E6EF0 load like the ROM

    if (play->unkA4 != 7) {
        func_8016AF54(play, arg1, (value = D_801E6EF0) & 0xFFFF, *((s8 *)play + 0x186E0), arg2, player->unk24, player->unkBE);
    }
}
