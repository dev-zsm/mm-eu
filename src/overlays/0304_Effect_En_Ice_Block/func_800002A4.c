// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0304.h"
void func_80A07A70();
void EffectEnIceBlock_Update(PlayState *play, u32 index, void *this) {
    *(s16 *)((u8 *)this + 0x44) = *(s16 *)((u8 *)this + 0x46) + *(s16 *)((u8 *)this + 0x44);
    func_80A07A70(this, play);
}
