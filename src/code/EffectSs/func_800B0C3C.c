#include "types.h"

typedef struct {
    u8 pad[0x5C];
    s16 life;
    u8 pad5E[2];
} EffectSs;
typedef struct {
    EffectSs *table;
    s32 searchStartIndex;
    s32 tableSize;
} EffectSsInfo;

extern EffectSsInfo D_801AF260;
void EffectSs_Delete(EffectSs *ss);
void EffectSs_Update(s32 play, s32 index);

void EffectSs_UpdateAll(s32 play) {
    s32 i;

    for (i = 0; i < D_801AF260.tableSize; i++) {
        if (D_801AF260.table[i].life > -1) {
            D_801AF260.table[i].life--;
            if (D_801AF260.table[i].life < 0) {
                EffectSs_Delete(&D_801AF260.table[i]);
            }
        }
        if (D_801AF260.table[i].life > -1) {
            EffectSs_Update(play, i);
        }
    }
}
