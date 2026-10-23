// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 textSize;
    u32 dataSize;
    u32 rodataSize;
    u32 bssSize;
    u32 nRelocations;
    u32 relocations[1];
} OverlayRelocationSection;

extern s32 D_80096DC0;

void func_80084A00(u32 allocu32, OverlayRelocationSection *ovl, u32 vramStart) {
    u32 sections[4];
    u32 *relocDataP;
    u32 reloc;
    u32 i;
    u32 *luiInstRef;
    u32 *regValP;
    u32 isLoNeg;
    u32 *luiRefs[32];
    u32 luiVals[32];
    u32 relocatedAddress;
    u32 unrelocatedAddress;

    sections[0] = 0;
    sections[1] = allocu32;
    sections[2] = sections[1] + ovl->textSize;
    sections[3] = sections[2] + ovl->dataSize;

    for (i = 0; i < ovl->nRelocations; i++) {
        reloc = ovl->relocations[i];
        relocDataP = (u32 *)(sections[reloc >> 30] + (reloc & 0xFFFFFF));
        switch (reloc & 0x3F000000) {
            case 0x02000000:
                if (!(*relocDataP & 0x0F000000)) {
                    *relocDataP = *relocDataP - vramStart + allocu32;
                } else if (D_80096DC0 >= 3) {
                }
                break;
            case 0x04000000:
                *relocDataP = (*relocDataP & 0xFC000000) |
                              ((((((*relocDataP & 0x03FFFFFF) << 2) | 0x80000000) - vramStart + allocu32) & 0x0FFFFFFF) >> 2);
                break;
            case 0x05000000:
                luiRefs[(*relocDataP >> 16) & 0x1F] = relocDataP;
                luiVals[(*relocDataP >> 16) & 0x1F] = *relocDataP;
                break;
            case 0x06000000:
                regValP = &luiVals[(*relocDataP >> 21) & 0x1F];
                luiInstRef = luiRefs[(*relocDataP >> 21) & 0x1F];
                unrelocatedAddress = (s16)*relocDataP + (*luiInstRef << 16);
                if (!(unrelocatedAddress & 0x0F000000)) {
                    relocatedAddress = ((s16)*relocDataP + (*regValP << 16)) - vramStart + allocu32;
                    isLoNeg = (relocatedAddress & 0x8000) ? 1 : 0;
                    *luiInstRef = (*luiInstRef & 0xFFFF0000) | (((relocatedAddress >> 16) & 0xFFFF) + isLoNeg);
                    *relocDataP = (*relocDataP & 0xFFFF0000) | (relocatedAddress & 0xFFFF);
                } else if (D_80096DC0 >= 3) {
                }
                break;
        }
    }
}
