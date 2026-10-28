#include "types.h"

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 padC[0x3F4C - 0xC];
    u8 unk3F4C;
} CsState;
typedef struct {
    u8 pad[0x18875];
    s8 unk18875;
} CsGlobal;
typedef struct {
    u8 pad[8];
    u8 unk8;
} CsArg1;
extern CsState D_801E6EF0;
extern void (*D_801BBC78[])(CsGlobal *, CsArg1 *);
extern void Cutscene_SetupScripted(void);
void Cutscene_UpdateScripted(CsGlobal *arg0, CsArg1 *arg1) {
    short v = D_801E6EF0.unk3F4C;
    if ((v != 0) && (arg0->unk18875 == 0x14)) {
        v = (D_801E6EF0.unk3F4C = 0);
    }
    if ((v != 0) && (arg1->unk8 == 0)) {
        D_801E6EF0.unk8 = 0xFFFD;
        D_801E6EF0.unk3F4C = 1;
    }
    if (D_801E6EF0.unk8 >= 0xFFF0) {
        Cutscene_SetupScripted();
        D_801BBC78[arg1->unk8](arg0, arg1);
    }
}
