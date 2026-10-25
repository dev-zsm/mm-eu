#include "types.h"

typedef struct {
    u8 pad0[0x68];
    f32 unk68;
    u8 pad6C[0x24];
    u16 flags;
} Unk90Obj;

s32 func_800B73A0(Unk90Obj *obj, s32 arg1, u32 arg2) {
    if (obj->flags & 1) {
        obj->flags &= ~1;
        obj->flags |= 4;
        if (obj->unk68 < 0.0f && (arg2 & 0x10)) {
            obj->unk68 = 0.0f;
        }
        return 0;
    }
    return 1;
}
