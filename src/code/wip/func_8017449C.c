#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ void *unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[0x87];
    /* 0x9B */ u8 unk9B;
} SetupState;

extern void SysFlashrom_InitFlash(void);
extern void SaveContext_Init(void);
extern void Setup_InitRegs(void);

void Setup_InitImpl(SetupState *state) {
    SysFlashrom_InitFlash();
    SaveContext_Init();
    Setup_InitRegs();
    state->unk9B = 0;
    state->unk10 = 0x248;
    state->unkC = (void *)0x80800768;
}
