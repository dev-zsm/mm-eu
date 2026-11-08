#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0607.h"
void func_80BD86C0(void *p, s32 b);

void func_80000480(Actor *thisx, PlayState *play) {
    func_80BD86C0((u8 *)thisx + 0x34C, play);
}
