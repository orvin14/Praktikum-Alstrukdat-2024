#include <stdio.h>
#include "listdin.h"
//#include "listdin.c"
int main(){
    ListDin l;
    CreateListDin(&l,1000);
    readList(&l);
    int count=0;
    int first=getFirstIdx(l);
    int last=getLastIdx(l);
    for (int i = first; i < last; i++) {
        for (int j = first; j < last-i ; j++) {
            if (ELMT(l, j) > ELMT(l, j + 1)){
                ElType temp = ELMT(l, j);
                ELMT(l, j) = ELMT(l, j + 1);
                ELMT(l, j + 1) = temp;
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}