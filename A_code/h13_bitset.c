# include <stdio.h>

int main(){
    int num;
    int count = 0;
    scanf("%d", &num);

    while(num != 0){
        if( (num%2) == 1){
            printf("%d\n",count);
        }
        num >>= 1;
        count++;
    }
    return 0;
}
