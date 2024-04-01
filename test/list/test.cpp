#include "polist.h"
#include <stdlib.h>
#include <random>
#include <list>
#include <assert.h>
#include <iterator>

using namespace std;
// 摘录 深度探索 C++ 14
std::default_random_engine& global_urng()
{
    static std::default_random_engine u{};
    return u;
}

void randomize()
{
    static std::random_device rd{};
    global_urng().seed(rd());
}

int pick(int from, int to) {
    static std::uniform_int_distribution<> d{};
    using parm_t = decltype(d)::param_type;
    return d(global_urng(), parm_t{from, to});
}

int *ref(int *t) {
  int *res = (int *)malloc(sizeof(int));
  *res = *t;
  return res;
}

list_t *t = List_Construction();
list<int> l;

void TEST(int pos) {
  int val = pick(-0x3f3f3f, 0x3f3f3f);
  int si = size(l);
  switch(pos) {
    case 0: l.push_front(val); List_Push_Front(t, &val); break;
    case 1: l.push_back(val); List_Push_Back(t, &val); break;
    case 3: if (size(l) == 0) break; assert(l.front() == *(int *)List_Front(t)); break;
    case 4: if (size(l) == 0) break; assert(l.back() == *(int *)List_Back(t)); break;
    case 5: if (size(l) == 0) break; l.pop_back(); List_Pop_Back(t); break;
    case 6: if (size(l) == 0) break; l.pop_front(); List_Pop_Front(t); break;
    case 7: {
              int ins = pick(0, size(l));
              auto iter = begin(l);
              for (int i = 0; i < ins; ++i) iter++;
              l.insert(iter, val);
              List_Insert(t, ins, &val);
              break;
    }
    case 8: {
              if (si == 0) break;
              int ins = pick(0, si - 1);
              auto iter = begin(l);
              for (int i = 0; i < ins; ++i) iter++;
              l.erase(iter);
              List_Erase(t, ins);
              break;
    }
  }
}

void print(int *t) {
  printf("%d->", *t);
}

int
main() {
  List_Init(t, (ref_t)ref);
  randomize();
  constexpr int M = 1e6;
  for (int i = 0; i < M; ++i) {
    int pos = pick(0, 9);
    TEST(pos);
  }
  List_Clean(t);
}

