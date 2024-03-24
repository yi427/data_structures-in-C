#ifndef __POTREE_H__
#define __POTREE_H__
#define T void *

typedef struct __node_t {
  T val;
  __node_t *left;
  __node_t *right;
} node_t;

typedef struct __tree_t {
  node_t *root;
} tree_t;

#undef T
#endif
