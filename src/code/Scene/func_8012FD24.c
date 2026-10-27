#include "types.h"

typedef struct {
    u8 pad0[0x10];
    void* unk10;
    u8 pad14[4];
    void* unk18;
    void* unk1C;
    void* unk20;
    u8 pad24[4];
    void* unk28;
} CollHeader;

typedef struct {
    u8 pad0[4];
    void* unk4;
} SceneCmd;

extern void* func_80100304(void* p);
extern void BgCheck_Allocate(void* colCtx, void* play, CollHeader* colHeader);

void Scene_CommandCollisionHeader(u8* play, SceneCmd* cmd) {
    CollHeader* colHeader = func_80100304(cmd->unk4);

    colHeader->unk10 = func_80100304(colHeader->unk10);
    colHeader->unk18 = func_80100304(colHeader->unk18);
    if (colHeader->unk1C != NULL) {
        colHeader->unk1C = func_80100304(colHeader->unk1C);
    }
    if (colHeader->unk20 != NULL) {
        colHeader->unk20 = func_80100304(colHeader->unk20);
    }
    if (colHeader->unk28 != NULL) {
        colHeader->unk28 = func_80100304(colHeader->unk28);
    }
    BgCheck_Allocate(play + 0x830, play, colHeader);
}
