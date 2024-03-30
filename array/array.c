#include <stdlib.h>
#include "poarray.h"
int main(){
    array_t *t = Array_Init(15);
    for(int i = 0; i < 30; ++i){
        Array_Add(&t, i);    
    }
    Array_Print(t);
    Array_Destory(t);
    return 0;
}
