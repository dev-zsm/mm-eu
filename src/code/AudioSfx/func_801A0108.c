// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 id;
    u8 pad[8];
} SfxSetting;

extern SfxSetting D_801F4A30[8];
extern u8 D_801F4A90;

SfxSetting *AudioSfx_AddSfxSetting(s32 arg0) {
    SfxSetting *s;
    u8 i = 0;
    u8 free = 0xFF;

    for (; i < 8; i++) {
        s = &D_801F4A30[i];
        if (s->id == 0 && free == 0xFF) {
            free = i;
        }
        if (s->id == arg0) {
            return s;
        }
    }
    if (free != 0xFF) {
        D_801F4A90 |= 1 << free;
        s = &D_801F4A30[free];
        s->id = arg0;
        return s;
    }
    return 0;
}
