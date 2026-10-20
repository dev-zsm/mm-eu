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
    s32 unk250;
    s32 unk254;
} Obj;

extern void func_8008F3E0(void *a, void *b, s32 c);
extern void func_8008D7E0(s32 a, void *b, s32 c);
extern void func_80092580(void *a, s32 b, u8 c);
extern void func_80089FE0(void *a, s32 b, void (*c)(Obj *), Obj *d, s32 e, s32 f);
extern void func_80095950(void *a);
extern void func_800816D4(Obj *this);

void func_800817A4(Obj *this, s32 a1, s32 a2, u8 a3) {
    this->unk248 = 0;
    this->unk0 = 1;
    this->unk20 = 4;
    this->unk40 = 3;
    this->unk24C = 0;
    this->unk254 = 0;
    this->unk250 = 0;
    func_8008F3E0(this->unk60, this->unk78, 8);
    func_8008D7E0(0xE, this->unk60, 0x29D);
    func_80092580(this->unk60, 0x29A, a3);
    func_80089FE0(this->unk98, 0x13, func_800816D4, this, a1, a2);
    func_80095950(this->unk98);
}
