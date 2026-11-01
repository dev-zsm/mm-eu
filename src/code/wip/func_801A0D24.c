#include "types.h"

extern s16 D_801CEFD4;
extern f32 *D_801F4AD4;
extern f32 D_801F4AD8;
extern f32 D_801F4ADC;

// Remaining diff: the ROM loads the addresses of D_801F4AD4/D_801F4AD8/D_801CEFD4 into registers (lui+addiu) and has no
// sll/sra on a2; we use lui+%lo(at) per access.
void Audio_SetSfxVolumeTransition(f32 *arg0, f32 arg1, s16 arg2) {
    D_801F4AD8 = arg1;
    D_801F4AD4 = arg0;
    D_801CEFD4 = arg2;
    D_801F4ADC = (*arg0 - D_801F4AD8) / (u16)arg2;
}
