#include "types.h"

extern s16 D_801BE3E0;
extern u8 D_801EC690[];

s16 CutsceneManager_IsNext(s16 csId) {
    s32 ret;

    if (csId == 0x7F) {
        if (D_801BE3E0 == -1) {
            return 0x7F;
        }
        return 0;
    }
    if (csId < 0) {
        return -1;
    }
    if (D_801EC690[csId >> 3] & (1 << (csId & 7))) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}
