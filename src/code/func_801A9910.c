#include "types.h"

typedef struct {
    u8 pad0[0x1FC];
    u32 unk1FC;
    u8 pad200[0xA];
    u16 unk20A;
    u8 pad20C[4];
    u8 unk210;
    u8 pad211[0xB];
} SeqPlayer;

extern SeqPlayer D_801F7980[];

u16 AudioSeq_GetActiveSeqId(u8 playerIndex) {
    SeqPlayer *player = &D_801F7980[playerIndex];

    if (player->unk210 == 1) {
        return player->unk1FC & 0xFF;
    }
    if (player->unk20A != 0xFFFF) {
        return player->unk20A;
    }
    return 0xFFFF;
}
