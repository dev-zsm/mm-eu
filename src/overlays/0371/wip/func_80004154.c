// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_TrackPlayer), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_trt.h"

void func_80004154(EnTrt* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f playerPos;
    Vec3f pos;

    Math_SmoothStepToS(&this->headYaw, this->actor.yawTowardsPlayer - this->actor.shape.rot.y, 4, 0x38E0, 1);
    this->headYaw = CLAMP(this->headYaw, -0x38E0, 0x38E0);

    playerPos = player->actor.world.pos;
    playerPos.y = player->bodyPartsPos[PLAYER_BODYPART_HEAD].y + 3.0f;
    pos = this->actor.world.pos;
    Math_SmoothStepToS(&this->headPitch, Math_Vec3f_Pitch(&pos, &playerPos), 4, 0x1C70, 1);
    this->headPitch = CLAMP(this->headPitch, -0x1C70, 0x1C70);
}
