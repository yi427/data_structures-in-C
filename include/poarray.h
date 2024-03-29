#ifndef POARRAY_H
#define POARRAY_H
#include <stdio.h>

#define Object int
#define public
#define private 

typedef struct __array_t {
    int size;
    int capacity;
    Object *elementData[];
} array_t;


public void Array_Init(array_t *, int initialSize);
private void Array_Ensure_Capacity(array_t *, int minCapacity);
private void Array_Grow(array_t *, int minCapacity);
private void Array_Add(array_t *, Object element);
private void Array_Print(array_t *);

#undef public
#undef private
#undef Object
#endif
