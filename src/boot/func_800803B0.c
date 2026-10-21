// FLAGS: -O2 -g3 -mips2
#include "types.h"

#define OS_TV_PAL   0
#define OS_TV_NTSC  1
#define OS_TV_MPAL  2

// Per-TV-type setup, run at boot. Picks the 20-word timing table for the console's
// TV standard (osTvType at 0x80000300, likely libultra). Globals keep their D_ names.
typedef struct {
    u32 w[20];
} TvTable;

#define osTvType D_80000300

extern void func_80095440(s32);
extern s32 D_80000300;
extern s8 D_80096CC0;
extern s32 D_80096CCC;
extern f32 D_80096CD0;
extern f32 D_80096CD4;
extern TvTable D_800981B0;
extern TvTable D_80098200;
extern TvTable D_80098320;
extern f32 D_80098440;
extern TvTable D_8009B610;
extern s8 D_8009B660;

void func_800803B0(void) {
    func_80095440(0xFE);
    D_80096CCC = 0x42;
    D_80096CD0 = 1.0f;
    D_80096CD4 = 1.0f;
    switch (osTvType) {
    case OS_TV_NTSC:
        D_8009B660 = 2;
        D_8009B610 = D_800981B0;
        break;
    case OS_TV_MPAL:
        D_8009B660 = 0x1E;
        D_8009B610 = D_80098200;
        break;
    case OS_TV_PAL:
        D_8009B660 = 0x2C;
        D_8009B610 = D_80098320;
        D_80096CD4 = D_80098440;
        break;
    }
    D_80096CC0 = 1;
}
