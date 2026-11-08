// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void Play_InitEnvironment(struct PlayState *this, s16 skyboxId) {
    Skybox_Init(this, (u8 *)this + 0x46E0, skyboxId);
    Environment_Init(this, (u8 *)this + 0x17004, 0);
}
