#include <stdio.h>
int main(){
    int n, i, j, bintang, spasi;
    scanf("%d", &n);
    bintang=2*n-1;
    spasi=0;
    
    for (i=0;i<n;i++){
        for (j=0;j<spasi;j++){
            printf(" ");
        }
        for (j=0;j<bintang;j++){
            printf("*");
        }
        bintang-=2;
        spasi++;
        printf("\n");
    }

    return 0;
}