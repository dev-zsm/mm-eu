// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vimode.h"

void ViMode_Update(ViMode* viMode, Input* input) {
    ViMode_Load(viMode);

    if ((viMode->editState == VI_MODE_EDIT_STATE_ACTIVE) || (viMode->editState == VI_MODE_EDIT_STATE_2) ||
        (viMode->editState == VI_MODE_EDIT_STATE_3)) {
        gScreenWidth = viMode->viWidth;
        gScreenHeight = viMode->viHeight;

        
        if (CHECK_BTN_ALL(input->cur.button, BTN_START | BTN_CUP | BTN_CRIGHT)) {
            ViMode_Init(viMode);
        }

        
        if (CHECK_BTN_ALL(input->cur.button, BTN_CUP)) {
            if (CHECK_BTN_ALL(input->cur.button, BTN_DUP)) {
                viMode->upperAdjust--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN)) {
                viMode->upperAdjust++;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DLEFT)) {
                viMode->leftAdjust--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT)) {
                viMode->leftAdjust++;
            }
        }

        
        if (CHECK_BTN_ALL(input->cur.button, BTN_CRIGHT)) {
            if (CHECK_BTN_ALL(input->cur.button, BTN_DUP)) {
                viMode->lowerAdjust--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN)) {
                viMode->lowerAdjust++;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DLEFT)) {
                viMode->rightAdjust--;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT)) {
                viMode->rightAdjust++;
            }
        }

        
        if (CHECK_BTN_ALL(input->cur.button, BTN_CDOWN)) {
            if (CHECK_BTN_ALL(input->press.button, BTN_DUP)) {
                viMode->loRes = !viMode->loRes;
            }
            if (CHECK_BTN_ALL(input->press.button, BTN_DDOWN)) {
                viMode->antialiasOff = !viMode->antialiasOff;
            }
            if (CHECK_BTN_ALL(input->press.button, BTN_DLEFT)) {
                viMode->modeN = !viMode->modeN;
            }
            if (CHECK_BTN_ALL(input->press.button, BTN_DRIGHT)) {
                viMode->fb16Bit = !viMode->fb16Bit;
            }
        }

        
        if (viMode->editState >= VI_MODE_EDIT_STATE_2) {
            
            if (viMode->leftAdjust < -16) {
                viMode->leftAdjust = -16;
            }
            if (viMode->upperAdjust < -50) {
                viMode->upperAdjust = -50;
            }
            if (viMode->rightAdjust > 16) {
                viMode->rightAdjust = 16;
            }
            if (viMode->lowerAdjust > 50) {
                viMode->lowerAdjust = 50;
            }
        } else {
            
            if (viMode->leftAdjust < 0) {
                viMode->leftAdjust = 0;
            }
            if (viMode->upperAdjust < 0) {
                viMode->upperAdjust = 0;
            }
            if (viMode->rightAdjust > 0) {
                viMode->rightAdjust = 0;
            }
            if (viMode->lowerAdjust > 0) {
                viMode->lowerAdjust = 0;
            }
        }

        ViMode_Configure(&viMode->customViMode, OS_VI_MPAL_LPN1, osTvType, viMode->loRes, viMode->antialiasOff,
                         viMode->modeN, viMode->fb16Bit, viMode->viWidth, viMode->viHeight, viMode->leftAdjust,
                         viMode->rightAdjust, viMode->upperAdjust, viMode->lowerAdjust);
        ViMode_ConfigureFeatures(viMode, viMode->viFeatures);

        if (viMode->editState == VI_MODE_EDIT_STATE_3) {
            
            ViMode_LogPrint(&osViModeNtscLan1);
            ViMode_LogPrint(&viMode->customViMode);
            viMode->editState = VI_MODE_EDIT_STATE_2;
        }
    }

    ViMode_Save(viMode);
}
