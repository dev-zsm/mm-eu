#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x11A];
    /* 0x11A */ u16 unk11A;
    /* 0x11C */ u8 unk11C;
} Struct_800BC8F4;

extern void Actor_PlaySfx(void *, u16);

void Actor_SetColorFilter(Struct_800BC8F4 *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4) {
    if ((arg1 == 0x8000) && !(arg2 & 0x8000)) {
        Actor_PlaySfx(arg0, 0x3836);
    }
    arg0->unk11A = arg1 | arg3 | ((arg2 & 0xF8) << 5) | arg4;
    arg0->unk11C = arg4;
}
