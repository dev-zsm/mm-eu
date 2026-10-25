#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx D_801C2840[];

Gfx* Gfx_SetupDL67(Gfx* dl) {
    // one line: the ROM's scheduling depends on the whole command (incl. the pointer bump) coming from a single source line
    do { Gfx* cmd = dl++; cmd->w0 = 0xDE000000; cmd->w1 = (u32)D_801C2840; } while (0);
    return dl;
}
