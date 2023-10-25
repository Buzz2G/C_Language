#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n < 0){
        printf("%d", n-1);
    }else{
        printf("+%d", n == 0 ? (n) : (n+1));
    }
    return 0;

}
