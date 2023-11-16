#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Car
{
    int x;
    int y;
} car;

struct action
{
    double angle
} act;

char calcuDirecation( double angle)
{
    double derection = fmod(angle, 2 * M_PI);
    if (derection<0){
        derection += 2 * M_PI;
    }
    derection /= M_PI /2;
    if((int)derection == 1){
        return 'N';
    }
    if((int)derection == 2){
        return 'W';
    }
    if((int)derection == 3){
        return 'S';
    }
    if((int)derection == 0){
        return 'E';
    }
}

int main()
{
    car = (struct Car)
    {0, 0};
    act = (struct action)
    {0.0};
    char input;
    int num;

    while(scanf(" %c", &input) == 1  )
    {
        switch (input)
        {
        case 'F'/* forward */:
            scanf("%d", &num);
            car.x += (int)cos(act.angle) * num;
            car.y += (int)sin(act.angle) * num;
            break;
        case 'B'/* backward */:
            scanf("%d", &num);
            car.x -= (int)cos(act.angle) * num ;
            car.y -= (int)sin(act.angle) * num ;
            break;
        case 'L'/* left */:
            act.angle += M_PI / 2.0;
            break;
        case 'R'/* right */:
            act.angle -= M_PI / 2.0;
            break;
        default:
            break;
        }
    }
    printf("%d %d\n",car.x,car.y);
    printf("%c\n",calcuDirecation(act.angle));

    return 0;
}

