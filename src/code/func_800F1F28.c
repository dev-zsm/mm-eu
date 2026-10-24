#include "types.h"

typedef struct {
    char pad0[0xB];
    u8 customValue;
} CutsceneEntry;

CutsceneEntry *CutsceneManager_GetCutsceneEntryImpl(s16 csId);

s32 CutsceneManager_GetCutsceneCustomValue(s16 csId) {
    if (csId < 0) {
        return -1;
    }
    return CutsceneManager_GetCutsceneEntryImpl(csId)->customValue;
}
