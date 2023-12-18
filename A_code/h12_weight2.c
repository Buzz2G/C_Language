#include <stdio.h>
#include <stdlib.h>

// 定义一个包含标签和匿名联合体的结构体
typedef struct
{
    char id;//判断union存的是int还是char

    char c[100];   // 字符串成员
    union
    {
        int i;    // 整数成员

        int weight;    //字符的权重
    };
} Data;

int countStringWeight(char word[])
{
    int result = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        // 逐个字符访问，并将ASCII码加总
        result += (int)word[i];
    }

    return result;
}

Data *read_data(char word[])
{
    // 假设这里是从某处读取数据的实现
    Data *newData = (Data *)malloc(sizeof(Data));


    newData->id = 'c';  //id
    strncpy(newData->c, word, sizeof(newData->c));  //write string
    newData->weight = countStringWeight(word);// write weight


    //这里直接把权重搞定算了，到时候直接权重排序了

    return newData;
}



void print_2ed(Data *str)
{
    int i = 1;
    int count = 0;

    while (1)
    {
        if (str[i].weight != str[i - 1].weight)
        {
            count++;
        }

        if (count == 1)
        {
            printf("%s ", str[i].c);  // print string
        }

        if (count >= 2)
        {
            printf("\n%d ",str[i-1].weight);//print weight
            break;
        }

        i++;
    }
}

// 比较函数，按照 weight 字段从大到小排序
int compare(const void *a, const void *b)
{
    return ((Data *)b)->weight - ((Data *)a)->weight;
}

int main()
{
    int count;//字符串个数
    int i = 0;
    char input[100];//读取的字符串
    char temp[100];
    Data str[100];

    scanf("%d",&count);

    // 读取int或者char
    while(i < count)
    {
        if (scanf("%d", &str[i].i) == 1)//int的处理
        {
            str[i].id = 'i';//写入id
            str[i].weight = abs(str[i].i);//写入weight
            sprintf(input, "%d", str[i].i);//将读入转化成string存入input


            //大于0的时候填上加号赋值到c中
            if(str[i].i >= 0)
            {
                strcpy(temp,"+");
                strcat(temp, input);

                strncpy(str[i].c, temp, sizeof(str[i].c));//填上加号之后的字符串赋值



            }
            //小于0的时候直接赋值赋值到c中
            else
            {
                strncpy(str[i].c, input, sizeof(str[i].c));//负数就直接赋值了
            }
        }
        else    //string的处理
        {

            scanf("%s", &input);
            str[i] = *read_data(input);//直接丢到另外一个方法中自己处理
        }
        i++;
    }


    qsort(str, count, sizeof(Data), compare);//根据weight排序，从大到小排序



    print_2ed(str);

    return 0;
}
