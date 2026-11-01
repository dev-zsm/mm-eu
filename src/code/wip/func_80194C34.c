// FLAGS: -O1 -g3 -mips2
// WIP: 4 instr differ; -O2 folds the address into lui at and loses the two separate lui/addiu of the ROM.
#include "types.h"
typedef struct { u8 pad0[0x29A4]; s32 unk29A4; u8 pad29A8[0x4448 - 0x29A8]; u8 unk4448; } AudioContext;
extern AudioContext D_801F84B0;
extern s32 D_801CE918;
extern void AudioThread_ResetAudioHeap(s32 a0);
void AudioThread_PreNMIInternal(void) { *(s32 *)((u8 *)&D_801F84B0 + 0x29A4) = 1; if (D_801CE918 != 0) { AudioThread_ResetAudioHeap(0); *((u8 *)&D_801F84B0 + 0x4448) = 0; } }
