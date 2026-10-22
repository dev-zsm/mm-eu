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
M2C_UNK Math_Vec3f_Copy(u8 *, u8 *, u8 *, M2C_UNK **);
extern M2C_UNK D_801C1654;
extern M2C_UNK D_801C1678;
extern f32 D_801D5DF4;
void func_80126F64(u8 *arg0, M2C_UNK **arg1)
{
  s8 temp_v1;
  if (((*((u8 *) (((s8 *) arg0) + 0x14B))) == 1) || ((*((s16 *) (((s8 *) arg0) + 0))) == 0x159))
  {
    Math_Vec3f_Copy(arg0 + 0xAFC, arg0 + 0xBA8, arg0, arg1);
    *arg1 = &D_801C1678;
    return;
  }
  *((f32 *) (((s8 *) (&D_801C1654)) + 0xC)) = (f32) (*((f32 *) (((s8 *) (&D_801C1654)) + 0)));
  temp_v1 = *((s8 *) (((s8 *) arg0) + 0xADD));
  if (temp_v1 >= 3)
  {
    *((s8 *) (((s8 *) arg0) + 0xADD)) = (s8) (temp_v1 + 1);
    *((f32 *) (((s8 *) (&D_801C1654)) + 0xC)) = (f32) ((1.0f + (((f32) (9 - (*((s8 *) (((s8 *) arg0) + 0xADD))))) * D_801D5DF4)) * (*((f32 *) (((s8 *) (&D_801C1654)) + 0xC))));
  }
  *((f32 *) (((s8 *) (&D_801C1654)) + 0xC)) = (f32) ((*((f32 *) (((s8 *) (&D_801C1654)) + 0xC))) + 1200.0f);
  *((f32 *) (((s8 *) (&D_801C1654)) + 0x18)) = (f32) (*((f32 *) (((s8 *) (&D_801C1654)) + 0xC)));
  *arg1 = &D_801C1654;
}
