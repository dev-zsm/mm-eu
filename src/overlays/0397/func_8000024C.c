// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_twig.h"

void ref_func_80AC0A7C(EnTwig* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    Math_Vec3f_Copy(&this->unk_180, &player->bodyPartsPos[PLAYER_BODYPART_WAIST]);
    this->unk_178 = 0;
    this->unk_17A = 0;
    this->actionFunc = ref_func_80AC0AC8;
}
