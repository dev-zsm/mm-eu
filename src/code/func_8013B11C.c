#include "types.h"
extern s32 Play_InCsMode();
s32 SubS_InCsMode(void) {
    s32 r = 0;
    if (Play_InCsMode()) {
        r = 1;
    }
    return r;
}
