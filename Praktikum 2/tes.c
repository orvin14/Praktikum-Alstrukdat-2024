#include "liststatik.c"
#include <stdio.h>
int main(){
    ListStatik l1,l2;
    ElType max,min,val;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    readList(&l1);
    readList(&l2);
    insertFirst(&l1,69);
    insertAt(&l1,420,1);
    insertLast(&l1,24434);
    printf("%d\n",getFirstIdx(l1));
    printf("%d\n",getLastIdx(l1));
    extremeValues(l1,&max,&min);
    printList(l1);
    sortList(&l1,true);
    printList(l1);
    sortList(&l1,false);
    printList(l1);
    deleteFirst(&l1,&val);
    deleteAt(&l1,&val,0);
    printf("%d\n",getLastIdx(l1));
    printf("Last element before deletion: %d\n", ELMT(l1, getLastIdx(l1)));
    deleteLast(&l1,&val);
    printf("%d\n",getLastIdx(l1));
    printf("Last element after deletion: %d\n", ELMT(l1, getLastIdx(l1)));
    printf("%d\n",listLength(l1));
    printf("%d\n",getFirstIdx(l1));
    printf("%d\n",getLastIdx(l1));
    extremeValues(l1,&max,&min);
    printf("%d\n",max);
    printf("%d\n",min);
    printList(plusMinusList(l1,l2,true));
    printList(plusMinusList(l1,l2,false));
    printList(l1);
    boolean tes4= isListEqual(l1,l2);
    if (tes4){
        printf("true\n");
    } else{
        printf("false\n");
    }
    /*printf("%d\n",indexOf(l1,7));
    printf("%d\n", ELMT(l1,0));
    
    
    boolean tes=isIdxValid(l1,99);
    if (tes){
        printf("true\n");
    } else{
        printf("false\n");
    }
    boolean tes1=isIdxEff(l1,0);
    if (tes1){
        printf("true\n");
    } else{
        printf("false\n");
    }
    boolean tes2=isEmpty(l1);
    if (tes2){
        printf("true\n");
    } else{
        printf("false\n");
    }
    boolean tes3=isFull(l1);
    if (tes3){
        printf("true\n");
    } else{
        printf("false\n");
    }*/
    return 0;
}