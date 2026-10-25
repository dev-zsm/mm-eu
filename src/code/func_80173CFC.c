#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Buf;

void THA_Reset(Buf *arg0) {
    arg0->unk8 = arg0->unk4;
    arg0->unkC = arg0->unk4 + arg0->unk0;
}
