#ifndef __POTREE_H__
#define __POTREE_H__

#define T void *

// define the function API
typedef void *(*ref_t)(void*);

#ifndef __GET_STREUCT__
typedef struct __node_t {
  T val;
  struct __node_t *left;
  struct __node_t *right;
} node_t;

typedef struct __tree_t {
  node_t *root;
} tree_t;
#else
typedef struct __node_t node_t;
typedef struct __tree_t tree_t;
#endif

tree_t * Tree_Construction();
void Tree_Init(tree_t *, ref_t);
void Tree_Insert(tree_t *);

#undef T
#endif
