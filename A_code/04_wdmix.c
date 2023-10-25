#include <stdio.h>
#include <string.h>


int main(void)
{
    char str1[80];
    char str2[80];

    scanf("%s", str1);
    scanf("%s", str2);
    if(strlen(str1)== strlen(str2))
    {
        for(int i =0; i<strlen(str1); i++){
            printf("%c%c", str1[i],str2[i]);
        }

        return 0;
    }

    printf("_");
    return 0;

}
