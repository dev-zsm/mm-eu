#include "types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} CsMgr;
typedef struct {
    u8 pad[6];
    s16 unk6;
} CsEntry;

extern CsMgr D_801BE3E0;
CsEntry *CutsceneManager_GetCutsceneEntryImpl(s16 a, s16 b);

s16 func_800F1D6C(s16 csId) {
    CsEntry *entry;

    if (csId < 0) {
        return csId;
    }
    entry = CutsceneManager_GetCutsceneEntryImpl(D_801BE3E0.unk0, csId);
    if (D_801BE3E0.unk2 > 0 && entry->unk6 == -1) {
        return -2;
    }
    if (csId != 0x7F && entry->unk6 != -1) {
        return -3;
    }
    if (csId == 0x7F) {
        csId = D_801BE3E0.unk0;
    }
    if (csId == D_801BE3E0.unk0) {
        D_801BE3E0.unk4 = D_801BE3E0.unk0;
        return D_801BE3E0.unk4;
    }
    return -1;
}
