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
typedef struct Node
{
  s16 type;
  s16 flag;
  u32 val;
  struct Node *next;
} Node;
extern void func_800871FC(void);
extern void func_80087224(void);
void func_800878AC(Node **head, u32 *a1, u32 *a2, u32 *a3)
{
  Node *node;
  func_800871FC();
  *a1 = 0;
  *a2 = 0;
  *a3 = 0;
  for (node = *head; node != ((void *) 0); node = node->next)
  {
    if (node->flag != 0)
    {
      *a2 += node->val;
      if ((*a1) < node->val)
      {
        *a1 = node->val;
      }
    }
    else
    {
      *a3 += node->val;
      if (!head)
      {
      }
    }
  }

  func_80087224();
}
