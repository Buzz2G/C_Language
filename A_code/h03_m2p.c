#include<stdio.h>

int main()
{
    double N_pyeong = 0;
    double hi_m2 = 0;
    double h_max_m2 =0;

    fscanf(stdin,"%lf", &N_pyeong);
    double N_m2 =  3.3058 * N_pyeong;

    while (1)
    {
        if (fscanf(stdin,"%lf", &hi_m2) == 1)// �ɹ���ȡһ��С��
        {
            if( hi_m2 < N_m2)
            {
                if(hi_m2 > h_max_m2)
                {
                    h_max_m2=hi_m2;
                }
            }
        }
        else
        {
            // �޷���ȡ����С�����������벻��С��
            break;
        }
    }
    double h_max_pyeong = h_max_m2/ 3.3058;
    printf("%.2lf\n", h_max_pyeong);
    printf("%.2lf\n", h_max_m2);
}
