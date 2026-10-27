#include "types.h"
typedef struct { s8 type; u8 pad1; s16 index; void *params; } AnimatedMat;
extern f32 D_801ED328;
extern s32 D_801ED320;
extern s32 D_801ED324;
extern void (*D_801C4898[])(void *, s32, void *);
extern void *func_80100304(void *);

void AnimatedMat_DrawMain(void *play, AnimatedMat *mat, f32 alpha, s32 step, s32 flags) {
    s32 type;
    s32 seg;

    D_801ED328 = alpha;
    D_801ED320 = step;
    D_801ED324 = flags;
    if (mat != NULL) {
        if (mat->type != 0) {
            do {
                type = mat->type;
                seg = (type < 0 ? -type : type) + 7;
                D_801C4898[mat->index](play, seg, func_80100304(mat->params));
                mat++;
            } while (type >= 0);
        }
    }
}
