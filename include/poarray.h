#ifndef POARRAY_H
#define POARRAY_H

#define Object int
#define public
#define private 

typedef struct __array_t {
    int size;
    int capacity;
    Object elementData[];
} array_t;


public array_t* Array_Init(int initialSize);
public void Array_Destory(array_t *);
private void Array_Ensure_Capacity(array_t **, int minCapacity);
private void Array_Grow(array_t **, int minCapacity);
public void Array_Add(array_t **, Object element);
public void Array_Delete(array_t **, int index);
public void Array_Print(array_t *); 
public void Array_Destroy(array_t *);
#undef public
#undef private
#undef Object
#endif
