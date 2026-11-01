#include "types.h"

typedef struct {
    u8 pad0[0x28];
    void (*draw)(void);
    u8 pad2C[0x34];
} EffectSs;

extern EffectSs *D_801AF260;

void EffectSs_Draw(s32 arg0, s32 index) {
    EffectSs *effect = &D_801AF260[index];

    if (effect->draw != 0) {
        effect->draw();
    }
}
