typedef struct A { char pad[0x144]; void (*fn)(struct A *, int); } A;
void func_80A0448C();
void func_80000560(A *a, int b) { a->fn(a, b); func_80A0448C(a, b); }
