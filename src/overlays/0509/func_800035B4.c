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
    u8 pad0[0x1CCC];
    void *unk1CCC;
    u8 pad1CD0[0x16BA5];
    s8 unk18875;
    u8 pad18876[0x4];
    s16 unk1887A;
    u8 pad1887C[0x3];
    s8 unk1887F;
} S_arg1;
typedef struct {
    u8 pad0[0xA6C];
    s32 unkA6C;
} S_temp_v0;
typedef struct {
    u8 pad0[0x38];
    s8 unk38;
    u8 pad39[0x273];
    s16 unk2AC;
    u8 pad2AE[0x46];
    s32 unk2F4;
} S_arg0;
M2C_UNK func_800B680C(u8 *);
M2C_UNK func_800F1D6C(s8);
void func_801A4E18(M2C_UNK);
M2C_UNK func_80B5DB68(u8 *, u8 *);
M2C_UNK func_80B5DBB8(u8 *, u8 *, M2C_UNK);
s32 func_80B5E8D0(u8 *, u8 *);
M2C_UNK func_80B5FEA8(u8 *, u8 *, M2C_UNK);
extern M2C_UNK D_801E6EF0;
void func_800035B4(S_arg0 *arg0, S_arg1 *arg1) {
    S_temp_v0 *temp_v0;
    temp_v0 = arg1->unk1CCC;
    temp_v0->unkA6C = (s32) (temp_v0->unkA6C | 0x20);
    func_80B5DB68(arg0, arg1);
    func_80B5DBB8(arg0, arg1, 0);
    arg0->unk2F4 = (s32) (arg0->unk2F4 | 4);
    arg0->unk2AC = (s16) (arg0->unk2AC + 0x3E8);
    func_80B5FEA8(arg0, arg1, 0);
    if ((func_80B5E8D0(arg0, arg1) == 4) && (!((*((u8 *) (((s8 *) (&D_801E6EF0)) + 0xF33))) & 2))) {
        func_800F1D6C(arg0->unk38);
        func_801A4E18(0);
        *((u8 *) (((s8 *) (&D_801E6EF0)) + 0xF33)) = (u8) ((*((u8 *) (((s8 *) (&D_801E6EF0)) + 0xF33))) | 2);
        *((u16 *) (((s8 *) (&D_801E6EF0)) + 0x3F4A)) = 0xFFF3;
        arg1->unk1887A = 0x5400;
        arg1->unk1887F = 0x40;
        *((s8 *) (((s8 *) (&D_801E6EF0)) + 0x3F55)) = 0x40;
        arg1->unk18875 = 0x14;
        *((u16 *) (((s8 *) (&D_801E6EF0)) + 0xC)) = (u16) ((*((u16 *) (((s8 *) (&D_801E6EF0)) + 0xC))) + 0xAAC);
    }
    func_800B680C(arg0);
}
