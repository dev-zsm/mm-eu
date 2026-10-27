#include "types.h"

void Flags_SetSwitch(u8 *play, s32 flag) {
    if ((flag >= 0) && (flag < 0x80)) {
        *(u32 *)(play + 0x1E58 + ((flag & ~0x1F) >> 5) * 4) |= 1 << (flag & 0x1F);
    }
}
