#include <stdio.h>
typedef struct
{
    int up;
    int down;
} Rational;

int gcd(int a, int b)
{
    if (a == b)
        return a;
    else if (a > b)
        return gcd(b, a);
    else
        return gcd(a, b - a);
}

void simplify(Rational *r)
{
    int div = gcd(r ->up, r ->down);
    r->up /=  div;
    r->down /=  div;

}


int main()
{
    Rational r1,r2,result;
    scanf("%d %d",r1.up, r1.down);
    scanf("%d %d",r2.up, r2.down);
    result.up = r1.up * r2.up;
    result.down = r1.down * r2.down;
    simplify(&result);
    printf("%d/%d",result.up, result.down);


    return 0;
}
