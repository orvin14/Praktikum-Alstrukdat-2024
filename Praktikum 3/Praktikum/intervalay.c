#include <stdio.h>
#include "listdin.h"
//#include "listdin.c"
void mergeIntervals(ListDin *l) {
    if (NEFF(*l) == 0) return;

    ListDin merged;
    CreateListDin(&merged, CAPACITY(*l));

    insertLast(&merged, ELMT(*l, 0)); // start pertama
    insertLast(&merged, ELMT(*l, 1)); // stop pertama

    for (int i = 2; i < NEFF(*l); i += 2) {
        int start = ELMT(*l, i);
        int stop = ELMT(*l, i + 1);

        //tidak overlap
        if (start > ELMT(merged, NEFF(merged) - 1)) {
            insertLast(&merged, start);
            insertLast(&merged, stop);
        } else {
            // overlap, merge dengan interval terakhir
            ELMT(merged, NEFF(merged) - 1) = stop > ELMT(merged, NEFF(merged) - 1) ? stop : ELMT(merged, NEFF(merged) - 1);
        }
    }
    copyList(merged, l);
    dealocateList(&merged);
}

void insertInterval(ListDin *l, int newStart, int newStop) {
    ListDin temp;
    CreateListDin(&temp, CAPACITY(*l));

    boolean added = false;
    for (int i = 0; i < NEFF(*l); i += 2) {
        int start = ELMT(*l, i);
        int stop = ELMT(*l, i + 1);

        if (!added && newStart < start) {
            insertLast(&temp, newStart);
            insertLast(&temp, newStop);
            added = true;
        }

        insertLast(&temp, start);
        insertLast(&temp, stop);
    }

    if (!added) {
        insertLast(&temp, newStart);
        insertLast(&temp, newStop);
    }
    mergeIntervals(&temp);

    copyList(temp, l);
    dealocateList(&temp);
}

int main(){
    ListDin l;
    int newStart,newStop;
    CreateListDin(&l,1000);
    readList(&l);
    scanf("%d %d",&newStart,&newStop);
    insertInterval(&l,newStart,newStop);
    for (int i=0;i<=NEFF(l)-1;i++){
        if (i!=0 && i<NEFF(l)){
            printf(" ");
        }
        printf("%d", ELMT(l,i));
    }
    printf("\n");
    dealocateList(&l);
    return 0;
}