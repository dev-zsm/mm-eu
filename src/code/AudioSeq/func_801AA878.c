#include "types.h"

typedef struct {
    u8 pad0[0x1CC];
    u32 unk1CC;
    u8 pad1D0[0x202 - 0x1D0];
    u16 unk202;
    u16 unk204;
    u16 unk206;
    u16 unk208;
    u16 unk20A;
    u16 unk20C;
    u16 unk20E;
    u8 unk210;
    u8 pad211;
    u8 unk212[4];
    u8 unk216;
    u8 unk217;
    u8 pad218;
    u8 unk219;
    u8 unk21A;
    u8 unk21B;
} ActiveSeq;

extern u8 D_801F7574[];
extern ActiveSeq D_801F7980[];

void AudioSeq_ResetActiveSequences(void) {
    u8 i;
    u8 j;

    for (i = 0; i < 5; i++) {
        D_801F7574[i] = 0;
        D_801F7980[i].unk20A = 0xFFFF;
        D_801F7980[i].unk20C = 0xFFFF;
        D_801F7980[i].unk204 = 0;
        D_801F7980[i].unk202 = 0;
        D_801F7980[i].unk1CC = 0;
        D_801F7980[i].unk20E = 0;
        D_801F7980[i].unk219 = 0;
        D_801F7980[i].unk21A = 0;
        D_801F7980[i].unk206 = 0;
        D_801F7980[i].unk208 = 0;
        D_801F7980[i].unk210 = 0;
        D_801F7980[i].unk21B = 0;
        for (j = 0; j < 4; j++) {
            D_801F7980[i].unk212[j] = 0x7F;
        }
        D_801F7980[i].unk216 = 1;
        D_801F7980[i].unk217 = 1;
    }
}
