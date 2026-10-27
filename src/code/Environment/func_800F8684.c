#include "types.h"

// Raw byte access to the save context, matches the compiler aliasing.
extern u8 D_801E6EF0[];

void Environment_SetLetterToKafeiScheduledIf(u16 arg0) {
    if (!(D_801E6EF0[0xF14] & 8) && !(D_801E6EF0[0xF14] & 0x10) && (D_801E6EF0[0xEF8 + (arg0 >> 8)] & arg0 & 0xFF)) {
        if (D_801E6EF0[0xF53] & 4) {
            D_801E6EF0[0xF14] |= 8;
            D_801E6EF0[0xF52] |= 8;
            D_801E6EF0[0xF2B] |= 2;
        }
        if (D_801E6EF0[0xF53] & 8) {
            D_801E6EF0[0xF14] |= 0x10;
            D_801E6EF0[0xF52] |= 8;
            D_801E6EF0[0xF2B] |= 2;
        }
    }
}
