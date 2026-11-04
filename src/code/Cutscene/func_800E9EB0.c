#include "types.h"

typedef struct {
    u8 pad0[8];
    u8 unk8;
} CutsceneCmd;

extern s32 D_801E6EF8;
extern void (*D_801BBC64[])(void *a0, CutsceneCmd *cmd);

void Cutscene_UpdateManual(void *a0, CutsceneCmd *cmd) {
    if (D_801E6EF8 < 0xFFF0) {
        D_801BBC64[cmd->unk8](a0, cmd);
    }
}
