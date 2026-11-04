// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_rumble.h"

void RumbleManager_Update(RumbleManager* rumbleMgr) {
    s32 strongestIndex = -1;
    s32 i;
    s32 temp;

    
    for (i = 0; i < ARRAY_COUNT(rumbleMgr->rumbleEnabled); i++) {
        rumbleMgr->rumbleEnabled[i] = false;
    }

    if (!rumbleMgr->updateEnabled) {
        

        if (ref_D_801D1E70) {
            for (i = 0; i < MAXCONTROLLERS; i++) {
                PadMgr_RumbleSetSingle(i, false);
            }
        }

        ref_D_801D1E70 = rumbleMgr->updateEnabled;
        PadMgr_RumblePause();

        return;
    }

    ref_D_801D1E70 = rumbleMgr->updateEnabled;

    
    if (rumbleMgr->state == RUMBLEMANAGER_STATE_INITIAL) {
        for (i = 0; i < MAXCONTROLLERS; i++) {
            PadMgr_RumbleSetSingle(i, false);
        }

        for (i = 0; i < RUMBLE_REQUEST_BUFFER_SIZE; i++) {
            rumbleMgr->requestIntensities[i] = 0;
            rumbleMgr->requestDecayTimers[i] = 0;
            rumbleMgr->requestDecaySteps[i] = 0;
            rumbleMgr->requestAccumulators[i] = 0;
        }

        rumbleMgr->rumblingDuration = 0;
        rumbleMgr->downTime = 0;

        rumbleMgr->overrideIntensity = 0;
        rumbleMgr->overrideDecayTimer = 0;
        rumbleMgr->overrideDecayStep = 0;
        rumbleMgr->overrideAccumulator = 0;

        rumbleMgr->state = RUMBLEMANAGER_STATE_RUNNING;

        PadMgr_RumblePause();
    }

    if (rumbleMgr->state != RUMBLEMANAGER_STATE_WIPE) {
        
        for (i = 0; i < RUMBLE_REQUEST_BUFFER_SIZE; i++) {
            if (rumbleMgr->requestIntensities[i] != 0) { 
                if (rumbleMgr->requestDecayTimers[i] > 0) {
                    rumbleMgr->requestDecayTimers[i]--;
                } else {
                    temp = rumbleMgr->requestIntensities[i] - rumbleMgr->requestDecaySteps[i];
                    if (temp > 0) {
                        rumbleMgr->requestIntensities[i] = temp;
                    } else {
                        rumbleMgr->requestIntensities[i] = 0;
                    }
                }

                temp = rumbleMgr->requestAccumulators[i] + rumbleMgr->requestIntensities[i];
                rumbleMgr->requestAccumulators[i] = temp; 
                if (strongestIndex == -1) {
                    strongestIndex = i;
                    rumbleMgr->rumbleEnabled[0] = (temp >= 0x100);
                } else if (rumbleMgr->requestIntensities[strongestIndex] < rumbleMgr->requestIntensities[i]) {
                    strongestIndex = i;
                    rumbleMgr->rumbleEnabled[0] = (temp >= 0x100);
                }
            }
        }

        
        if (rumbleMgr->overrideIntensity != 0) {
            if (rumbleMgr->overrideDecayTimer > 0) {
                rumbleMgr->overrideDecayTimer--;
            } else {
                temp = rumbleMgr->overrideIntensity - rumbleMgr->overrideDecayStep;
                if (temp > 0) {
                    rumbleMgr->overrideIntensity = temp;
                } else {
                    rumbleMgr->overrideIntensity = 0;
                }
            }

            temp = rumbleMgr->overrideAccumulator + rumbleMgr->overrideIntensity;
            rumbleMgr->overrideAccumulator = temp; 
            rumbleMgr->rumbleEnabled[0] = (temp >= 0x100);
        }

        if (rumbleMgr->overrideIntensity != 0) {
            temp = rumbleMgr->overrideIntensity;
        } else if (strongestIndex == -1) {
            temp = 0;
        } else {
            temp = rumbleMgr->requestIntensities[strongestIndex];
        }

        
        if (temp == 0) {
            rumbleMgr->downTime++;
            if (rumbleMgr->downTime > 5) {
                rumbleMgr->rumblingDuration = 0;
                rumbleMgr->downTime = 5;
            }
        } else {
            rumbleMgr->downTime = 0;
            rumbleMgr->rumblingDuration++;
            if (rumbleMgr->rumblingDuration > 2 * 60 * 60) { 
                
                rumbleMgr->state = RUMBLEMANAGER_STATE_WIPE;
            }
        }
    } else { 
        for (i = 0; i < RUMBLE_REQUEST_BUFFER_SIZE; i++) {
            rumbleMgr->requestIntensities[i] = 0;
            rumbleMgr->requestDecayTimers[i] = 0;
            rumbleMgr->requestDecaySteps[i] = 0;
            rumbleMgr->requestAccumulators[i] = 0;
        }

        rumbleMgr->rumblingDuration = 0;
        rumbleMgr->downTime = 0;

        rumbleMgr->overrideIntensity = 0;
        rumbleMgr->overrideDecayTimer = 0;
        rumbleMgr->overrideDecayStep = 0;
        rumbleMgr->overrideAccumulator = 0;

        PadMgr_RumblePause();
    }
}
