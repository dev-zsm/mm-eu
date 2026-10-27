// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct {
    u32 enabled : 1;
    u32 finished : 1;
    u32 pad : 30;
    
    u8 seqId;
    u8 fontId;
    u8 pad6[0x9C - 6];
    u8 notePool[1];
} SeqPlayer;
typedef struct {
    u8 pad0[0x2C34];
    s32 unk2C34;
    u8 pad2C38[0x2C52 - 0x2C38];
    s16 unk2C52;
    u8 pad2C54[0x2C5E - 0x2C54];
    s16 unk2C5E;
} AudioCtx;
extern AudioCtx D_801F84B0;
extern void AudioScript_SequencePlayerDisableChannels(SeqPlayer *p, u16 a);
extern void AudioList_ClearNotePool(void *p);
extern s32 AudioLoad_IsSeqLoadComplete(s32 id);
extern s32 AudioLoad_IsFontLoadComplete(s32 id);
extern void AudioLoad_SetSeqLoadStatus(s32 id, s32 s);
extern void AudioLoad_SetFontLoadStatus(s32 id, s32 s);
void AudioScript_SequencePlayerDisable(SeqPlayer *seqPlayer) {
    AudioScript_SequencePlayerDisableChannels(seqPlayer, 0xFFFF);
    AudioList_ClearNotePool(seqPlayer->notePool);
    if (seqPlayer->enabled) {
        seqPlayer->enabled = 0;
        seqPlayer->finished = 1;
        if (AudioLoad_IsSeqLoadComplete(seqPlayer->seqId)) {
            AudioLoad_SetSeqLoadStatus(seqPlayer->seqId, 3);
        }
        if (AudioLoad_IsFontLoadComplete(seqPlayer->fontId)) {
            AudioLoad_SetFontLoadStatus(seqPlayer->fontId, 4);
        }
        if (D_801F84B0.unk2C52 == seqPlayer->fontId) {
            D_801F84B0.unk2C34 = 1;
            return;
        }
        if (D_801F84B0.unk2C5E == seqPlayer->fontId) {
            D_801F84B0.unk2C34 = 0;
        }
    }
}
