#include "types.h"

typedef struct {
    u8 pad0[0xE6C];
    s32 unkE6C;
    s32 unkE70;
    s32 unkE74;
    u8 padE78[0xEE8 - 0xE78];
    u32 unkEE8;
    s32 unkEEC;
    u8 padEF0[4];
    u32 unkEF4;
} Data801E6EF0;
extern Data801E6EF0 D_801E6EF0;
void Sram_ClearHighscores(void) {
    D_801E6EF0.unkEE8 = (D_801E6EF0.unkEE8 & 0xFFFF) | 0x130000;
    D_801E6EF0.unkEE8 = (D_801E6EF0.unkEE8 & 0xFFFF0000) | 0xA;
    D_801E6EF0.unkEEC = 0x1770;
    D_801E6EF0.unkEF4 = (D_801E6EF0.unkEF4 & 0xFFFF0000) | 0x27;
    D_801E6EF0.unkEF4 = (D_801E6EF0.unkEF4 & 0xFFFF) | 0xA0000;
    D_801E6EF0.unkE6C = 0x1D4C;
    D_801E6EF0.unkE70 = 0x1D4C;
    D_801E6EF0.unkE74 = 0x1DB0;
}
