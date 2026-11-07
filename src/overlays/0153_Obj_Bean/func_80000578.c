#include "types.h"

typedef struct { u8 pad0[0x1C]; s16 unk1C; u8 pad1E[0x1D8 - 0x1E]; s16 unk1D8; s16 unk1DA; s16 unk1DC; } A;
typedef struct { u8 pad0[0x18864]; u8 (*unk18864)[8]; } B;

void func_80000578(A *this, B *play) {
    this->unk1D8 = play->unk18864[(this->unk1C >> 8) & 0x3F][0] - 1;
    this->unk1DA = 0;
    this->unk1DC = 1;
}
