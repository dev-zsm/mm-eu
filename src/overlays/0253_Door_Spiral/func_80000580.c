// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_spiral.h"

void DoorSpiral_Update(Actor* thisx, PlayState* play) {
    DoorSpiral* this = (DoorSpiral*)thisx;
    Player* player = GET_PLAYER(play);

    if (!(player->stateFlags1 &
          (PLAYER_STATE1_TALKING | PLAYER_STATE1_DEAD | PLAYER_STATE1_400 | PLAYER_STATE1_10000000)) ||
        (this->actionFunc == ref_func_809A2DB0)) {
        this->actionFunc(this, play);
    }
}
