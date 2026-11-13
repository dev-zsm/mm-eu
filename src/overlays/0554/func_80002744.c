#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0554.h"
typedef struct { s32 w; u8 pad[0x40]; } Stride44_s32;

M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BA2D48(u8 *, s32);                 /* extern */
M2C_UNK func_80BA2DFC(u8 *);                      /* extern */
M2C_UNK func_80BA2E84(u8 *);                      /* extern */
M2C_UNK func_80BA3114(u8 *, s32);                 /* extern */
extern s32 D_801EFA18;

void func_80002744(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x18C)(thisx, play);
    func_800B763C(play, thisx, 0x41F00000, 0x41400000, 0.0f, 5);
    D_801EFA18 = ((Stride44_s32 *)((u8 *)play + 0x17D98))[M2C_FIELD(thisx, s32 *, 0x1F4)].w + 0x80000000;
    func_80137070((u8 *)thisx + 0x148);
    if (M2C_FIELD(thisx, s32 *, 0x308) != 0xE) {
        func_80BA3114(thisx, play);
    }
    func_80BA2DFC(thisx);
    func_80BA2E84(thisx);
    func_80BA2D48(thisx, play);
}
