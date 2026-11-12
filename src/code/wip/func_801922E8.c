// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ s8 unk1;
    /* 0x02 */ u8 pad2[2];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s8 *unk1C;
    /* 0x20 */ s32 pad20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x64 - 0x28];
} SlowLoad; /* size 0x64 */

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 pad4[0xC];
} SeqTableHeader;

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s8 unk18;
    /* 0x19 */ u8 pad19[7];
} SeqEntry; /* size 0x20? */

extern struct {
    /* 0x0000 */ u8 pad0[0x1D6C];
    /* 0x1D6C */ s32 unk1D6C;
    /* 0x1D70 */ SlowLoad unk1D70[2];
    /* 0x1E38 */ u8 pad1E38[0x2864 - 0x1E38];
    /* 0x2864 */ u16 unk2864;
} D_801F84B0;

s32 AudioLoad_GetRealTableIndex(s32, s32, s32);
SeqTableHeader *AudioLoad_GetLoadTable(s32);

s32 AudioLoad_SlowLoadSeq(s32 arg0, s32 arg1, s8 *arg2) {
    SlowLoad *slow;
    SeqTableHeader *table;
    SeqEntry *entry;
    s8 temp;

    if (arg0 >= D_801F84B0.unk2864) {
        *arg2 = 0;
        return -1;
    }
    arg0 = AudioLoad_GetRealTableIndex(0, arg0, arg0);
    table = AudioLoad_GetLoadTable(0);
    slow = &D_801F84B0.unk1D70[D_801F84B0.unk1D6C];
    if (slow->unk14 == 3) {
        slow->unk14 = 0;
    }
    slow->unk24 = 0;
    entry = (SeqEntry *)((u8 *)table + arg0 * 0x10);
    slow->unk1C = arg2;
    slow->unk14 = 1;
    slow->unkC = arg1;
    slow->unk18 = (entry->unk14 + 0xF) & ~0xF;
    slow->unk10 = arg1;
    slow->unk8 = entry->unk10;
    temp = entry->unk18;
    slow->unk1 = arg0;
    slow->unk0 = temp;
    if ((temp & 0xFF) == 1) {
        slow->unk4 = table->unk2;
    }
    D_801F84B0.unk1D6C ^= 1;
    return 0;
}
