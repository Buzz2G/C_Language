#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256
#define SWAPCHAR(a, b) do { char *temp = (a); (a) = (b); (b) = temp; } while(0)

char strings[MAX_LINES][MAX_LENGTH];
char str[MAX_LENGTH];

char* revstr(char *s)
{
    int len = strlen(s);
    int top = 0, end = len - 1;

    while (top < end)
    {
        SWAPCHAR(s[top], s[end]);

        top++;
        end--;
    }

    return s;
}

int main()
{
    int count = 0;

    for (int i = 0; i < MAX_LINES; i++)
    {
        if (fgets(str, sizeof(str), stdin) == NULL)
        {
            // ���������˳�ѭ��
            break;
        }

        // ɾ��ĩβ�Ļ��з�
        str[strcspn(str, "\n")] = '\0';

        // ʹ�� revstr ������ת�ַ���
        strcpy(strings[i], revstr(str));

        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}
