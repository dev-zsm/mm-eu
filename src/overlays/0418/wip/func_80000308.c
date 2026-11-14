// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_GetInitialMaskText), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_osn.h"

s32 func_80000308(EnOsn* this, PlayState* play) {
    switch (Player_GetMask(play)) {
        case PLAYER_MASK_GREAT_FAIRY:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_GREAT_FAIRY)) {
                this->maskTextFlags |= OSN_MASK_TEXT_GREAT_FAIRY;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_GIBDO:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_GIBDO)) {
                this->maskTextFlags |= OSN_MASK_TEXT_GIBDO;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_TRUTH:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_TRUTH)) {
                this->maskTextFlags |= OSN_MASK_TEXT_TRUTH;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_GIANT:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_GIANT)) {
                this->maskTextFlags |= OSN_MASK_TEXT_GIANT;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_KAFEIS_MASK:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_KAFEIS)) {
                this->maskTextFlags |= OSN_MASK_TEXT_KAFEIS;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_DON_GERO:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_DON_GERO)) {
                this->maskTextFlags |= OSN_MASK_TEXT_DON_GERO;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_BLAST:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_BLAST)) {
                this->maskTextFlags |= OSN_MASK_TEXT_BLAST;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_COUPLE:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_COUPLE)) {
                this->maskTextFlags |= OSN_MASK_TEXT_COUPLE;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_SCENTS:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_SCENTS)) {
                this->maskTextFlags |= OSN_MASK_TEXT_SCENTS;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_KAMARO:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_KAMARO)) {
                this->maskTextFlags |= OSN_MASK_TEXT_KAMARO;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_STONE:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_STONE)) {
                this->maskTextFlags |= OSN_MASK_TEXT_STONE;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_POSTMAN:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_POSTMAN)) {
                this->maskTextFlags |= OSN_MASK_TEXT_POSTMAN;
                return 0x1FD2;
            }
            break;

        case PLAYER_MASK_BUNNY:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_BUNNY)) {
                this->maskTextFlags |= OSN_MASK_TEXT_BUNNY;
                return 0x1FD2;
            }
            break;

        case PLAYER_MASK_CAPTAIN:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_CAPTAIN)) {
                this->maskTextFlags |= OSN_MASK_TEXT_CAPTAIN;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_BREMEN:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_BREMEN)) {
                this->maskTextFlags |= OSN_MASK_TEXT_BREMEN;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_CIRCUS_LEADER:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_CIRCUS_LEADER)) {
                this->maskTextFlags |= OSN_MASK_TEXT_CIRCUS_LEADER;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_KEATON:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_KEATON)) {
                this->maskTextFlags |= OSN_MASK_TEXT_KEATON;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_GARO:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_GARO)) {
                this->maskTextFlags |= OSN_MASK_TEXT_GARO;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_ALL_NIGHT:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_ALL_NIGHT)) {
                this->maskTextFlags |= OSN_MASK_TEXT_ALL_NIGHT;
                return 0x1FD1;
            }
            break;

        case PLAYER_MASK_ROMANI:
            if (!(this->maskTextFlags & OSN_MASK_TEXT_ROMANI)) {
                this->maskTextFlags |= OSN_MASK_TEXT_ROMANI;
                return 0x1FD1;
            }
            break;

        default:
            break;
    }
    this->stateFlags |= OSN_STATE_END_CONVERSATION;
    if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) && (CURRENT_TIME < CLOCK_TIME(6, 0))) {
        return 0x2006;
    }
    return 0x1FCD;
}
