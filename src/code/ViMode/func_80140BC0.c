#include "types.h"

typedef struct { u8 pad0[0x134]; s16 unk134, unk136, unk138, unk13A, unk13C, unk13E, unk140; } Src;
typedef struct { u8 pad0[0x50]; s32 unk50, unk54, unk58, unk5C, unk60, unk64, unk68; } Dst;

extern Src *D_801EB7E0;

void ViMode_Load(Dst *dst) {
    if ((D_801EB7E0->unk136 & -4) == 1) {
        D_801EB7E0->unk136 += 4;
    }
    dst->unk68 = D_801EB7E0->unk134;
    dst->unk54 = D_801EB7E0->unk136 & -4;
    dst->unk50 = D_801EB7E0->unk138;
    dst->unk64 = D_801EB7E0->unk13A;
    dst->unk60 = D_801EB7E0->unk13C;
    dst->unk5C = D_801EB7E0->unk13E;
    dst->unk58 = D_801EB7E0->unk140;
}
