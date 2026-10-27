#include "types.h"
typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} A;
typedef struct {
    u8 pad0[0x14B];
    u8 unk14B;
} B;
typedef struct {
    u8 pad0[0xF54];
    u8 unkF54;
    u8 padF55[0x3CAC - 0xF55];
    s32 unk3CAC;
} Gs;
extern Gs D_801E6EF0;
extern s32 D_801BE5D0;
extern void Horse_SpawnMinigame(A *a, B *b);
extern void Horse_SpawnOverworld(A *a, B *b);
void Horse_Spawn(A *a, B *b) {
    s32 v0;
    if ((a->unkA4 == 0x6A && (D_801E6EF0.unkF54 & 7) == 1) ||
        (a->unkA4 == 0x35 && (D_801E6EF0.unk3CAC == 1 || D_801E6EF0.unk3CAC == 5) && b->unk14B == 4) ||
        (a->unkA4 == 0x6A && ((v0 = D_801E6EF0.unkF54 & 7) == 3 || v0 == 2))) {
        Horse_SpawnMinigame(a, b);
    } else {
        Horse_SpawnOverworld(a, b);
    }
    D_801BE5D0 = 0;
}
