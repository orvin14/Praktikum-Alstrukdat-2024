#include <stdio.h>
#include "point.c"
#include "garis.c"

int main(){
    float b;
    GARIS L;
    POINT P;
    int n;
    int i;
    int sum=0;
    scanf("%f",&b);
    BacaGARIS(&L);
    scanf("%d",&n);
    for (i=0;i<n;i++){
        BacaPOINT(&P);
        if (JarakGARIS(L,P)<=b){
            sum+=1;
        }
    }
    printf("%d\n",sum);
    return 0;
}