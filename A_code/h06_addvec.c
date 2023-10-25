#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Vector;

double calculateAngle(double x, double y)
{
    if(x== 0.0&& y==0)
        return 0.0;

    double t = y/x;
    double re = 180*atan(t)/acos(-1.0);
    return re;
}

int main()
{

    Vector p, q, v;
    scanf("%lf %lf", &p.x, &p.y);
    scanf("%lf %lf", &q.x, &q.y);

    v.x = p.x +q.x;
    v.y = p.y +q.y;




    printf("%.2lf\n",calculateAngle(v.x,v.y));


    //printf("%.2lf\n",calculateAngle(1,1));
    return 0;
}
