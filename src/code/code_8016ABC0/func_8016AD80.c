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
s32 func_8016AD80(s32 arg0, s16 arg1, s16 arg2)
{
  int new_var;
  u8 *temp_v0;
  new_var = arg1 * 4;
  temp_v0 = *((u8 **) (((s8 *) (arg0 + new_var)) + 0x800));
  if (temp_v0 != ((void *) 0))
  {
    return 0;
  }
  if (arg2 != (*((s16 *) (((s8 *) temp_v0) + 0x130))))
  {
    return 0;
  }
  if ((*((s16 *) (((s8 *) temp_v0) + 0x140))) != 7)
  {
    return 2;
  }
  return 1;
}
