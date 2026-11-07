#include "types.h"
typedef struct { u8 pad[0x1C]; s16 unk1C; u8 pad1E[0x1B6]; s16 unk1D4; s16 unk1D6; s16 unk1D8; s16 unk1DA; } A;
typedef struct { u8 pad[0x18864]; u8 *unk18864; } B;
void func_80000538(A *a, B *b) {
    a->unk1D4 = b->unk18864[(a->unk1C & 0xFF) * 8] - 1;
    a->unk1D6 = 0;
    a->unk1D8 = 1;
    a->unk1DA = 1;
}
