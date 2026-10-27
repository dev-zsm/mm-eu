#include "types.h"

typedef struct {
    u8 pad0[0x74];
    f32 unk74;
    u8 pad78[0xA6C - 0x78];
    u32 unkA6C;
    u8 pad_A70[0x1CCC - 0xA70];
    void *unk1CCC;
} Obj2;

typedef struct {
    u8 pad0[0x8C];
    Obj2 *unk8C;
    Obj2 *unk90;
    u8 pad94[4];
    f32 unk98;
    u8 pad9C[0x104 - 0x9C];
    f32 unk104;
} Obj1;

extern f32 D_801D4E64;
extern f32 func_800CAFC0(f32 a);

s32 func_800CB700(Obj1 *arg0) {
    s32 t;

    if (arg0->unk8C->unk1CCC == arg0->unk90) {
        t = func_800CAFC0(arg0->unk98 - arg0->unk104) < 11.0f;
        if (t == 0) {
            t = D_801D4E64 < arg0->unk90->unk74;
            if (t == 0) {
                t = (arg0->unk90->unkA6C & 0x200000) != 0;
            }
        }
        return t;
    }
    return 1;
}
