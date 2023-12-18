#include <stdio.h>
#include <stdlib.h>

// ����һ��������ǩ������������Ľṹ��
typedef struct
{
    char id;//�ж�union�����int����char

    char c[100];   // �ַ�����Ա
    union
    {
        int i;    // ������Ա

        int weight;    //�ַ���Ȩ��
    };
} Data;

int countStringWeight(char word[])
{
    int result = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        // ����ַ����ʣ�����ASCII�����
        result += (int)word[i];
    }

    return result;
}

Data *read_data(char word[])
{
    // ���������Ǵ�ĳ����ȡ���ݵ�ʵ��
    Data *newData = (Data *)malloc(sizeof(Data));


    newData->id = 'c';  //id
    strncpy(newData->c, word, sizeof(newData->c));  //write string
    newData->weight = countStringWeight(word);// write weight


    //����ֱ�Ӱ�Ȩ�ظ㶨���ˣ���ʱ��ֱ��Ȩ��������

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

// �ȽϺ��������� weight �ֶδӴ�С����
int compare(const void *a, const void *b)
{
    return ((Data *)b)->weight - ((Data *)a)->weight;
}

int main()
{
    int count;//�ַ�������
    int i = 0;
    char input[100];//��ȡ���ַ���
    char temp[100];
    Data str[100];

    scanf("%d",&count);

    // ��ȡint����char
    while(i < count)
    {
        if (scanf("%d", &str[i].i) == 1)//int�Ĵ���
        {
            str[i].id = 'i';//д��id
            str[i].weight = abs(str[i].i);//д��weight
            sprintf(input, "%d", str[i].i);//������ת����string����input


            //����0��ʱ�����ϼӺŸ�ֵ��c��
            if(str[i].i >= 0)
            {
                strcpy(temp,"+");
                strcat(temp, input);

                strncpy(str[i].c, temp, sizeof(str[i].c));//���ϼӺ�֮����ַ�����ֵ



            }
            //С��0��ʱ��ֱ�Ӹ�ֵ��ֵ��c��
            else
            {
                strncpy(str[i].c, input, sizeof(str[i].c));//������ֱ�Ӹ�ֵ��
            }
        }
        else    //string�Ĵ���
        {

            scanf("%s", &input);
            str[i] = *read_data(input);//ֱ�Ӷ�������һ���������Լ�����
        }
        i++;
    }


    qsort(str, count, sizeof(Data), compare);//����weight���򣬴Ӵ�С����



    print_2ed(str);

    return 0;
}
