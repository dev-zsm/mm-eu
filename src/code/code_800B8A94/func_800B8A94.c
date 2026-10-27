// FLAGS: -O2 -g3 -mips2

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
void func_800B8A94(u8 *arg0, M2C_UNK arg1, f32 arg2, s16 arg3, f32 arg4, s32 arg5, s32 arg6)
{
  u8 *temp_v0;
  temp_v0 = *((u8 **) (((s8 *) arg0) + 0x1CCC));
  *((s8 *) (((s8 *) temp_v0) + 0xB74)) = (s8) arg6;
  *((s8 *) (((s8 *) temp_v0) + 0xB75)) = (s8) arg5;
  *((f32 *) (((s8 *) temp_v0) + 0xB78)) = arg2;
  *((s16 *) (((s8 *) temp_v0) + 0xB76)) = arg3;
  *((f32 *) (((s8 *) temp_v0) + 0xB7C)) = arg4;
}
