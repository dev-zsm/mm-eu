// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 vromStart;
    u32 vromEnd;
} RomFile;

typedef struct {
    u8 pad0[0x74];
    u8 tha[0x18754 - 0x74]; /* 0x74 */
    void *areaTextures;     /* 0x18754 */
} PlayState;

void *THA_AllocTailAlign16(void *tha, u32 size);
s32 func_80080CE0(void *dest, u32 vrom, u32 size);
extern RomFile D_801C3320[];

void Scene_LoadAreaTextures(PlayState *play, s32 fileIndex) {
    u32 vromStart = D_801C3320[fileIndex].vromStart;
    u32 size = D_801C3320[fileIndex].vromEnd - vromStart;

    if (size != 0) {
        play->areaTextures = THA_AllocTailAlign16(&play->tha, size);
        func_80080CE0(play->areaTextures, vromStart, size);
    }
}
