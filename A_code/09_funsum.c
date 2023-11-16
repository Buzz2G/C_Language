#include <stdio.h>

// �����ӷ���ͺ���
int sum_type_1(int a, int b) {
    return a + b;
}

// λ������ͺ���
int sum_type_0(int a, int b) {
    return a ^ b;
}

int main() {
    int numbers[1000];
    int i = 0;

    // ��ȡ����
    while (scanf("%d", &numbers[i]) == 1) {
        i++;
    }

    // ���ݵ�һ�����ֵ���ż��ѡ����ͺ���
    int (*sum_func)(int, int) = (numbers[0] % 2 == 0) ? sum_type_0 : sum_type_1;
    int (*sum_func)(int, int) = sum_type_0 ;

    // ������ͽ��
    int result = numbers[0];
    for (int j = 1; j < i; j++) {
        result = sum_func(result, numbers[j]);
    }

    // ������
    printf("%d\n", result);

    return 0;
}
