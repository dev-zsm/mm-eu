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
extern unsigned char D_801AF0D4;
u8 func_800A869C(s32 arg0)
{
  if ((arg0 < 0) || (arg0 >= 0x20))
  {
    return 0U;
  }
  return *((&D_801AF0D4) + arg0);
}
