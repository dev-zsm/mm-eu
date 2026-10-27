#include "types.h"

typedef struct {
    u16 unk0;
    u8 pad2[6];
} Entry;

typedef struct {
    u8 pad0[0x18858];
    Entry *unk18858;
} Play;

u16 func_8016ADEC(Play *arg0, s32 arg1) {
    Entry *e = &arg0->unk18858[arg1];

    return e->unk0;
}
