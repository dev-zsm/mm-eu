// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/overlays/0440.h"
extern u8 D_80AD7080;
void func_80AD555C();
void EnTest7_WarpCsWait(EnTest7 *this, PlayState *play) {
    if (*(s32 *)((u8 *)this + 0x1E54) >= 0x82) {
        func_80AD555C(this, &D_80AD7080);
    }
}
