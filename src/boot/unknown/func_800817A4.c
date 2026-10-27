// FLAGS: -O2 -g3
#include "types.h"

typedef struct {
    s16 unk0;
    u8 pad2[0x1E];
    s16 unk20;
    u8 pad22[0x1E];
    s16 unk40;
    u8 pad42[0x1E];
    u8 unk60[0x18];
    u8 unk78[0x20];
    u8 unk98[0x1B0];
    s32 unk248;
    u8 unk24C;
    u8 pad24D[3];
    u64 unk250;
} Obj;

extern void osCreateMesgQueue(void *a, void *b, s32 c);
extern void osSetEventMesg(s32 a, void *b, s32 c);
extern void osViSetEvent(void *a, s32 b, u8 c);
extern void osCreateThread(void *a, s32 b, void (*c)(Obj *), Obj *d, s32 e, s32 f);
extern void osStartThread(void *a);
extern void func_800816D4(Obj *this);

void func_800817A4(Obj *this, s32 a1, s32 a2, u8 a3) {
    this->unk248 = 0;
    this->unk0 = 1;
    this->unk20 = 4;
    this->unk40 = 3;
    this->unk24C = 0;
    this->unk250 = 0;
    osCreateMesgQueue(this->unk60, this->unk78, 8);
    osSetEventMesg(0xE, this->unk60, 0x29D);
    osViSetEvent(this->unk60, 0x29A, a3);
    osCreateThread(this->unk98, 0x13, func_800816D4, this, a1, a2);
    osStartThread(this->unk98);
}
