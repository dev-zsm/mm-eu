typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef s32 M2C_UNK;
typedef struct {
    u8 pad0[0x92];
    s16 unk92;
    u8 pad94[0x192];
    s16 unk226;
} S_arg0;
typedef struct {
    u8 pad0[0x18875];
    s8 unk18875;
    u8 pad18876[0x4];
    s16 unk1887A;
} S_arg1;
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32);
M2C_UNK func_80130A44(u8 *);
s16 func_80130B24(s16);
M2C_UNK func_80137070(s32);
s32 func_80147B34(u8 *);
M2C_UNK func_80147CC4(u8 *);
s32 func_801529DC(s32);
extern M2C_UNK D_801E6EF0;
extern s16 D_801EAE3A;
void func_8000084C(S_arg0 *arg0, S_arg1 *arg1) {
    func_80137070(((u8 *) arg0) + 0x144);
    func_800FFCBC(((u8 *) arg0) + 0x32, arg0->unk92, 1, 0xBB8, 0);
    if ((func_801529DC(((u8 *) arg1) + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_80147CC4(arg1);
        // one line: the ROM's scheduling depends on these stores sharing a single source line
        do { arg1->unk1887A = func_80130B24(arg0->unk226); D_801EAE3A = 0; func_80130A44(arg1); } while (0);
        arg1->unk18875 = 0x14;
        *((u8 *) (((s8 *) (&D_801E6EF0)) + 0xF09)) = (u8) ((*((u8 *) (((s8 *) (&D_801E6EF0)) + 0xF09))) | 4);
    }
}
