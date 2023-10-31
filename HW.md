2:bit .c读取一个两位数的十进制整数n，并打印由n的二进制表示的第7、5、3和1位组成的二进制数的十进制值。位位从LSB开始计数，即LSB是二进制表示的第一个位。

例如，给定n = 75, n的二进制表示形式为1001011。因为第7位、第5位、第3位和第1位分别是1、0、0和1，你的程序应该输出9。如果你找不到n的二进制表示的任何位，你应该假设对应的位是0，因为它确实适用于数字，比如1100等于0001100。输入由单行组成，其中包含两个十进制数字的十进制整数n (9 <n < 100)。你的程序应该将n的二进制表示的奇数位组成的数字打印到标准输出。额外加分要求:你的程序文件应该命名为Bits.c如本节标题所述。不要使用scanf，而是使用getchar。

```c
#include <stdio.h>

int main() {
    // Read the decimal integer from the input
    int n = 0;
    int ch;

    // Read each character using getchar and convert to integer
    while ((ch = getchar()) != '\n') {
        n = n * 10 + (ch - '0');
    }

    // Calculate the binary value of the specified bits
    
    int seventh = (n & (1 << 6)) >> 6;
    int fifth = (n & (1 << 4)) >> 4;
    int third = (n & (1 << 2)) >> 2;
    int first = (n & 1);

    // Calculate the decimal value using the specified bits
    int result = (seventh << 3) | (fifth << 2) | (third << 1) | first;

    // Print the result
    printf("%d\n", result);

    return 0;
}

```


3:fbits.c给定一个正整数n和一个正浮点数x (0 < x < 1)，用小数点后的n个二进制数字打印x的二进制表示形式。例如，如果n = 3, f= 0.29，你的程序应该输出0.010作为输出。在标准输入中，输入由两行组成。第一行包含二进制数n，第二行包含浮点数f。你的程序应该在小数点后打印n个二进制数的二进制表示。

input 
5
0.29

output
0.01001

input
10
0.9

output
0.1110011001



```c
#include <stdio.h>
#include <math.h>

void floatToBinaryFraction(double f, int n) {
    int i;
    printf("0.");

    for (i = 0; i < n; i++) {
        f *= 2;
        if (f >= 1.0) {
            printf("1");
            f -= 1.0;
        } else {
            printf("0");
        }
    }

    printf("\n");
}

int main() {
    int n;
    double f;

    // Input
    scanf("%d", &n);
    scanf("%lf", &f);

    // Check if the input is valid
    if (0.0 < f && f < 1.0 && n > 0) {
        floatToBinaryFraction(f, n);
    } else {
        printf("Invalid input. Please make sure 0 < f < 1 and n > 0.\n");
    }

    return 0;
}
```


 4: wdmix.c
计算字符的weight 返回合并的字符
```c
#include <stdio.h>
#include <string.h>


int main(void)
{
    char str1[80];
    char str2[80];

    scanf("%s", str1);
    scanf("%s", str2);
    if(strlen(str1)== strlen(str2))
    {
        for(int i =0; i<strlen(str1); i++){
            printf("%c%c", str1[i],str2[i]);
        }

        return 0;
    }

    printf("_");
    return 0;

}
```
 5: wdist.c
 由字母计算向量
```c
#include <stdio.h>
#include <string.h>
#include <math.h>

double calcDistance (int x1, int x2, int y1, int y2)
{
    double result;
    result  = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return result;
}

int main()
{

    char word01[41] ;
    char word02[41] ;
    int x1=0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    scanf("%s", word01);
    scanf("%s", word02);

    for( int i = 0 ; word01 [i] != '\0' ; i++)
    {
        word01[i] = tolower(word01[i]);
        if (word01 [i] == 'a' || word01 [i] == 'e' || word01 [i] == 'i' || word01 [i] == 'o' || word01 [i] == 'u')
        {
            x1++;
        }
        else
        {
            y1++;
        }
    }

    for( int i = 0 ; word02 [i] != '\0' ; i++)
    {
        word02 [i] = tolower(word02[i]);

        if (word02 [i] == 'a' || word02 [i] == 'e' || word02 [i] == 'i' || word02 [i] == 'o' || word02 [i] == 'u')
        {
            x2++;
        }
        else
        {
            y2++;
        }

    }
    //printf("%d,%d,%d,%d\n",x1, x2, y1, y2);
    printf("%.3f\n", calcDistance ( x1, x2, y1, y2));

}
```
字符回圈
```c
#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z') {
        // If the character is an uppercase letter
        if (c == 'Z') {
            // Handle the special case for 'Z'
            printf("A\n");
        } else {
            // Print the next uppercase character
            printf("%c\n", c + 1);
        }
    } else if (c >= 'a' && c <= 'z') {
        // If the character is a lowercase letter
        if (c == 'a') {
            // Handle the special case for 'a'
            printf("z\n");
        } else {
            // Print the previous lowercase character
            printf("%c\n", c - 1);
        }
    } else {
        // If it's not a letter, just print the character itself
        printf("%c\n", c);
    }

    return 0;
}

```