#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x39];
    /* 0x0039 */ s8 unk39;
    /* 0x003A */ u8 pad3A[0x3F2A - 0x3A];
    /* 0x3F2A */ s16 unk3F2A;
    /* 0x3F2C */ u8 pad3F2C[2];
    /* 0x3F2E */ s16 unk3F2E;
    /* 0x3F30 */ u8 pad3F30[4];
    /* 0x3F34 */ s16 unk3F34;
} Struct_801E6EF0;

extern Struct_801E6EF0 D_801E6EF0;
extern void Audio_PlaySfx(s32);

void func_801162AC(void) {
    s32 lo;
    s32 hi;

    if (D_801E6EF0.unk3F2A != 0) {
        D_801E6EF0.unk39 += 4;
        Audio_PlaySfx(0x401F);
        lo = D_801E6EF0.unk39;
        hi = D_801E6EF0.unk3F2E;
        if (lo >= hi) {
            D_801E6EF0.unk39 = hi;
            D_801E6EF0.unk3F34 = 0;
            D_801E6EF0.unk3F2A = 0;
        } else {
            D_801E6EF0.unk3F34 -= 4;
            if (D_801E6EF0.unk3F34 <= 0) {
                D_801E6EF0.unk3F34 = 0;
                D_801E6EF0.unk3F2A = 0;
            }
        }
    }
}
