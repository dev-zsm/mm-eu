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
s32 func_801243C4(u8 *arg0)
{
  s8 *new_var;
  new_var = (s8 *) (*((u8 **) (((s8 *) arg0) + 0x1CCC)));
  return (*((s32 *) (new_var + 0xA6C))) & 0x800000;
}
