#include "code_funcs.h"
// FLAGS: -O2 -g3 -mips2

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
