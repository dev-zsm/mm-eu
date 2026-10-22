// FLAGS: -O2 -g3

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
typedef struct 
{
  u8 pad0[0x60];
  u8 unk60[0x18];
} Obj;
extern void osRecvMesg(void *a, s32 *b, s32 c);
extern void IrqMgr_HandleRetrace(Obj *this);
extern void IrqMgr_HandlePreNMI(Obj *this);
extern void IrqMgr_HandlePRENMI450(Obj *this);
extern void IrqMgr_HandlePRENMI480(Obj *this);
extern void IrqMgr_HandlePRENMI500(Obj *this);
void func_800816D4(Obj *this)
{
  s32 cmd;
  u8 *p;
  s32 done;
  done = (cmd = 0);
  p = this->unk60;
  while (done == 0)
  {
    osRecvMesg(p, &cmd, 1);
    switch (cmd)
    {
      case 0x29A:
        IrqMgr_HandleRetrace(this);
        break;

      case 0x29D:
        IrqMgr_HandlePreNMI(this);
 do { } while (0);
        break;

      case 0x29F:
        IrqMgr_HandlePRENMI450(this);
        break;

      case 0x2A0:
        IrqMgr_HandlePRENMI480(this);
        break;

      case 0x2A1:
        IrqMgr_HandlePRENMI500(this);
        break;

    }

  }

}
