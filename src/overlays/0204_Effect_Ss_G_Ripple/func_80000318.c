#include "types.h"
#include "generated/overlays/0204.h"

extern void func_8095E978();
extern u8 D_40367B0;

void EffectSsGRipple_Draw(PlayState *play, u32 index, void *this) {
    if (*(s16 *)((u8 *)this + 0x56) == 0) {
        func_8095E978(play, this, &D_40367B0);
    }
}
