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
M2C_UNK func_800FEA90(s32, M2C_UNK *, M2C_UNK, u8 *);
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_801EAE30;
void func_801472FC(u8 *arg0)
{
  unsigned short new_var;
  if ((*((u8 *) (((s8 *) (&D_801E6EF0)) + 0x3F3F))) != 0)
  {
    *((s16 *) (((s8 *) (&D_801E6EF0)) + 0x3F40)) = (new_var = 0xA51D);
    func_800FEA90(*((s32 *) (((s8 *) arg0) + 4)), &D_801EAE30, 6, arg0);
  }
}
