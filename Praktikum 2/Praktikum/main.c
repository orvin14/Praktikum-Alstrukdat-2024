#include "liststatik.h"
//#include "liststatik.c"
#include <stdio.h>
int main(){
    IdxType i;
    ListStatik l,frek,unik;
    readList(&l);
    CreateListStatik(&frek);
    CreateListStatik(&unik);
    for (i=0;i<listLength(l);i++){
        if (ELMT(frek,ELMT(l,i))==MARK){
            ELMT(frek,ELMT(l,i))=1;
            insertLast(&unik,ELMT(l,i));
        } else {
            ELMT(frek,ELMT(l,i))+=1;
        }
    }
    int pertama = 0;
    for (i = 1; i < listLength(unik); i++) {
        if (ELMT(frek, ELMT(unik, i)) > ELMT(frek, ELMT(unik, pertama))) {
            pertama = i;
        }
    }

    int kedua = -1;
    for ( i = 0; i < listLength(unik); i++) {
        if (ELMT(frek, ELMT(unik, i)) == ELMT(frek, ELMT(unik, pertama))) continue;

        if (kedua == -1) {
            kedua = i;
            continue;
        }
        
        if (ELMT(frek, ELMT(unik, i)) > ELMT(frek, ELMT(unik, kedua))) {
            kedua = i;
        }
        else if (ELMT(frek, ELMT(unik, i)) == ELMT(frek, ELMT(unik, kedua))) {
            if (ELMT(unik, i) < ELMT(unik, kedua)) {
                kedua = i;
            }
        } 
    }

    if (kedua == -1) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    else {
        printf("%d\n", ELMT(unik, kedua));
    }
    return 0;
}