#include <stdio.h>
#include <string.h>


char opration[100];
// �ַ���������ӳ���ϵ
char charArray[] = {'D', 'A', 'S', 'H'};
// ����ӳ������ַ�ӳ�䵽��Ӧ�ĺ���ָ��


int D(int num)
{
    return num * 2;
};

int A(int num)
{
    return num + 1;
}

int S(int num)
{
    return num -1;
}
int H(int num)
{
    return num / 2;
}

int (*methodMap[4])() = {D, A, S, H};

int dash(int num)
{
    for (int i = 0; opration[i] != '\0'; ++i)
    {
       (opration[i] == 'D') ? num = methodMap[0](num) : 0 ;
       (opration[i] == 'A') ? num = methodMap[1](num) : 0 ;
       (opration[i] == 'S') ? num = methodMap[2](num) : 0 ;
       (opration[i] == 'H') ? num = methodMap[3](num) : 0 ;
    }

    return num;
}



int main()
{
    const int number;
    scanf("%d", &number);
    scanf("%98s", opration);
    printf("%d",dash(number));

}
