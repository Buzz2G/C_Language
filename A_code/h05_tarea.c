#include <stdio.h>
#include <string.h>
#include <math.h>

double calcDistance (int x1, int x2, int y1, int y2)
{
    double result;

    result  = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    return result;
}
double calcSquare (double a, double b,double c)
{
    double result;
    double s = (a+b+c)/2;

    result  = sqrt (s*((s - a) * (s - b) * (s - c)));

    return result;
}


int main()
{

    char word01[41];
    char word02[41];
    char word03[41];
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int y1 = 0;
    int y2 = 0;
    int y3 = 0;

    scanf("%40s", word01);
    scanf("%40s", word02);
    scanf("%40s", word03);


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

    for( int i = 0 ; word03 [i] != '\0' ; i++)
    {
        word03 [i] = tolower(word03[i]);

        if (word03 [i] == 'a' || word03 [i] == 'e' || word03 [i] == 'i' || word03 [i] == 'o' || word03 [i] == 'u')
        {
            x3++;
        }
        else
        {
            y3++;
        }

    }
    //printf("%d,%d,%d,%d\n",x1, x2, y1, y2);
    double a = calcDistance ( x1, x2, y1, y2);
    double b = calcDistance ( x1, x3, y1, y3);
    double c = calcDistance ( x2, x3, y2, y3);

    if (a+b>c && a+c>b && b+c>a)
    {
        //printf("%d,%d,%d,%d,%d,%d\n",x1,x2,x3,y1,y2,y3);

        //printf("%d,%d,%d\n",a,b,c);
        printf("%.3f\n", calcSquare (a, b, c));
    }
    else
    {
        printf("%.3f\n", 0 );
    }

    return 0;
}
