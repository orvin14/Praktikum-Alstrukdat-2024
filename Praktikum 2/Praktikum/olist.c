#include "liststatik.h"
#include <stdio.h>
int main(){
    IdxType i;
    ListStatik l,frek,unik;
    readList(&l);
    CreateListStatik(&frek);
    CreateListStatik(&unik);
    for (i=0;i<listLength(l);i++){
        if (indexOf(unik,ELMT(l,i))==IDX_UNDEF){
            insertLast(&unik,ELMT(l,i));
        }
    }
    for (i=0;i<listLength(l);i++){
        int index=indexOf(unik,ELMT(l,i));
        if (ELMT(frek,index)==MARK){
            ELMT(frek,index)=1;
        } else {
            ELMT(frek,index)+=1;
        }
    }
    printList(unik);
    printf("\n");
    for (i=0;i<listLength(unik);i++){
        printf("%d %d\n",ELMT(unik,i), ELMT(frek,i));
    }
    return 0;
}