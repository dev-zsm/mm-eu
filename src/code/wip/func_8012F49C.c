#include "types.h"
typedef struct { s32 a; s32 b; } P2;
typedef struct {
  s32 pad[6]; s32 unk18; u8 pad1C[0x10]; u8 unk2C[8]; u8 pad34[0xA2]; u8 unkD6[5][8];
  u8 padFE[0xE68-0xFE]; s32 unkE68[5]; u8 padE7C[0x3DE0-0xE7C]; P2 q[1];
} SC;
extern SC D_801E6EF0;
void Inventory_SaveDekuPlaygroundHighScore(s16 arg0) {
    s16 j;
    D_801E6EF0.unkE68[D_801E6EF0.unk18 % 5] = (&D_801E6EF0.q[0])[arg0].b;
    for (j = 0; j < 8; j++) {
        D_801E6EF0.unkD6[D_801E6EF0.unk18 % 5][j] = D_801E6EF0.unk2C[j];
    }
}
