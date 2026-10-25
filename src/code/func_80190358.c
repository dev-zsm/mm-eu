// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x0 */ u32 romAddr;
    /* 0x4 */ u32 size;
    /* 0x8 */ s8 medium;
    /* 0x9 */ u8 pad9[7];
} AudioTableEntry;

typedef struct {
    /* 0x0 */ s16 numEntries;
    /* 0x2 */ s16 shift;
    /* 0x4 */ u32 romAddr;
    /* 0x8 */ u8 pad8[8];
    /* 0x10 */ AudioTableEntry entries[1];
} AudioTable;

void AudioLoad_InitTable(AudioTable *table, u32 romAddr, u16 shift) {
    s32 i;

    table->shift = shift;
    table->romAddr = romAddr;
    for (i = 0; i < table->numEntries; i++) {
        if (table->entries[i].size != 0 && table->entries[i].medium == 2) {
            table->entries[i].romAddr += romAddr;
        }
    }
}
