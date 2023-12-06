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
            // 处理错误或退出循环
            break;
        }

        // 删除末尾的换行符
        str[strcspn(str, "\n")] = '\0';

        // 使用 revstr 函数反转字符串
        strcpy(strings[i], revstr(str));

        count++;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}
