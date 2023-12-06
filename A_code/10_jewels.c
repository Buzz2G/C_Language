#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Coord;

int find_jewels(int map[][] ,Coord me){

}

Coord find_me(int map[][], int col,int row){
    Coord me;
     for(int i = 0; i < col ; i++ )
    {
        for(int j = 0 ; j < row ; j++)
        {
            if(map[i][j] == -1)
            {
                me.x = i;
                me.y = j;

            }
        }
    }
    return me;
}


int main ()
{
    int col;
    int row;
    int s_col = -1;
    int s_row = -1;
    int dis = 0;
    int temp;


    scanf("%d", &col);
    scanf("%d", &row);

    int map[col][row];

    for(int i = 0; i < col ; i++ )
    {
        for(int j = 0 ; j < row ; j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == -1)
            {
                s_col = i;
                s_row = j;

            }
        }
    }

    if(s_col != -1)
    {
        for(int i = 0; i < col ; i++ )
        {
            for(int j = 0 ; j < row ; j++)
            {
                if(map[i][j] > 0)
                {
                    temp = abs(i - s_col) + abs(j - s_row);
                    if(dis == 0){
                        dis = temp;
                    }
                    if(dis > temp)
                    {
                        dis = temp;
                    }
                }
            }
        }
        printf("%d", dis);
    }
    else{
            printf("%d", dis);
    }






}
