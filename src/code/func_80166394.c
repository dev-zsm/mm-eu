#include "types.h"

extern u32 TransitionOverlay_VramToRam(u32 base, u32 addr);

void TransitionOverlay_VramToRamArray(u32 base, u32 *addrs, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        addrs[i] = TransitionOverlay_VramToRam(base, addrs[i]);
    }
}
