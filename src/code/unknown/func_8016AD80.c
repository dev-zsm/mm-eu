#include "code_funcs.h"
// FLAGS: -O2 -g3 -mips2

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
