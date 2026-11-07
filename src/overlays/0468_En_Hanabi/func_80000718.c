// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void EnHanabi_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnHanabi* this = (EnHanabi*)thisx;
    s32 i;

    
    if (1) {}

    Actor_SetScale(thisx, 1.0f);
    this->actionFunc = ref_func_80B23910;
    this->unk_144 = 0;
    ref_func_80B22C00(this->unk_148);

    for (i = 0; i < ARRAY_COUNT(this->unk_4608); i++) {
        Lights_PointNoGlowSetInfo(&this->unk_4608[i], thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, 255,
                                  255, 255, -1);
        this->unk_4634[i] = LightContext_InsertLight(play, &play->lightCtx, &this->unk_4608[i]);
    }

    if (ENHANABI_GET_1F(thisx) == ENHANABI_1F_1) {
        this->actionFunc = ref_func_80B23934;
        this->actor.home.rot.x = 0x384;
    }
}
