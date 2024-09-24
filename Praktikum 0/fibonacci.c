#include <stdio.h>
int fibonacci(int n, int a, int b) {
    int value;
    switch (n)
    {
    case 1:
        value=a;
        break;
    case 2:
        value=b;
        break;
    
    default:
        value=fibonacci(n-1,a,b)+fibonacci(n-2,a,b);
        break;
    }
    return value;
}
int main(){
    int n, a, b, value;
    scanf("%d %d %d", &n, &a, &b);
    value=fibonacci(n,a,b);
    printf("%d\n",value);
    return 0;
}    
    