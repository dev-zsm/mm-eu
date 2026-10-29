#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ s8 csId;
} Act;

extern s16 CutsceneManager_GetAdditionalCsId(s16);

s32 SubS_FillCutscenesList(Act *actor, s16 *list, s16 n) {
    s32 i;
    s16 csId;

    for (i = 0; i < n; i++) {
        list[i] = -1;
    }
    i = 0;
    csId = actor->csId;
    while (csId != -1) {
        if (i < n) {
            list[i] = csId;
            csId = CutsceneManager_GetAdditionalCsId(csId);
            i++;
        }
    }
    return i;
}
