// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { s32 pad0; u8 pad4[0x5A]; u8 type; u8 pad5F; } EffectSs;
typedef struct { EffectSs *table; s32 searchStart; } EffectSsInfo;

extern EffectSsInfo D_801AF260;
extern s32 func_8016B1A4(void);
extern s32 EffectSs_FindSlot(s32 type, s32 *index);

void EffectSs_Insert(void *play, EffectSs *effectSs) {
    s32 index;

    if (func_8016B1A4() != 1) {
        if (EffectSs_FindSlot(effectSs->type, &index) == 0) {
            D_801AF260.searchStart = index + 1;
            D_801AF260.table[index] = *effectSs;
        }
    }
}
