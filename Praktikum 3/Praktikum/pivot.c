#include <stdio.h>
#include "listdin.h"
//#include "listdin.c"
int main(){
    int i,j,max,min,count=0;
    ListDin l,maxl,minr;
    CreateListDin(&l,1000000);
    readList(&l);
    CreateListDin(&maxl,NEFF(l));
    CreateListDin(&minr,NEFF(l));
    NEFF(minr)=NEFF(l);
    max=ELMT(l,0);
    ELMT(maxl,0)=max;
    for (i=1;i<NEFF(l);i++){
        if (ELMT(l,i)>max){
            max=ELMT(l,i);
        }
        ELMT(maxl,i)=max;
    }
    min=ELMT(l,NEFF(l)-1);
    ELMT(minr,NEFF(l)-1)=min;
    for (i=NEFF(l)-2;i>=0;i--){
        if (ELMT(l,i)<min){
            min=ELMT(l,i);
        }
        ELMT(minr,i)=min;
    }
    NEFF(minr)=NEFF(l);
    for (i=0;i<NEFF(l);i++){
        if (i==0){
            if (ELMT(l,i)<ELMT(minr,i+1)){
                count++;
            }
        } else if (i==NEFF(l)-1){
            if (ELMT(l,i)>ELMT(maxl,i-1)){
                count++;
            }
        } else {
            if ((ELMT(l,i)<ELMT(minr,i+1))&&(ELMT(l,i)>ELMT(maxl,i-1))){
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}