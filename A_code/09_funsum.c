#include <stdio.h>

// 正常加法求和函数
int sum_type_1(int a, int b) {
    return a + b;
}

// 位运算求和函数
int sum_type_0(int a, int b) {
    return a ^ b;
}

int main() {
    int numbers[1000];
    int i = 0;

    // 读取输入
    while (scanf("%d", &numbers[i]) == 1) {
        i++;
    }

    // 根据第一个数字的奇偶性选择求和函数
    int (*sum_func)(int, int) = (numbers[0] % 2 == 0) ? sum_type_0 : sum_type_1;
    int (*sum_func)(int, int) = sum_type_0 ;

    // 计算求和结果
    int result = numbers[0];
    for (int j = 1; j < i; j++) {
        result = sum_func(result, numbers[j]);
    }

    // 输出结果
    printf("%d\n", result);

    return 0;
}
