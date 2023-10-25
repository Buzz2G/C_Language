#include <stdio.h>
#include <string.h>
#include <math.h>

double calcDistance (int x1, int x2, int y1, int y2)
{
    double result;
    result  = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return result;
}

int main()
{

    char word01[41] ;
    char word02[41] ;
    int x1=0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    scanf("%s", word01);
    scanf("%s", word02);

    for( int i = 0 ; word01 [i] != '\0' ; i++)
    {
        word01[i] = tolower(word01[i]);
        if (word01 [i] == 'a' || word01 [i] == 'e' || word01 [i] == 'i' || word01 [i] == 'o' || word01 [i] == 'u')
        {
            x1++;
        }
        else
        {
            y1++;
        }
    }

    for( int i = 0 ; word02 [i] != '\0' ; i++)
    {
        word02 [i] = tolower(word02[i]);

        if (word02 [i] == 'a' || word02 [i] == 'e' || word02 [i] == 'i' || word02 [i] == 'o' || word02 [i] == 'u')
        {
            x2++;
        }
        else
        {
            y2++;
        }

    }
    //printf("%d,%d,%d,%d\n",x1, x2, y1, y2);
    printf("%.3f\n", calcDistance ( x1, x2, y1, y2));

}
