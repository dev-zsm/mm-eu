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
void func_80188F58(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s8 *new_var;
  s8 *new_var2;
  new_var = (s8 *) arg0;
  *((s32 *) (new_var + 0)) = (s32) ((arg1 & 0xFFFFFF) | 0x0A000000);
  new_var2 = new_var + 4;
  *((s32 *) new_var2) = (s32) (((arg2 << 7) << 9) | (arg3 & 0xFFFF));
}
