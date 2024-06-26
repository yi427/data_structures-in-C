#include "povector.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define T int
#define ST true
#define Get(I) Vector_Get(v, I)
#define Set(I, ITEM) Vector_Set(v, I, ITEM)
#define Size() Vector_Size(v)
#define Empty() Vector_Empty(v)
#define CHECK(c, a)                                                            \
  if (c)                                                                       \
  assert(a)

static void resize(Vector_t *, size_t);

typedef struct __Vector_t {
  size_t c;
  Data_t *d;
} Vector_t;

typedef struct __Data_t {
  size_t size;
  T data[];
} Data_t;

extern Vector_t *Vector_Construction() {
  Vector_t *v = (Vector_t *)malloc(sizeof(Vector_t));
  assert(v);
  v->d = (Data_t *)malloc(sizeof(Data_t) + sizeof(T));
  assert(v->d);
  v->c = 1;
  v->d->size = 0;
  return v;
}

extern void Vector_Deconstruction(Vector_t *v) {
  CHECK(ST, v);
  free(v->d);
  free(v);
}

extern void Vector_Push_Back(Vector_t *v, T item) {
  if (v->c == Size())
    resize(v, v->c * 2);
  Set(v->d->size, item);
  v->d->size++;
}

extern void Vector_Push_Front(Vector_t *v, T item) {
  int l = Size();
  if (v->c == (size_t)l)
    resize(v, v->c * 2);
  for (int i = l - 1; i >= 0; --i) {
    Set(i + 1, Get(i)); // v[i+1] = v[i]
  }
  Set(0, item); // v[0] = item
  v->d->size++;
}

extern void Vector_Pop_Back(Vector_t *v) {
  if (Empty()) {
    perror("The vector is empty");
    exit(1);
  }
  v->d->size--;
}

extern void Vector_Pop_Front(Vector_t *v) {
  if (Empty()) {
    perror("The vecotr is empty");
    exit(-1);
  }
  int l = Size();
  for (int i = 0; i < l - 1; ++i) {
    Set(i, Get(i + 1));
  }
  v->d->size--;
}

extern T Vector_Get(Vector_t *v, size_t pos) {
  CHECK(ST, v && v->d && pos < v->d->size);
  return v->d->data[pos];
}

extern void Vector_Set(Vector_t *v, size_t pos, T val) {
  CHECK(ST, v && v->d && pos < v->c);
  v->d->data[pos] = val;
}

extern size_t Vector_Size(Vector_t *v) { return v->d->size; }
extern bool Vector_Empty(Vector_t *v) { return v->d->size == 0; }

static void resize(Vector_t *v, size_t c) {
  CHECK(ST, v && v->d);
  v->c = c; // update the cap
  Data_t *temp = (Data_t *)malloc(sizeof(Data_t) + sizeof(T) * c);
  assert(temp);
  Data_t *origin = v->d;
  temp->size = origin->size;
  size_t len = v->d->size;
  for (size_t i = 0; i < len; ++i) {
    temp->data[i] = origin->data[i];
  }
  v->d = temp;
  free(origin);
}

#undef ST
#undef CHECK
#undef Set
#undef Get
#undef Size
#undef Empty
#undef T
