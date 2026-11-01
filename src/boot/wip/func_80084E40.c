// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 textSize;
    u32 dataSize;
    u32 rodataSize;
    u32 bssSize;
    u32 nRelocations;
    u32 relocations[1];
} OvlReloc;

void func_80084E40(u8 *allocatedRamAddr, OvlReloc *ovlRelocs, u32 vramStart) {
    u32 sections[4];
    u32 *relocDataP;
    u32 reloc;
    u32 *luiRefs[32];
    u32 luiVals[32];
    u32 *luiInstRef;
    u32 luiVal;
    u32 isLoNeg;
    u32 relocatedAddress;
    u32 unrelocatedAddress;
    u32 relocatedValue;
    u32 regIdx;
    u32 i;

    sections[0] = 0;
    sections[1] = (u32)allocatedRamAddr;
    sections[2] = sections[1] + ovlRelocs->textSize;
    sections[3] = sections[2] + ovlRelocs->dataSize;

    for (i = 0; i < ovlRelocs->nRelocations; i++) {
        reloc = ovlRelocs->relocations[i];
        relocDataP = (u32 *)(sections[reloc >> 30] + (reloc & 0xFFFFFF));
        if ((reloc & 0x3F000000) == 0x02000000) {
            if ((*relocDataP & 0x0F000000) == 0) {
                *relocDataP = *relocDataP - vramStart + (u32)allocatedRamAddr;
            }
        } else if ((reloc & 0x3F000000) == 0x04000000) {
            relocatedAddress = ((*relocDataP & 0x03FFFFFF) << 2) | 0x80000000;
            relocatedAddress = relocatedAddress - vramStart + (u32)allocatedRamAddr;
            *relocDataP = (*relocDataP & 0xFC000000) | ((relocatedAddress & 0x0FFFFFFF) >> 2);
        } else if ((reloc & 0x3F000000) == 0x05000000) {
            luiRefs[(*relocDataP >> 16) & 0x1F] = relocDataP;
            luiVals[(*relocDataP >> 16) & 0x1F] = *relocDataP;
        } else if ((reloc & 0x3F000000) == 0x06000000) {
            regIdx = (*relocDataP >> 21) & 0x1F;
            luiInstRef = luiRefs[regIdx];
            luiVal = luiVals[regIdx];
            unrelocatedAddress = (s16)*relocDataP + (luiVal << 16);
            if ((unrelocatedAddress & 0x0F000000) == 0) {
                relocatedValue = unrelocatedAddress - vramStart + (u32)allocatedRamAddr;
                isLoNeg = (relocatedValue & 0x8000) ? 1 : 0;
                *luiInstRef = (*luiInstRef & 0xFFFF0000) | (((relocatedValue >> 16) & 0xFFFF) + isLoNeg);
                *relocDataP = (*relocDataP & 0xFFFF0000) | (relocatedValue & 0xFFFF);
            }
        }
    }
}
