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
void func_801890D8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  *((s32 *) (((s8 *) arg0) + 0)) = (s32) (((arg4 & 0xFF) << 0x10) | (arg3 & 0xFFFF));
  *((s32 *) (((s8 *) arg0) + 4)) = (s32) (((arg1 << 10) << 6) | (arg2 & 0xFFFF));
}
