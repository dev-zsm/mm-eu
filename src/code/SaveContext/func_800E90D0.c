#include "types.h"

typedef struct {
    u8 pad0[0x20];
    u8 unk20;
    u8 pad21[0x3F16 - 0x21];
    u8 unk3F16;
    u8 unk3F17;
    u8 pad3F18[0x3F26 - 0x3F18];
    s16 unk3F26;
    u8 pad3F28[0x3F3E - 0x3F28];
    u8 unk3F3E;
    u8 pad3F3F[0x3F46 - 0x3F3F];
    s16 unk3F46;
    u8 pad3F48[2];
    u16 unk3F4A;
    u8 unk3F4C;
    u8 unk3F4D;
    u16 unk3F4E;
    u8 pad3F50[2];
    s16 unk3F52;
    u8 unk3F54;
    u8 unk3F55;
} SaveContext;

extern SaveContext D_801E6EF0;
void func_800897D0(void *, s32);

void SaveContext_Init(void) {
    func_800897D0(&D_801E6EF0, 0x48E8);
    D_801E6EF0.unk20 = 0;
    D_801E6EF0.unk3F16 = 0xFF;
    D_801E6EF0.unk3F17 = 0xFF;
    D_801E6EF0.unk3F46 = 0;
    D_801E6EF0.unk3F4A = 0xFFEF;
    D_801E6EF0.unk3F4C = 0;
    D_801E6EF0.unk3F4D = 0;
    D_801E6EF0.unk3F4E = 0xFFFF;
    D_801E6EF0.unk3F52 = 0;
    D_801E6EF0.unk3F54 = 1;
    D_801E6EF0.unk3F55 = 0xFF;
    D_801E6EF0.unk3F26 = 0x32;
    D_801E6EF0.unk3F3E = 0;
}
