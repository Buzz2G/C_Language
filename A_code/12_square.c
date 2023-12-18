#include <stdio.h>
#include <stdlib.h>

// 定义一个包含标签和匿名联合体的结构体
typedef struct
{
    char ch;//判断union存的是int还是char
    union
    {
        int i;    // 整数成员
        char c;   // 字符成员
    };
} Data;

// 计算并返回数据项的平方
char* square(Data d)
{
    char *result;

    switch(d.ch)
    {
    case 'i':
        result = (char*)malloc(sizeof(int));  // 为整数平方分配足够的空间
        snprintf(result, sizeof(int), "%d", d.i * d.i);
        break;
    case 'c':
        result = (char*)malloc(3);   // 为两个字符和 null 终止符分配空间
        result[0] = d.c;
        result[1] = d.c;
        result[2] = '\0';
        break;
    default:
        result = NULL; // 处理其他情况，或者提供一个默认值
        break;
    }

    return result;
}

int main()
{
    int count;
    Data str[100];

    scanf("%d", &count);

    int i = count - 1;
    // 读取int或者char
    while(i >= 0)
    {
        if (scanf("%d", &str[i].i) == 1)
        {
            str[i].ch = 'i';
        }
        else
        {
            scanf("%c", &str[i].c);
            str[i].ch = 'd';
        }
        i--;
    }

    //归零
    i = 0;
    while(i < count)
    {
        //在c中只要是传递参数是arr或者string
        char *result = square(str[i]);
        printf("%s ", result);
        free(result);
        i++;
    }

    return 0;
}
