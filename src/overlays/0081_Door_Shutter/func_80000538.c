// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

s32 ref_func_808A0E28(DoorShutter* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (!Player_InCsMode(play)) {
        ShutterInfo* shutterInfo = &ref_D_808A21B0[this->unk_164];
        f32 temp_f0 = ref_func_808A0D90(play, this, 0.0f, shutterInfo->unk_0A, shutterInfo->unk_0B);

        if (fabsf(temp_f0) < 50.0f) {
            s16 temp_v0_2 = BINANG_SUB(player->actor.shape.rot.y, this->slidingDoor.dyna.actor.shape.rot.y);

            if (temp_f0 > 0.0f) {
                temp_v0_2 = 0x8000 - temp_v0_2;
            }

            if (ABS_ALT(temp_v0_2) < 0x3000) {
                return (temp_f0 >= 0.0f) ? 1.0f : -1.0f;
            }
        }
    }
    return 0;
}
