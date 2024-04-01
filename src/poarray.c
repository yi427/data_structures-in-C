#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/poarray.h"

#define public extern
#define private extern
#define Object int

public array_t* Array_Init(int initialCapacity){
    array_t* t = (array_t*)malloc(sizeof(array_t) + initialCapacity * sizeof(Object));
    assert(t != NULL);
    t->capacity = initialCapacity;
    t->size = 0;
    return t;
}

public void Array_Add(array_t **t, Object element){
    assert(t != NULL);
    Array_Ensure_Capacity(t, (*t)->size + 1);
    (*t)->elementData[(*t)->size] = element;
    (*t)->size++;
}

public void Array_Ensure_Capacity(array_t **t, int minCapacity){
    if((*t)->capacity < minCapacity){
        Array_Grow(t, minCapacity);
    }
}
public void Array_Grow(array_t **t, int minCapacity) {
    int oldCapacity = (*t)->capacity;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity < minCapacity) {
        newCapacity = minCapacity;
    }
    array_t *new_t = (array_t *)malloc(sizeof(array_t) + newCapacity * sizeof(Object));
    if (!new_t) {
        return;
    }
    new_t->size = (*t)->size;
    new_t->capacity = newCapacity;
    memcpy(new_t->elementData, (*t)->elementData, (*t)->size * sizeof(Object));
    free(*t);
    *t = new_t;
}

public void Array_Print(array_t *t){
    assert(t);
    for(int i = 0; i < t->size; ++i){
        printf("%d ", t->elementData[i]);
    }
    printf("\n");
}

public void Array_Destory(array_t *t){
    if(t != NULL){
        // free(t->elementData);
        free(t);
    }
}
