// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play_hireso.h"

void BombersNotebook_LoadFiles(BombersNotebook* this, s32 flag) {
    switch (this->loadState) {
        case BOMBERS_NOTEBOOK_LOAD_STATE_NONE:
            if (this->scheduleDmaSegment == NULL) {
                break;
            }
#if MM_VERSION >= N64_US
            CmpDma_LoadAllFiles(this->scheduleDmaSegmentStart, this->scheduleDmaSegment, this->scheduleDmaSegmentSize);
#endif
            osCreateMesgQueue(&this->loadQueue, this->loadMsg, ARRAY_COUNT(this->loadMsg));
            DmaMgr_RequestAsync(&this->dmaRequest, this->scheduleSegment, this->scheduleSegmentStart,
                                this->scheduleSegmentSize, 0, &this->loadQueue, NULL);
            this->loadState = BOMBERS_NOTEBOOK_LOAD_STATE_STARTED;
            FALLTHROUGH;
        case BOMBERS_NOTEBOOK_LOAD_STATE_STARTED:
            if (osRecvMesg(&this->loadQueue, NULL, flag) == 0) {
                this->loadState = BOMBERS_NOTEBOOK_LOAD_STATE_DONE;
            }
            break;

        default:
            break;
    }
}
