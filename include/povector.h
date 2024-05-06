#ifndef __PO_VECTOR__
#define __PO_VECTOR__
#include <stdbool.h>
#include <sys/types.h>

#define T int

#ifndef __GET_STREUCT__

#else
#endif
typedef struct __Vector_t Vector_t;
typedef struct __Data_t Data_t;

Vector_t* Vector_Construction();
void Vector_Deconstruction(Vector_t *);

void Vector_Push_Back(Vector_t *, T);
void Vector_Push_Front(Vector_t *, T);
void Vector_Pop_Back(Vector_t *);
void Vector_Pop_Front(Vector_t *);

T Vector_Get(Vector_t *, size_t);
void Vector_Set(Vector_t *, size_t, T);

bool Vector_Empty(Vector_t *);
size_t Vector_Size(Vector_t *);

#undef T
#endif
