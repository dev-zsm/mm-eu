#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 numSamplesMode;
    u8 pad5[0x18 - 5];
    u8 useResampling;
} ReverbState;

extern u32 *AudioSynth_LoadDownsampledReverbSamples(u32 *cmd);
extern u32 *AudioSynth_LoadResampledReverbSamples(void);
extern u32 *AudioSynth_LoadDefaultReverbSamples(u32 *cmd);

u32 *AudioSynth_LoadReverbSamples(u32 *cmd, s32 arg1, ReverbState *reverb, s16 arg3) {
    if (reverb->numSamplesMode == 1) {
        if (reverb->useResampling) {
            cmd = AudioSynth_LoadResampledReverbSamples();
        } else {
            cmd = AudioSynth_LoadDefaultReverbSamples(cmd);
        }
    } else {
        cmd = AudioSynth_LoadDownsampledReverbSamples(cmd);
    }
    return cmd;
}
