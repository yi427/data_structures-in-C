#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/poarray.h"
#define public extern
#define private extern

public void Array_Init(array_t *t, int initialSize){
    assert(t != NULL);
    aseert(initialSize != NULL);
    t->capacity = initialSize;
    t->size = 0;
    t->elementData = (Object*)malloc(initialSize * sizeof(Object));
    assert(t->elementData != NULL);
}

public void Array_Add(array_t *t, Object element){
    assert(t);
    t->elementData[size] = element;
    size++;
}

public void Array_Ensure_Capacity(array_t *t, int minCapacity){
    
}

public void Array_Grow(array_t *t, int minCapacity){
    int oldCapacity = t->capacity;
    int newCapacity = oldCapacity + oldCapacity >> 1;
    if (newCapacity < minCapacity) newCapacity = minCapacity;
    // free the memory
    Object *newElementData[] = (Object*)malloc(newCapacity * sizeof(Object));
    for(int i = 0; i < t->size; ++i){
        newElementData[i] = t->elementData[i];
    } 
    free(t->elementData);
    t->elementData = newElementData;
}

public void Array_Print(array_t *t){
    assert(t);
    for(int i = 0; i < size; ++i){
        printf(t->elementData[i]);
    }
}
