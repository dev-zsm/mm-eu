// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul

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
M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);
f32 func_8017A79C(f32);
f32 func_8017A7F0(f32);
M2C_UNK func_80969D58();
extern f32 D_8096A60C;
extern f32 D_8096A610;
extern f32 D_8096A614;
extern f32 D_8096A618;
extern f32 D_8096A61C;
extern f32 D_8096A620;
extern f32 D_8096A624;
void func_800015DC(u8 *arg0, unsigned int arg1) {
    f32 new_var;
    *((s16 *) (((s8 *) arg0) + 0x14A)) = (s16) ((*((s16 *) (((s8 *) arg0) + 0x14A))) - 1);
    new_var = func_8017A79C(((f32) (*((s16 *) (((s8 *) arg0) + 0x14A)))) * D_8096A60C);
    func_800FEE3C(arg0 + 0x58, ((D_8096A610 * new_var) + 1.5f) * D_8096A614, 0x3C23D70B);
    func_800FEE3C(arg0 + 0x5C, ((func_8017A7F0(((f32) (*((s16 *) (((s8 *) arg0) + 0x14A)))) * D_8096A618) * D_8096A61C) + 0.75f) * D_8096A620, 0x3C23D70B);
    func_800FEE3C(arg0 + 0x60, D_8096A624 - (*((f32 *) (((s8 *) arg0) + 0x58))), 0x3C23D70B);
    if ((*((s16 *) (((s8 *) arg0) + 0x14A))) == 0) {
        *((s16 *) (((s8 *) arg0) + 0x14A)) = 0x14;
    }
    if ((*((s16 *) (((s8 *) arg0) + 0x1C))) == 8) {
        func_80969D58(arg0, arg1);
    }
}
