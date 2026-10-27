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
extern unsigned char D_801F3400;
s32 func_80179C60(s32 arg0)
{
  M2C_UNK *new_var;
  if (arg0 < 2)
  {
    new_var = (&D_801F3400) + (arg0 * 4);
    return 0, *new_var;
  }
  return 0;
}
