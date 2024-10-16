#include "liststatik.h"
//#include "liststatik.c"
#include <stdio.h>
#include <math.h>
int main(){
    ListStatik l;
    readList(&l);
    boolean tambah=true;
    int n=listLength(l);
    int i;
    i=n-1;
    while (tambah)
    {
        if (i==-1){
            insertFirst(&l,1);
            tambah=false;
        } else{
            ELMT(l,i)+=1;
            if (ELMT(l,i)==10){
                ELMT(l,i)=0;
            } else {
                tambah=false;
            }   
        }
         i--;
    }
    for (i=0;i<listLength(l);i++){
        printf("%d", ELMT(l,i));
        if (i<listLength(l)-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}