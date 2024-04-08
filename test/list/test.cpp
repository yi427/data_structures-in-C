#include "polist.h"
#include <cstdlib>
#include <limits.h>
#include <list>
#include <assert.h>
#include <iterator>
#include "../tester.hpp"

int* GET(int *i) {
  int *res = (int *)malloc(sizeof(int));
  *res = *i;
  return res;
}

using namespace std;

int
main() {
  tester perform;
  list_t *t = List_Construction();
  List_Init(t, (ref_t)GET);
  list<int> l;
  constexpr int M = 1e6;
  auto test = [&](int pos) {
    int val = pick(INT_MIN, INT_MAX);
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
  };
  for (int i = 0; i < M; ++i) {
    perform.start(0, 8, test);
  }
  List_Clean(t);
}

