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
int func_8008F380(u8 *s)
{
  int new_var;
  u8 *p = s;
  if ((*s) != 0)
  {
    new_var = 1;
    do
    {
      p++;
    }
    while ((*(p + new_var)) != (new_var = 0));
  }
  new_var = p - s;
  return new_var;
}
