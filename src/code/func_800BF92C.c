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
void func_800BF92C(s16 *arg0)
{
  int new_var;
  new_var = 0xFFFF ^ 0;
  *arg0 = new_var;
}
