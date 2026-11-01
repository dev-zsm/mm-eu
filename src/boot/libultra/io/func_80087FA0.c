// FLAGS: -O2 -g0
#include "sdk/os_vi.h"

void osViExtendVStart(s32 value) {
    D_800983BC = value;
}
