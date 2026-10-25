#include "types.h"

extern u16 D_801CEFD4;
extern f32 *D_801F4AD4;
extern f32 D_801F4AD8;
extern f32 D_801F4ADC;

void Audio_UpdateSfxVolumeTransition(void) {
    if (D_801CEFD4 != 0) {
        D_801CEFD4--;
        if (D_801CEFD4 == 0) {
            *D_801F4AD4 = D_801F4AD8;
            return;
        }
        *D_801F4AD4 -= D_801F4ADC;
    }
}
