// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 *unk0;
    s32 pad4;
    void (*unk8)(void *);
} GameStateDestroy;

void AudioMgr_StopAllSfxExceptSystem(void);
void Audio_Update(void);
void func_80088070(u8 *, s32, s32);
void Rumble_Destroy(void);
void func_801785A4(void *);
void VisCvg_Destroy(void *);
void VisZBuf_Destroy(void *);
void VisMono_Destroy(void *);
void ViMode_Destroy(void *);
void THA_Destroy(void *);
void GameAlloc_Cleanup(void *);
extern u8 D_801EF880[];
extern u8 D_801EF8A0[];
extern u8 D_801EF8B0[];
extern u8 D_801EF8C0[];
extern u8 D_801EF8D8[];

void GameState_Destroy(GameStateDestroy *a0) {
    AudioMgr_StopAllSfxExceptSystem();
    Audio_Update();
    func_80088070(a0->unk0 + 0x5C, 0, 1);
    if (a0->unk8 != NULL) {
        a0->unk8(a0);
    }
    Rumble_Destroy();
    func_801785A4(D_801EF880);
    VisCvg_Destroy(D_801EF8A0);
    VisZBuf_Destroy(D_801EF8B0);
    VisMono_Destroy(D_801EF8C0);
    ViMode_Destroy(D_801EF8D8);
    THA_Destroy((u8 *)a0 + 0x74);
    GameAlloc_Cleanup((u8 *)a0 + 0x84);
}
