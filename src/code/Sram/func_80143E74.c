#include "types.h"

extern u8 D_801E6EF0[];

void Sram_ClearFlagsAtDawnOfTheFirstDay(void) {
    D_801E6EF0[0xF2F] &= 0xFD;
    D_801E6EF0[0xF52] &= 0xFE;
    D_801E6EF0[0xF51] &= 0xBF;
    D_801E6EF0[0xF51] &= 0xF7;
    D_801E6EF0[0xF4D] &= 0x7F;
}
