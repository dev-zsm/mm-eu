// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_choose_NES.h"

void func_8000AB90(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    u16 vtxId;
    s16 j;
    s16 i;
    s16 spAC;
    u16 spA4[3];
    u16* ptr;
    s32 posY;
    s32 relPosY;
    s32 tempPosY;
    s32 posX;
    s32 index;

    this->windowContentVtx = GRAPH_ALLOC(this->state.gfxCtx, 960 * sizeof(Vtx));

    
    for (vtxId = 0; vtxId < 960; vtxId += 4) {
        
        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = 0x12C;
        
        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 16;

        
        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = 0;
        
        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 16;

        
        this->windowContentVtx[vtxId + 0].v.ob[2] = this->windowContentVtx[vtxId + 1].v.ob[2] =
            this->windowContentVtx[vtxId + 2].v.ob[2] = this->windowContentVtx[vtxId + 3].v.ob[2] = 0;

        
        this->windowContentVtx[vtxId + 0].v.flag = this->windowContentVtx[vtxId + 1].v.flag =
            this->windowContentVtx[vtxId + 2].v.flag = this->windowContentVtx[vtxId + 3].v.flag = 0;

        
        this->windowContentVtx[vtxId + 0].v.tc[0] = this->windowContentVtx[vtxId + 0].v.tc[1] =
            this->windowContentVtx[vtxId + 1].v.tc[1] = this->windowContentVtx[vtxId + 2].v.tc[0] = 0;
        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 2].v.tc[1] =
            this->windowContentVtx[vtxId + 3].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x200;

        
        this->windowContentVtx[vtxId + 0].v.cn[0] = this->windowContentVtx[vtxId + 1].v.cn[0] =
            this->windowContentVtx[vtxId + 2].v.cn[0] = this->windowContentVtx[vtxId + 3].v.cn[0] =
                this->windowContentVtx[vtxId + 0].v.cn[1] = this->windowContentVtx[vtxId + 1].v.cn[1] =
                    this->windowContentVtx[vtxId + 2].v.cn[1] = this->windowContentVtx[vtxId + 3].v.cn[1] =
                        this->windowContentVtx[vtxId + 0].v.cn[2] = this->windowContentVtx[vtxId + 1].v.cn[2] =
                            this->windowContentVtx[vtxId + 2].v.cn[2] = this->windowContentVtx[vtxId + 3].v.cn[2] =
                                this->windowContentVtx[vtxId + 0].v.cn[3] = this->windowContentVtx[vtxId + 1].v.cn[3] =
                                    this->windowContentVtx[vtxId + 2].v.cn[3] =
                                        this->windowContentVtx[vtxId + 3].v.cn[3] = 255;
    }

     

    
    this->windowContentVtx[0].v.ob[0] = this->windowContentVtx[2].v.ob[0] = this->windowPosX;
    
    this->windowContentVtx[1].v.ob[0] = this->windowContentVtx[3].v.ob[0] = this->windowContentVtx[0].v.ob[0] + 0x80;
    
    this->windowContentVtx[0].v.ob[1] = this->windowContentVtx[1].v.ob[1] = 0x48;
    
    this->windowContentVtx[2].v.ob[1] = this->windowContentVtx[3].v.ob[1] = this->windowContentVtx[0].v.ob[1] - 0x10;
    
    this->windowContentVtx[1].v.tc[0] = this->windowContentVtx[3].v.tc[0] = 0x1000;

     

    
    for (vtxId = 4, i = 0; i < 3; i++) {
        posX = this->windowPosX - 6;

        
        for (j = 0; j < 7; j++, vtxId += 4) {
            
            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX;
            
            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + sFileInfoBoxPartWidths[j];

            
            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] =
                this->fileNamesY[i] + 0x2C;
            
            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - 0x38;

            
            this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] =
                sFileInfoBoxPartWidths[j] << 5;
            this->windowContentVtx[vtxId + 2].v.tc[1] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x700;

            
            posX += sFileInfoBoxPartWidths[j];
        }
    }

    

    posX = this->windowPosX - 6;
    posY = 44;

    
    for (j = 0; j < 3; j++, vtxId += 16, posY -= 0x10) {

         

        
        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX;
        
        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 0x40;

        
        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] =
            this->buttonYOffsets[j] + posY;
        
        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 0x10;

        
        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x800;

         

        
        this->windowContentVtx[vtxId + 4].v.ob[0] = this->windowContentVtx[vtxId + 6].v.ob[0] = posX + 0x40;
        
        this->windowContentVtx[vtxId + 5].v.ob[0] = this->windowContentVtx[vtxId + 7].v.ob[0] =
            this->windowContentVtx[vtxId + 4].v.ob[0] + 0x6C;

        
        this->windowContentVtx[vtxId + 4].v.ob[1] = this->windowContentVtx[vtxId + 5].v.ob[1] =
            this->buttonYOffsets[j] + posY;
        
        this->windowContentVtx[vtxId + 6].v.ob[1] = this->windowContentVtx[vtxId + 7].v.ob[1] =
            this->windowContentVtx[vtxId + 4].v.ob[1] - 0x10;

        
        this->windowContentVtx[vtxId + 5].v.tc[0] = this->windowContentVtx[vtxId + 7].v.tc[0] = 0xD80;

         

        
        this->windowContentVtx[vtxId + 8].v.ob[0] = this->windowContentVtx[vtxId + 10].v.ob[0] = posX + 0x34;
        
        this->windowContentVtx[vtxId + 9].v.ob[0] = this->windowContentVtx[vtxId + 11].v.ob[0] =
            this->windowContentVtx[vtxId + 8].v.ob[0] + 0x18;

        
        this->windowContentVtx[vtxId + 8].v.ob[1] = this->windowContentVtx[vtxId + 9].v.ob[1] =
            this->buttonYOffsets[j] + posY;
        
        this->windowContentVtx[vtxId + 10].v.ob[1] = this->windowContentVtx[vtxId + 11].v.ob[1] =
            this->windowContentVtx[vtxId + 8].v.ob[1] - 0x10;

        
        this->windowContentVtx[vtxId + 9].v.tc[0] = this->windowContentVtx[vtxId + 11].v.tc[0] = 0x300;

         

        
        this->windowContentVtx[vtxId + 12].v.ob[0] = this->windowContentVtx[vtxId + 14].v.ob[0] = posX + 0xA9;
        
        this->windowContentVtx[vtxId + 13].v.ob[0] = this->windowContentVtx[vtxId + 15].v.ob[0] =
            this->windowContentVtx[vtxId + 12].v.ob[0] + 0x34;

        
        this->windowContentVtx[vtxId + 12].v.ob[1] = this->windowContentVtx[vtxId + 13].v.ob[1] =
            this->buttonYOffsets[j] + posY;
        
        this->windowContentVtx[vtxId + 14].v.ob[1] = this->windowContentVtx[vtxId + 15].v.ob[1] =
            this->windowContentVtx[vtxId + 12].v.ob[1] - 0x10;

        
        this->windowContentVtx[vtxId + 13].v.tc[0] = this->windowContentVtx[vtxId + 15].v.tc[0] = 0x680;
    }

    posY = 44;

    
    for (j = 0; j < 3; j++, posY -= 16) {
        if (!gSaveContext.flashSaveAvailable) {
            
            
            continue;
        }

        

        spAC = j;
        if (this->isOwlSave[j + 2]) {
            spAC = j + 2;
        }

         

        posX = this->windowPosX - 6;

        if ((this->configMode == 0x10) && (j == this->copyDestFileIndex)) {
            relPosY = this->fileNamesY[j] + 0x2C;
        } else if (((this->configMode == 0x11) || (this->configMode == 0x12)) && (j == this->copyDestFileIndex)) {
            relPosY = this->buttonYOffsets[j] + posY;
        } else {
            relPosY = posY + this->buttonYOffsets[j] + this->fileNamesY[j];
        }

        tempPosY = relPosY - 2;

        
        for (i = 0; i < 8; i++, vtxId += 4) {

            index = this->fileNames[j][i];

             

            
            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] =
                ref_D_80814280[index] + posX + 0x4E;
            
            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + 0xB;

            
            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;
            
            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - 0xC;

             

            
            this->windowContentVtx[vtxId + 32].v.ob[0] = this->windowContentVtx[vtxId + 34].v.ob[0] =
                ref_D_80814280[index] + posX + 0x4F;
            
            this->windowContentVtx[vtxId + 33].v.ob[0] = this->windowContentVtx[vtxId + 35].v.ob[0] =
                this->windowContentVtx[vtxId + 32].v.ob[0] + 0xB;

            
            this->windowContentVtx[vtxId + 32].v.ob[1] = this->windowContentVtx[vtxId + 33].v.ob[1] = tempPosY - 1;
            
            this->windowContentVtx[vtxId + 34].v.ob[1] = this->windowContentVtx[vtxId + 35].v.ob[1] =
                this->windowContentVtx[vtxId + 32].v.ob[1] - 0xC;

            
            posX += 10;
        }
        
        vtxId += 32;

         

        posX = this->windowPosX + 14;
        tempPosY = relPosY - 0x18;

        FileSelect_SplitNumber(this->rupees[spAC], &spA4[0], &spA4[1], &spA4[2]);

        index = sWalletFirstDigit[this->walletUpgrades[spAC]];

        ptr = &spA4[index];

        for (i = 0; i < 3; i++, vtxId += 4, ptr++) {

             

            
            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] =
                ref_D_80814280[*ptr] + posX;
            
            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + ref_D_80814628[i];

            
            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;
            
            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - ref_D_80814630[i];

             

            
            this->windowContentVtx[vtxId + 12].v.ob[0] = this->windowContentVtx[vtxId + 14].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + 1;
            
            this->windowContentVtx[vtxId + 13].v.ob[0] = this->windowContentVtx[vtxId + 15].v.ob[0] =
                this->windowContentVtx[vtxId + 12].v.ob[0] + ref_D_80814628[i];

            
            this->windowContentVtx[vtxId + 12].v.ob[1] = this->windowContentVtx[vtxId + 13].v.ob[1] = tempPosY - 1;
            
            this->windowContentVtx[vtxId + 14].v.ob[1] = this->windowContentVtx[vtxId + 15].v.ob[1] =
                this->windowContentVtx[vtxId + 12].v.ob[1] - ref_D_80814630[i];

            
            posX += ref_D_80814620[i];
        }

        
        vtxId += 12;

         

        posX = this->windowPosX + 42;
        tempPosY = relPosY - 0x2A;

        FileSelect_SplitNumber(this->maskCount[spAC], &spA4[0], &spA4[1], &spA4[2]);

        for (i = 1; i < 3; i++, vtxId += 4) {

             

            
            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] =
                ref_D_80814280[spA4[i]] + posX;
            
            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + ref_D_80814628[i];

            
            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;
            
            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - ref_D_80814630[i];

             

            
            this->windowContentVtx[vtxId + 8].v.ob[0] = this->windowContentVtx[vtxId + 10].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + 1;
            
            this->windowContentVtx[vtxId + 9].v.ob[0] = this->windowContentVtx[vtxId + 11].v.ob[0] =
                this->windowContentVtx[vtxId + 8].v.ob[0] + ref_D_80814628[i];

            
            this->windowContentVtx[vtxId + 8].v.ob[1] = this->windowContentVtx[vtxId + 9].v.ob[1] = tempPosY - 1;
            
            this->windowContentVtx[vtxId + 10].v.ob[1] = this->windowContentVtx[vtxId + 11].v.ob[1] =
                this->windowContentVtx[vtxId + 8].v.ob[1] - ref_D_80814630[i];

            
            posX += ref_D_80814620[i];
        }

        
        vtxId += 8;

         

        posX = this->windowPosX + 63;
        tempPosY = relPosY - 0x10;

        
        for (i = 0; i < 20; i++, vtxId += 4, posX += 9) {
            
            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX;
            
            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + 0xA;

            
            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;
            
            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - 0xA;

            
            if (i == 9) {
                posX = this->windowPosX + (63 - 9);
                tempPosY -= 8;
            }
        }

         

        posX = this->windowPosX + 64;
        tempPosY = relPosY - 0x20;

        
        for (i = 0; i < 4; i++, vtxId += 4, posX += 0x18) {
            
            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX;
            
            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + 0x14;

            
            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;
            
            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - 0x14;

            
            this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 2].v.tc[1] =
                this->windowContentVtx[vtxId + 3].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x400;
        }

         

        
        tempPosY = relPosY - 0x15;

        
        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = this->windowPosX - 1;
        
        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 0x10;

        
        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;
        
        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 0x10;

        
        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x200;
        this->windowContentVtx[vtxId + 2].v.tc[1] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x200;

        vtxId += 4;

         

        
        tempPosY = relPosY - 0x15;

        
        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = this->windowPosX + 0x27;
        
        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 0x18;

        
        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;
        
        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 0x10;

        
        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x300;
        this->windowContentVtx[vtxId + 2].v.tc[1] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x200;

        vtxId += 4;

         

        
        tempPosY = relPosY - 0x27;

        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = this->windowPosX - 10;

        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 0x40;

        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY;

        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 0x10;

        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x800;
        this->windowContentVtx[vtxId + 2].v.tc[1] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x200;

        this->windowContentVtx[vtxId + 4].v.ob[0] = this->windowContentVtx[vtxId + 6].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 1;

        this->windowContentVtx[vtxId + 5].v.ob[0] = this->windowContentVtx[vtxId + 7].v.ob[0] =
            this->windowContentVtx[vtxId + 4].v.ob[0] + 0x40;

        this->windowContentVtx[vtxId + 4].v.ob[1] = this->windowContentVtx[vtxId + 5].v.ob[1] = tempPosY - 1;

        this->windowContentVtx[vtxId + 6].v.ob[1] = this->windowContentVtx[vtxId + 7].v.ob[1] =
            this->windowContentVtx[vtxId + 4].v.ob[1] - 0x10;

        this->windowContentVtx[vtxId + 5].v.tc[0] = this->windowContentVtx[vtxId + 7].v.tc[0] = 0x800;
        this->windowContentVtx[vtxId + 6].v.tc[1] = this->windowContentVtx[vtxId + 7].v.tc[1] = 0x200;

        vtxId += 8;

         

        posX = this->windowPosX + 0xA3;

        if ((this->configMode == 0x10) && (j == this->copyDestFileIndex)) {
            tempPosY = this->fileNamesY[j] + 0x2C;
        } else if (((this->configMode == 0x11) || (this->configMode == 0x12)) && (j == this->copyDestFileIndex)) {
            tempPosY = this->buttonYOffsets[j] + posY;
        } else {
            tempPosY = posY + this->buttonYOffsets[j] + this->fileNamesY[j];
        }

        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX + 0xE;

        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 0x18;

        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY - 2;

        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 0xC;

        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x300;
        this->windowContentVtx[vtxId + 2].v.tc[1] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x180;

        vtxId += 4;

         

        for (i = 0; i < 2; i++, vtxId += 4) {

            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = 2 + posX + i;

            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + 0x30;

            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY - i - 0x12;

            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - 0x18;

            this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x600;

            this->windowContentVtx[vtxId + 2].v.tc[1] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x300;
        }

         

        posX += 6;
        index = vtxId;

        for (i = 0; i < 5; i++, vtxId += 4, posX += 8) {

            this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX;

            this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
                this->windowContentVtx[vtxId + 0].v.ob[0] + 0xC;

            this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] = tempPosY - 0x2A;

            this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
                this->windowContentVtx[vtxId + 0].v.ob[1] - 0xC;

            this->windowContentVtx[vtxId + 0x14].v.ob[0] = this->windowContentVtx[vtxId + 0x16].v.ob[0] = posX + 1;

            this->windowContentVtx[vtxId + 0x15].v.ob[0] = this->windowContentVtx[vtxId + 0x17].v.ob[0] =
                this->windowContentVtx[vtxId + 0x14].v.ob[0] + 0xC;

            this->windowContentVtx[vtxId + 0x14].v.ob[1] = this->windowContentVtx[vtxId + 0x15].v.ob[1] =
                tempPosY - 0x2B;

            this->windowContentVtx[vtxId + 0x16].v.ob[1] = this->windowContentVtx[vtxId + 0x17].v.ob[1] =
                this->windowContentVtx[vtxId + 0x14].v.ob[1] - 0xC;
        }

        
        this->windowContentVtx[index + 8].v.ob[0] = this->windowContentVtx[index + 10].v.ob[0] =
            this->windowContentVtx[index + 8].v.ob[0] + 3;

        this->windowContentVtx[index + 9].v.ob[0] = this->windowContentVtx[index + 11].v.ob[0] =
            this->windowContentVtx[index + 8].v.ob[0] + 0xC;

        this->windowContentVtx[index + 0x1C].v.ob[0] = this->windowContentVtx[index + 0x1E].v.ob[0] =
            this->windowContentVtx[index + 8].v.ob[0] + 1;

        this->windowContentVtx[index + 0x1D].v.ob[0] = this->windowContentVtx[index + 0x1F].v.ob[0] =
            this->windowContentVtx[index + 0x1C].v.ob[0] + 0xC;

        vtxId += 20;
    }

    posX = this->windowPosX - 6;
    posY = -0xC;

    for (j = 0; j < 2; j++, vtxId += 4, posY -= 0x10) {

        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX;

        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 0x40;

        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] =
            this->buttonYOffsets[j + 3] + posY;

        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 0x10;

        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x800;
    }

    this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = posX;

    this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
        this->windowContentVtx[vtxId + 0].v.ob[0] + 0x40;

    this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] =
        this->buttonYOffsets[5] - 0x34;

    this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
        this->windowContentVtx[vtxId + 0].v.ob[1] - 0x10;

    this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x800;

    vtxId += 4;

    if (((this->menuMode == FS_MENU_MODE_CONFIG) && (this->configMode >= 2)) ||
        ((this->menuMode == FS_MENU_MODE_SELECT) && (this->selectMode == 3))) {
        if (this->menuMode == FS_MENU_MODE_CONFIG) {
            if ((this->configMode == 4) || (this->configMode == 7) || (this->configMode == 0x16)) {
                j = ref_D_80814644[this->buttonIndex];
            } else if ((this->configMode == 0x19) || (this->configMode == 0xC)) {
                j = ref_D_8081464C[this->buttonIndex];
            } else {
                j = ref_D_80814638[this->buttonIndex];
            }
        } else {
            j = ref_D_80814650[this->confirmButtonIndex];
        }

        this->windowContentVtx[vtxId + 0].v.ob[0] = this->windowContentVtx[vtxId + 2].v.ob[0] = this->windowPosX - 0xA;

        this->windowContentVtx[vtxId + 1].v.ob[0] = this->windowContentVtx[vtxId + 3].v.ob[0] =
            this->windowContentVtx[vtxId + 0].v.ob[0] + 0x48;

        this->windowContentVtx[vtxId + 0].v.ob[1] = this->windowContentVtx[vtxId + 1].v.ob[1] =
            this->windowContentVtx[j].v.ob[1] + 4;

        this->windowContentVtx[vtxId + 2].v.ob[1] = this->windowContentVtx[vtxId + 3].v.ob[1] =
            this->windowContentVtx[vtxId + 0].v.ob[1] - 0x18;

        this->windowContentVtx[vtxId + 1].v.tc[0] = this->windowContentVtx[vtxId + 3].v.tc[0] = 0x900;

        this->windowContentVtx[vtxId + 2].v.tc[1] = this->windowContentVtx[vtxId + 3].v.tc[1] = 0x300;
    }

    this->windowContentVtx[vtxId + 4].v.ob[0] = this->windowContentVtx[vtxId + 6].v.ob[0] = this->windowPosX + 0x3A;

    this->windowContentVtx[vtxId + 5].v.ob[0] = this->windowContentVtx[vtxId + 7].v.ob[0] =
        this->windowContentVtx[vtxId + 4].v.ob[0] + 0x80;

    this->windowContentVtx[vtxId + 4].v.ob[1] = this->windowContentVtx[vtxId + 5].v.ob[1] =
        this->windowContentVtx[ref_D_80814638[this->warningButtonIndex]].v.ob[1];

    this->windowContentVtx[vtxId + 6].v.ob[1] = this->windowContentVtx[vtxId + 7].v.ob[1] =
        this->windowContentVtx[vtxId + 4].v.ob[1] - 0x10;

    this->windowContentVtx[vtxId + 5].v.tc[0] = this->windowContentVtx[vtxId + 7].v.tc[0] = 0x1000;
}
