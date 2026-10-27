#include "types.h"

typedef struct { u8 pad0[0x144]; s8 unk144; u8 pad145[6]; u8 unk14B; u8 unk14C; u8 pad14D[2]; u8 unk14F; } Player;
typedef struct { u8 a; u8 b[4]; } Entry;
extern Entry D_801C0C70[];
extern void Player_SetModels(Player *p);

void Player_SetModelGroup(Player *p, s32 g) {
    p->unk14C = g;
    if (g == 1) {
        p->unk14F = 0;
    } else {
        p->unk14F = D_801C0C70[g].a;
    }
    if (p->unk14F < 3) {
        if ((p->unk14B != 0 && p->unk14B != 4) || p->unk144 == 0) {
            p->unk14F = 0;
        }
    }
    Player_SetModels(p);
}
