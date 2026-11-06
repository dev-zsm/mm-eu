// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_spiral.h"

s32 ref_func_809A2EA0(DoorSpiral* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (!Player_InCsMode(play)) {
        SpiralInfo* spiralInfo = &sSpiralInfoTable[this->unk148];
        f32 temp_fv0 = ref_func_809A2E08(play, this, 0.0f, spiralInfo->unk_0B, spiralInfo->unk_0C);

        if (fabsf(temp_fv0) < 64.0f) {
            s16 var_v0 = player->actor.shape.rot.y - this->actor.shape.rot.y;

            if (temp_fv0 > 0.0f) {
                var_v0 = 0x8000 - var_v0;
            }
            if (ABS_ALT(var_v0) < 0x3000) {
                return (temp_fv0 >= 0.0f) ? 1.0f : -1.0f;
            }
        }
    }
    return 0;
}
