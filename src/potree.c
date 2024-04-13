#include <assert.h>
#include <stdlib.h>
#define __GET_STREUCT__
#include "potree.h"

#define public extern
#define private static
#define T void *
#define P(x) *(x)
#define NEW_NODE(V, L, R) (node_t){ \
    .val = V,                       \
    .left = L,                      \
    .right = R  }

typedef struct __node_t {
    T val;
    struct __node_t *left, *right;
} node_t;

typedef struct __tree_t {
    struct __node_t *root;
} tree_t;

// global variable
ref_t GET;

public tree_t* Tree_Construction() {
    tree_t *t = (tree_t*)malloc(sizeof(tree_t));
    return t;
}

public void Tree_Init(tree_t *t, ref_t r) {
    assert(t);
    P(t->root) = NEW_NODE(NULL, NULL, NULL);
    GET = r;
}

