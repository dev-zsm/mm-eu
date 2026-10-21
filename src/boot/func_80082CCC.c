// FLAGS: -O2 -g3 -mips2 -trapuv

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
extern u32 D_80098BE4;
extern u32 D_80098BEC;
extern u32 D_80098BF8;
extern u32 D_80098C00;
extern void func_80082138();
extern void func_800843FC();
extern void func_8008487C();
void func_80082CCC(u32 *arg0, u32 arg1, s32 arg2)
{
  u32 var_s0 = arg1;
  u32 *var_s1;
  u32 *var_a3;
  u32 temp_a3;
  s32 var_s2;
  s32 var_s0_2;
  u32 temp_s0;
  if (arg1 < 0x80000000U)
  {
    var_s0 = 0x80000000;
  }
  if (var_s0 >= 0x807FFF01U)
  {
    var_s0 = 0x807FFF00;
  }
  var_s0 &= ~3;
  temp_s0 = var_s0;
  var_s1 = (u32 *) temp_s0;
  func_80082138();
  func_800843FC(-2, 0);
  if (arg0 != 0)
  {
    var_a3 = arg0;
  }
  else
  {
    var_a3 = &D_80098BEC;
  }
  func_8008487C(0x24, 0x12, &D_80098BE4, var_a3, temp_s0);
  if (temp_s0 >= 0x80000000U)
  {
    var_s2 = 0x1C;
    if (temp_s0 < 0xC0000000U)
    {
      do
      {
        func_8008487C(0x18, var_s2, &D_80098BF8, var_s1);
        var_s0_2 = 0x52;
        if ((var_s1 && var_s1) && var_s1)
        {
        }
        do
        {
          func_8008487C(var_s0_2, var_s2, &D_80098C00, *(var_s1++));
          var_s0_2 += 0x34;
        }
        while (var_s0_2 != 0x122);
        var_s2 += 9;
      }
      while (var_s2 != 0xE2);
    }
  }
  func_800843FC(0, 0);
}
