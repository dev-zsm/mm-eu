// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 a, b, c;
} Words3;

typedef struct {
    char pad0[0x30];
    Words3 params;
} PortamentoSrc;

typedef struct {
    char pad0[0x3C];
    f32 unk3C;
    char pad40[8];
    PortamentoSrc *src;
    char pad4C[0x3C];
    Words3 params;
} Portamento;

void AudioEffects_InitPortamento(Portamento *arg0) {
    arg0->unk3C = 1.0f;
    arg0->params = arg0->src->params;
}
