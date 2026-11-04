// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_takaraya_wall.h"

void ObjTakarayaWall_Destroy(Actor* thisx, PlayState* play) {
    ObjTakarayaWall* this = (ObjTakarayaWall*)thisx;
    s32 i;
    s32 j;

    Collider_DestroyCylinder(play, &this->columnCollider);
    Collider_DestroyCylinder(play, &this->rowCollider);

    for (i = 0; i < TAKARAYA_WALL_ROWS; i++) {
        for (j = 0; j < TAKARAYA_WALL_COLUMNS; j++) {
            AudioSfx_StopByPos(&sTakarayaWallAudioPositions[i][j]);
        }
    }
}
