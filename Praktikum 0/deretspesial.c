#include <stdio.h>
int main() {
    int a, b,temp;
    scanf("%d %d", &a, &b);
    do
    {
        printf("%d",a);
        if (a%2!=0){
            a+=1;
        }
        else {
            a*=2;
        }
        temp=a;
        if (temp<b){
            printf(" ");
        }
    } while (b>=a);
    printf("\n");
    return 0;
}