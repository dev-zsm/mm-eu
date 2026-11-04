// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_step.h"

void ObjTokeiStep_SpawnDust(ObjTokeiStep* this, ObjTokeiStepPanel* panel, PlayState* play) {
    s32 i;
    s32 pad;
    Vec3f dustSpawnOffset;
    Vec3f dustSpawnPos;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);

    dustSpawnOffset.y = 115.0f;
    dustSpawnOffset.z = -10.0f;
    for (i = 0; i < 7; i++) {
        dustSpawnOffset.x = sDustSpawnXOffsets[i];
        Matrix_MultVec3f(&dustSpawnOffset, &dustSpawnPos);
        dustSpawnPos.x += panel->pos.x;
        dustSpawnPos.y += panel->pos.y;
        dustSpawnPos.z += panel->pos.z;
        ref_func_800B1210(play, &dustSpawnPos, &gZeroVec3f, &sDustEffectAccel, (s32)((Rand_ZeroOne() * 40.0f) + 80.0f),
                      (s32)((Rand_ZeroOne() * 20.0f) + 50.0f));
    }
}
