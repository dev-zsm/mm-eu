#include "types.h"

typedef struct {
    u8 b[0x10];
} CutsceneEntry;

extern CutsceneEntry D_801BE360[];
extern CutsceneEntry *D_801EC670;

CutsceneEntry *CutsceneManager_GetCutsceneEntryImpl(s16 csId) {
    if (csId < 0x78) {
        return &D_801EC670[csId];
    }
    csId -= 0x78;
    return &D_801BE360[csId];
}
