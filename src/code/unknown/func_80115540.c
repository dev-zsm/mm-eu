#include "types.h"

typedef struct {
    u8 pad0[0x210];
    u16 unk210;
    u16 unk212;
    u16 unk214;
    u8 pad216[2];
    f32 unk218;
} View;
typedef struct {
    u8 pad0[0x16BFC];
    u16 unk16BFC;
    u8 pad16BFE[0x16F1C - 0x16BFE];
    u16 unk16F1C;
} Ctx;
extern void func_80115324(View *view, u16 val, s32 a2);
void func_80115540(Ctx *ctx, u16 val) {
    View *v;
    u8 *new_var;
    v = (View *) (((u8 *) ctx) + 0x169E8);
    if (val != (*((u16 *) (((u8 *) ctx) + 0x16BFC)))) {
        v->unk214 = val;
        // one line: the ROM's scheduling depends on these stores sharing a single source line
        v->unk210 = 1; v->unk218 = 0.0f;
        new_var = ((u8 *) ctx) + 0x16F1C;
        func_80115324(v, val, 1);
        if ((*((u16 *) new_var)) != 0) {
            v->unk210 = 3; } }
}
