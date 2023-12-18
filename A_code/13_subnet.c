#include <stdio.h>
#include <stdint.h>

// ��������ĸ�λ�ֶε�IP���ͣ�ÿ���ֶα�ʾ8λ
typedef struct
{
    int A;
    int B;
    int C;
    int D;
} IP;


int countOne(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// �ݹ����IP������1��λ��
int countBits(IP ip)
{
    int count = 0;

    // ͳ��ÿ��8λ�ֶ���1�ĸ���
    count += countOne(ip.A);
    count += countOne(ip.B);
    count += countOne(ip.C);
    count += countOne(ip.D);

    return count;
}



int main()
{
    // �ӱ�׼�����ȡIP��ַ����������
    IP ad;
    IP msk;
    IP ad2;

    scanf("%d.%d.%d.%d", &ad.A, &ad.B, &ad.C, &ad.D);
    scanf("%d.%d.%d.%d", &msk.A, &msk.B, &msk.C, &msk.D);

    // ͨ����λ��������������ַ

    ad2.A = ad.A & msk.A;
    ad2.B = ad.B & msk.B;
    ad2.C = ad.C & msk.C;
    ad2.D = ad.D & msk.D;


    // ��ӡ���
    /*
    printf("%d.%d.%d.%d\n", ad2.A, ad2.B, ad2.C, ad2.D);
    printf("%d.%d.%d.%d\n", ad.A, ad.B, ad.C, ad.D);
    printf("%d.%d.%d.%d\n", msk.A, msk.B, msk.C, msk.D);
    */

    // �ݹ���������ַ��1��λ��
    int res = countBits(ad2);

    // ��ӡ�������׼���
    printf("%d\n", res);

    return 0;
}
