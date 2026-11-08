// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    u8 pad0[8];
    s8 unk8;
} SfxSetting;

SfxSetting *AudioSfx_AddSfxSetting(s32 arg0);

void AudioSfx_LowerSfxSettingsReverb(struct Vec3f *pos, s8 isReverbLowered) {
    SfxSetting *setting = AudioSfx_AddSfxSetting(pos);

    if (setting != NULL) {
        if (isReverbLowered != 0) {
            setting->unk8 = -0x80;
        } else {
            setting->unk8 = 0;
        }
    }
}
