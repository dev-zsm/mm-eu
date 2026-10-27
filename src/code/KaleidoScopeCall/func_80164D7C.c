#include "types.h"

typedef struct {
    u8 pad0[0x190];
    s16 unk190;
} SaveCtx4D7C;
typedef struct {
    u8 pad0[0x16F1C];
    u16 unk16F1C;
} Play4D7C;
extern SaveCtx4D7C *D_801EB7E0;
extern u8 D_801C9450[];
extern u8 *D_801C948C;
extern void (*D_801EE494)(Play4D7C *);
void KaleidoScopeCall_Draw(Play4D7C *play) {
    u8 *new_var;
    new_var = D_801C9450;
    if (D_801EB7E0->unk190 == 3) {
        if (((play->unk16F1C >= 4) && (play->unk16F1C < 8)) || ((play->unk16F1C >= 0xB) && (play->unk16F1C < 0x1B))) {
            if (D_801C948C == new_var) {
                D_801EE494(play);
            }
        }
    }
}
