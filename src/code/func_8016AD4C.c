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
s16 func_8016AD4C(s32 arg0, s16 arg1)
{
  u8 *temp_v1;
  int new_var;
  new_var = arg1 * 4;
  temp_v1 = *((u8 **) (((s8 *) (arg0 + new_var)) + 0x800));
  if (temp_v1 != ((void *) 0))
  {
    return *((s16 *) (((s8 *) temp_v1) + 0x130));
  }
  return -1;
}
