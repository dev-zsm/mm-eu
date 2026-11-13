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
    u8 pad0[0x1681C];
    s32 unk1681C;
    u8 pad16820[0x116];
    u16 unk16936;
} S_arg1;
typedef struct {
    u8 pad0[0x304];
    s16 unk304;
    u8 pad306[0xE];
    void *unk314;
} S_arg0;
M2C_UNK func_80152978(u8 *, M2C_UNK);
s32 func_801529DC(u8 *);
M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);
M2C_UNK func_80B8460C(u8 *);
M2C_UNK func_80B84A10(u8 *, M2C_UNK);
extern M2C_UNK D_80B84BBC;
extern M2C_UNK D_80B84CC0;
void func_80000A10(S_arg0 *arg0, S_arg1 *arg1) {
    func_80B8460C(arg0);
    if (1) {
        if (arg1->unk16936 == 3) {
            arg0->unk314 = &D_80B84CC0;
            arg0->unk304 = 6;
            func_80B84584(arg0, 1, 0);
            func_80152978(arg1, 0x3E);
            func_80B84A10(arg0, 1);
            return;
        }
        if (func_801529DC(((u8 *) arg1) + 0x4908) == 0xB) {
            arg1->unk1681C = 0;
            arg0->unk314 = &D_80B84BBC;
            arg0->unk304 = 3;
            func_80B84584(arg0, 5, 2);
            func_80B84A10(arg0, 0);
        }
    }
}
