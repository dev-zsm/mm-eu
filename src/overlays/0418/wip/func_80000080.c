// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_GetMaskText), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_osn.h"

s32 func_80000080(PlayState* play) {
    switch (Player_GetMask(play)) {
        case PLAYER_MASK_GREAT_FAIRY:
            return 0x1FD6;

        case PLAYER_MASK_GIBDO:
            return 0x1FD8;

        case PLAYER_MASK_TRUTH:
            return 0x1FDA;

        case PLAYER_MASK_GIANT:
            return 0x1FDC;

        case PLAYER_MASK_KAFEIS_MASK:
            return 0x1FDE;

        case PLAYER_MASK_DON_GERO:
            return 0x1FE0;

        case PLAYER_MASK_BLAST:
            return 0x1FE2;

        case PLAYER_MASK_COUPLE:
            return 0x1FE4;

        case PLAYER_MASK_SCENTS:
            return 0x1FE6;

        case PLAYER_MASK_KAMARO:
            return 0x1FE8;

        case PLAYER_MASK_STONE:
            return 0x1FEA;

        case PLAYER_MASK_POSTMAN:
            return 0x1FEC;

        case PLAYER_MASK_BUNNY:
            return 0x1FEE;

        case PLAYER_MASK_CAPTAIN:
            return 0x1FF0;

        case PLAYER_MASK_BREMEN:
            return 0x1FF2;

        case PLAYER_MASK_CIRCUS_LEADER:
            return 0x1FF4;

        case PLAYER_MASK_KEATON:
            return 0x1FF6;

        case PLAYER_MASK_GARO:
            return 0x1FF8;

        case PLAYER_MASK_ALL_NIGHT:
            return 0x1FFA;

        case PLAYER_MASK_ROMANI:
            return 0x1FFC;

        default:
            return 0;
    }
}
