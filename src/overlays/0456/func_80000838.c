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
    u8 pad0[0x18875];
    s8 unk18875;
    u8 pad18876[0x4];
    s16 unk1887A;
    u8 pad1887C[0x3];
    s8 unk1887F;
} S_arg0;
M2C_UNK func_800FD548(M2C_UNK, u8 *);
extern s8 D_801EAE45;
void func_80000838(S_arg0 *arg0) {
    int new_var;
    func_800FD548(0x38, arg0);
    new_var = 0x9C10; if (1) { } if (1) { }
    arg0->unk1887A = new_var;
    arg0->unk1887F = 0x40;
    D_801EAE45 = 0x40;
    arg0->unk18875 = 0x14;
}
