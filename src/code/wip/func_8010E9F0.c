// WIP: 12 instr differ; the ROM hoists one constant temp per store.
#include "types.h"

typedef struct {
    u8 pad0[0x100D];
    u8 unk100D;
    u8 pad100E[0x3DD6 - 0x100E];
    u8 unk3DD6;
    u8 pad3DD7[0x3E10 - 0x3DD7];
    s32 unk3E10;
    s32 unk3E14;
} SaveContext;

extern SaveContext D_801E6EF0;

void func_8010E9F0(s32 a0) {
    if (D_801E6EF0.unk3DD6 != 0) {
        if (D_801E6EF0.unk100D & 1) {
            D_801E6EF0.unk3E14 = 0xEF;
            D_801E6EF0.unk3E10 = 0;
        } else {
            D_801E6EF0.unk3E10 = 0;
            D_801E6EF0.unk3E14 = 1;
        }
    }
}
