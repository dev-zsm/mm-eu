// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_picture.h"

bool BgKin2Picture_IsSkulltulaCollected(PlayState* play, s32 skulltulaParams) {
    s32 flag = -1;

    if ((u8)skulltulaParams & 3) {
        flag = BG_KIN2_PICTURE_GET_3FC(skulltulaParams);
    }

    return (flag >= 0) && Flags_GetTreasure(play, flag);
}
