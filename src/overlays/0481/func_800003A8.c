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
    u8 pad0[0x28];
    f32 unk28;
    u8 pad2C[0x3C];
    f32 unk68;
    u8 pad6C[0x8];
    f32 unk74;
    u8 pad78[0x10];
    f32 unk88;
    u8 pad8C[0x94];
    void *unk120;
} S_arg0;
typedef struct {
    s16 unk0;
    u8 pad2[0x28A];
    s16 unk28C;
} S_temp_v1;
M2C_UNK func_800B6490();
extern f32 D_80B1D8A4;
void func_800003A8(S_arg0 *arg0, M2C_UNK arg1) {
    S_temp_v1 *temp_v1;
    if ((arg0->unk88 - D_80B1D8A4) < arg0->unk28) {
        arg0->unk68 = (f32) (arg0->unk68 + arg0->unk74);
        arg0->unk28 = (f32) (arg0->unk28 + arg0->unk68);
        return;
    }
    temp_v1 = arg0->unk120;
    if ((temp_v1 != ((void *) 0)) && (temp_v1->unk0 == 0x1EF)) {
        temp_v1->unk28C = (s16) (temp_v1->unk28C - 1);
    }
    temp_v1 = arg0->unk120;
    func_800B6490();
}
