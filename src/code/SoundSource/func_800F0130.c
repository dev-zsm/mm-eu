#include "types.h"

typedef struct {
    u8 unk0;
    u8 pad1[0x1B];
} SoundSource;
void SoundSource_InitAll(u8 *arg0) {
    SoundSource *s = (SoundSource *) (arg0 + 0x1F78);
    s32 i;
    for (i = 0; i < 16; i++) { s[i].unk0 = 0;
    }

}
