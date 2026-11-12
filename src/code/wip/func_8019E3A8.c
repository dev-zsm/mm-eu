// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x0 */ u8 noteIndex;
    /* 0x1 */ u8 pad1;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 unk6;
    /* 0x7 */ u8 pad7;
} MemoryGameEntry; /* size 0x8 */

extern u8 D_801CF960[];
extern u8 D_801CF968;
extern u8 D_801CF96C;
extern struct {
    u8 pad[0x8B8];
    MemoryGameEntry e[1];
} D_801CF974;

u32 AudioThread_NextRandom();

s32 AudioOcarina_MemoryGameNextNote(void) {
    u32 rnd;
    u8 noteIndex;
    u8 next;

    if (D_801CF96C == D_801CF968) {
        return 1;
    }
    rnd = AudioThread_NextRandom();
    noteIndex = D_801CF960[rnd % 5];
    if (noteIndex == D_801CF974.e[D_801CF968].noteIndex) {
        noteIndex = D_801CF960[(rnd + 1) % 5];
    }
    next = D_801CF968 + 1;
    D_801CF974.e[D_801CF968 + 1].noteIndex = noteIndex;
    D_801CF974.e[D_801CF968 + 1].unk2 = 0x26;
    D_801CF974.e[D_801CF968 + 1].unk4 = 0x50;
    D_801CF974.e[D_801CF968 + 1].unk5 = 0;
    D_801CF974.e[D_801CF968 + 1].unk6 = 0;
    D_801CF974.e[next].noteIndex = 0xFF;
    D_801CF974.e[next].unk2 = 0;
    D_801CF968 = next;
    D_801CF974.e[next + 1].noteIndex = 0xFF;
    D_801CF974.e[next + 1].unk2 = 0;
    return 0;
}
