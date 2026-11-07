// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gakufu.h"

void EnGakufu_ProcessNotes(EnGakufu* this) {
    OcarinaStaff* playbackStaff;
    OcarinaSongButtons* ocarinaSongButtons;
    s32 songNumButtons;
    s32 i;
    s32 songIndex;

    AudioOcarina_TerminaWallGenerateNotes();
    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_DEFAULT);
    AudioOcarina_StartDefault((1 << this->songIndex) | 0x80000000);
    playbackStaff = AudioOcarina_GetPlaybackStaff();
    playbackStaff->pos = 0;
    playbackStaff->state = 0xFF;
    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);

    songIndex = this->songIndex;
    ocarinaSongButtons = &gOcarinaSongButtons[songIndex];

    
    if (1) {}
    songNumButtons = gOcarinaSongButtons[this->songIndex].numButtons;

    for (i = 0; i < (u8)songNumButtons; i++) {
        this->buttonIndex[i] = ocarinaSongButtons->buttonIndex[i];
    }

    for (; i < ARRAY_COUNT(this->buttonIndex); i++) {
        this->buttonIndex[i] = OCARINA_BTN_INVALID;
    }
}
