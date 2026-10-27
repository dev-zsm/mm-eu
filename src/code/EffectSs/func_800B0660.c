// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad[0x60]; } Ss;
typedef struct { Ss *data; s32 searchStart; s32 size; } Tbl;
typedef struct { u8 pad0[0x10]; s32 unk10; u8 pad14[8]; } Ent;
extern Tbl D_801AF260;
extern Ent D_801AF360[0x27];
void EffectSs_Delete(Ss *);
void ZeldaArena_Free(s32);
void EffectSs_ClearAll(s32 play) {
    Ss *p;
    Ent *e;
    s32 i;
    D_801AF260.data = 0;
    D_801AF260.searchStart = 0;
    D_801AF260.size = 0;
    for (p = &D_801AF260.data[0]; p < &D_801AF260.data[D_801AF260.size]; p++) {
        EffectSs_Delete(p);
    }
    e = D_801AF360;
    for (i = 0; i != 0x27; i++) {
        if (e->unk10 != 0) {
            ZeldaArena_Free(e->unk10);
        }
        e->unk10 = 0;
        e++;
    }
}
