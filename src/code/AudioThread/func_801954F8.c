// FLAGS: -O2 -g0 -mips2
// sRandom/sPrevCount are function statics in the original source, so the object carries its own .data
#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x28C0];
    /* 0x28C0 */ u32 unk28C0;
    /* 0x28C4 */ u8 pad28C4[0xD8];
    /* 0x299C */ u32 unk299C;
} AudioContext;

extern u32 func_8008D460(void);
extern AudioContext D_801F84B0;

u32 AudioThread_NextRandom(void) {
    static u32 D_801CE92C = 0x12345678;
    static u32 D_801CE930 = 0x11111111;
    u32 count = func_8008D460();

    D_801CE92C = (D_801F84B0.unk28C0 + D_801CE92C + count) * (D_801F84B0.unk299C + 0x1234567);
    D_801CE92C = (D_801CE92C & 1) + (D_801CE92C * 2) + D_801CE930;
    D_801CE930 = count;
    return D_801CE92C;
}
