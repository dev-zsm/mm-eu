#include "types.h"

typedef struct { s32 unk0; u8 pad4[0xC]; s64 unk10; } NmiPrenmi;

extern NmiPrenmi *D_801ED0C0;

s64 func_800905C0();

void Nmi_SetPrenmiStart(void) {
    D_801ED0C0->unk0 = 1;
    D_801ED0C0->unk10 = func_800905C0();
}
