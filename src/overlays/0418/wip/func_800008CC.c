// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_HandleConversation), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_osn.h"

void func_800008CC(EnOsn* this, PlayState* play) {
    switch (this->textId) {
        case 0x1FC8:
            this->textId = 0x1FC9;
            break;

        case 0x1FC9:
            this->textId = 0x1FCA;
            break;

        case 0x1FCA:
            if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) &&
                (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                this->textId = 0x2007;
            } else {
                this->textId = 0x1FCB;
            }
            break;

        case 0x1FCB:
        case 0x2007:
            this->textId = 0x1FCC;
            this->stateFlags |= OSN_STATE_END_CONVERSATION;
            break;

        case 0x1FCE:
        case 0x1FD0:
            this->textId = 0x1FCF;
            break;

        case 0x1FCF:
            this->textId = 0x1FCA;
            break;

        case 0x1FD1:
        case 0x1FD2:
            this->textId = EnOsn_GetMaskText(play);
            break;

        case 0x1FD6:
            this->textId = 0x1FD7;
            break;

        case 0x1FD8:
            this->textId = 0x1FD9;
            break;

        case 0x1FDA:
            this->textId = 0x1FDB;
            break;

        case 0x1FDC:
            this->textId = 0x1FDD;
            break;

        case 0x1FDE:
            this->textId = 0x1FDF;
            break;

        case 0x1FE0:
            this->textId = 0x1FE1;
            break;

        case 0x1FE2:
            this->textId = 0x1FE3;
            break;

        case 0x1FE4:
            this->textId = 0x1FE5;
            break;

        case 0x1FE6:
            this->textId = 0x1FE7;
            break;

        case 0x1FE8:
            this->textId = 0x1FE9;
            break;

        case 0x1FEA:
            this->textId = 0x1FEB;
            break;

        case 0x1FEC:
            this->textId = 0x1FED;
            break;

        case 0x1FEE:
            this->textId = 0x1FEF;
            break;

        case 0x1FF0:
            this->textId = 0x1FF1;
            break;

        case 0x1FF2:
            this->textId = 0x1FF3;
            break;

        case 0x1FF4:
            this->textId = 0x1FF5;
            break;

        case 0x1FF6:
            this->textId = 0x1FF7;
            break;

        case 0x1FF8:
            this->textId = 0x1FF9;
            break;

        case 0x1FFA:
            this->textId = 0x1FFB;
            break;

        case 0x1FFC:
            this->textId = 0x1FFD;
            break;

        case 0x1FD7:
        case 0x1FDB:
        case 0x1FDD:
        case 0x1FDF:
        case 0x1FE1:
        case 0x1FE7:
        case 0x1FF1:
        case 0x1FF3:
        case 0x1FF7:
        case 0x1FF9:
        case 0x1FFB:
            this->textId = 0x1FD3;
            break;

        case 0x1FD9:
        case 0x1FE3:
        case 0x1FE9:
        case 0x1FEB:
        case 0x1FED:
        case 0x1FEF:
        case 0x1FF5:
        case 0x1FFD:
            this->textId = 0x1FD4;
            break;

        case 0x1FE5:
            this->textId = 0x1FFE;
            break;

        case 0x1FD3:
        case 0x1FD4:
        case 0x1FFE:
            this->textId = 0x1FD5;
            this->stateFlags |= OSN_STATE_END_CONVERSATION;
            break;
    }

    Message_StartTextbox(play, this->textId, &this->actor);
}
