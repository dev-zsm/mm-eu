// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_80096CF0;
extern u8 D_800A5FE0[];
extern u8 D_801DB830[];
extern u8 D_802006E0[];
extern u8 D_C8A000[];
extern u8 D_DBF850[];

typedef struct {
    u32 unk0;
    u8 unk4[0x18];
    u8 unk1C[0x18];
} Frame;

void func_80080150(u32 start, u32 end);
void func_8008019C(void);
void func_800801FC(void);
void func_80080C54(u8 *a, u8 *b, u8 *c, s32 d, s32 e, u8 *f, s32 g);
void func_80088070(u8 *p, s32 a, s32 b);
void func_8008F3E0(u8 *a, u8 *b, s32 c);

void func_80080260(void) {
    s32 sp28;
    s32 temp_t6;
    Frame f;

    func_8008F3E0(f.unk4, (u8 *)&f.unk0, 1);
    temp_t6 = D_80096CF0;
    D_80096CF0 = 0;
    sp28 = temp_t6;
    func_80080C54(f.unk1C, D_800A5FE0, D_C8A000, D_DBF850 - D_C8A000, 0, f.unk4, 0);
    func_8008019C();
    func_800801FC();
    func_80088070(f.unk4, 0, 1);
    D_80096CF0 = sp28;
    func_80080150((u32)D_801DB830, (u32)D_802006E0);
}
