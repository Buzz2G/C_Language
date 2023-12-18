#include <stdio.h>
#include <stdlib.h>

// ����һ��������ǩ������������Ľṹ��
typedef struct
{
    char ch;//�ж�union�����int����char
    union
    {
        int i;    // ������Ա
        char c;   // �ַ���Ա
    };
} Data;

// ���㲢�����������ƽ��
char* square(Data d)
{
    char *result;

    switch(d.ch)
    {
    case 'i':
        result = (char*)malloc(sizeof(int));  // Ϊ����ƽ�������㹻�Ŀռ�
        snprintf(result, sizeof(int), "%d", d.i * d.i);
        break;
    case 'c':
        result = (char*)malloc(3);   // Ϊ�����ַ��� null ��ֹ������ռ�
        result[0] = d.c;
        result[1] = d.c;
        result[2] = '\0';
        break;
    default:
        result = NULL; // ������������������ṩһ��Ĭ��ֵ
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
    // ��ȡint����char
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

    //����
    i = 0;
    while(i < count)
    {
        //��c��ֻҪ�Ǵ��ݲ�����arr����string
        char *result = square(str[i]);
        printf("%s ", result);
        free(result);
        i++;
    }

    return 0;
}
