#include "types.h"
#include "m2c_compat.h"
s32 func_800DFA9C(u8 *a);

void func_80002BB0(u8 *a, u8 *play) {
    M2C_FIELD(a, s16 *, 0xBE) = func_800DFA9C(((u8 **)(play + 0x800))[M2C_FIELD(play, s16 *, 0x810)]) + 0x8000;
    M2C_FIELD(a, void (**)(u8 *, u8 *), 0x200)(a, play);
}
