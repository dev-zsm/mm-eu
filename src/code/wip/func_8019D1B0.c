#include "types.h"

extern s8 D_801CF8E8;
extern s32 D_801F4C90;
extern s32 D_801F4C94;

extern void AudioSeq_QueueSeqCmd(s32 a0, s32 a1);
extern void AudioOcarina_ResetAndMute(void);
extern void func_8019BDB0(void);
extern void Audio_SetSfxVolumeExceptSystemAndOcarinaBanks(s32 a0);
extern void func_801A6AE8(s32 a0);

void AudioOcarina_SetInstrument(u8 instrument) {
    if ((instrument != D_801CF8E8) || (instrument == 1)) {
        AudioSeq_QueueSeqCmd(instrument | 0x82010D00, instrument);
        D_801CF8E8 = instrument;
        if (instrument == 0) {
            AudioOcarina_ResetAndMute();
            return;
        }
        D_801F4C90 = 0;
        func_8019BDB0();
        D_801F4C94 = D_801F4C90;
        Audio_SetSfxVolumeExceptSystemAndOcarinaBanks(0x40);
        func_801A6AE8(0xD);
    }
}
