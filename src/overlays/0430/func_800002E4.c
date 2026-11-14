// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tsn.h"

void func_800002E4(EnTsn* this, PlayState* play) {
    u16 textId;

    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_SEAHORSE)) {
        textId = 0x107E;
    } else if (GET_PLAYER_FORM == PLAYER_FORM_ZORA) {
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMAN_AS_ZORA)) {
            textId = 0x1083;
        } else {
            textId = 0x107F;
        }
    } else if (CHECK_WEEKEVENTREG(WEEKEVENTREG_TALKED_FISHERMAN_AS_HUMAN)) {
        textId = 0x1089;
    } else {
        textId = 0x1084;
    }

    Message_StartTextbox(play, textId, &this->actor);
}
