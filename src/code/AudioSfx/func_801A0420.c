// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[8];
    s8 unk8;
} SfxSetting;

SfxSetting *AudioSfx_AddSfxSetting(s32 arg0);

void AudioSfx_LowerSfxSettingsReverb(s32 arg0, s8 arg1) {
    SfxSetting *setting = AudioSfx_AddSfxSetting(arg0);

    if (setting != NULL) {
        if (arg1 != 0) {
            setting->unk8 = -0x80;
        } else {
            setting->unk8 = 0;
        }
    }
}
