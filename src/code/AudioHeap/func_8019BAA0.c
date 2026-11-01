// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    u8 flags;
    u8 pad1[0x10];
    u8 index;
    u8 pad12[0x3E];
    void *unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
} Chan;
typedef struct {
    u8 pad0[0x38];
    Chan *chan[16];
    u8 pad78[0x160 - 0x78];
} SeqPlayer;
extern u8 D_801F84B0[];
extern u8 D_801FAEA0[];
extern Chan D_801FFCF0;
Chan *AudioHeap_AllocZeroed(void *a, s32 b);
void func_8019BAA0(s32 playerIdx) {
    SeqPlayer *player = &((SeqPlayer *) (D_801F84B0 + 0x4460))[playerIdx];
    s32 i;
    Chan *chan;
    for (i = 0; i < 16; i++) {
        player->chan[i] = AudioHeap_AllocZeroed(D_801FAEA0, 0xE4);
        if (player->chan[i] == ((void *) 0)) {
            player->chan[i] = &D_801FFCF0;
        } else {
            chan = player->chan[i];
            player->chan[i]->unk50 = player;
            chan->index = i;
            chan->flags &= 0xFF7F;
            chan->unk58 = 0;
            chan->unk5C = 0;
            chan->unk60 = 0;
            chan->unk54 = 0;
        }
        AudioScript_InitSequenceChannel(player->chan[i]);
    }

}
