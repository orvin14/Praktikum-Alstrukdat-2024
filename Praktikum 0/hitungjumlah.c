#include <stdio.h>
int main(){
    int i,n,k,b;
    int value;
    scanf("%d %d", &n, &k);
    value=0;
    b=0;
    for (i=0;i<n;i++){
        scanf("%d",&b);
        if (b%k!=0){
            value=value+b;
        }
    }
    printf("%d\n", value);
    return 0;
}