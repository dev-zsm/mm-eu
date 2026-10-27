#include "types.h"

typedef struct {
    u32 unk0;
    u32 count;
    u64 total;
    u64 last;
} Nmi;

extern Nmi *D_801ED0C0;
extern Nmi D_8000031C;
extern u32 D_8000030C;

void Nmi_Init(void) {
    D_801ED0C0 = &D_8000031C;
    D_801ED0C0->unk0 = 0;
    if (D_8000030C == 0) {
        D_801ED0C0->count = 0;
        D_801ED0C0->total = 0;
    } else {
        D_801ED0C0->count++;
        D_801ED0C0->total += D_801ED0C0->last;
    }
    D_801ED0C0->last = 0;
}
