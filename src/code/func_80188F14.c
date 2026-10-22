// FLAGS: -O2 -g0 -mips2

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
void func_80188F14(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  *((s32 *) (((s8 *) arg0) + 0)) = (s32) ((((arg1 & 0xFF) << 0x10) | 0x08000000) | (arg2 & 0xFFFF));
  *((s32 *) (((s8 *) arg0) + 4)) = (s32) (((arg3 << 13) << 3) | (arg4 & 0xFFFF));
}
