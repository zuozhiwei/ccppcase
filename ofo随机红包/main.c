/*
    c    �����
    ������    ģ��ofo����������
    ʱ��        2018-1-13
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int times=0;
    srand((unsigned)time(NULL));
    while(1)
    {
        int x=0;
        times++;
        printf("������������������ʼ����\n");
        scanf("%d",&x);
        printf("���н���\n");
        x = rand()%100+1;
        if(times<3)
        {
            printf("��������%d��\n",times);
            if(x>(50-times*10))
            {
                printf("�����н�!����Ϊ:%.2f\n\n",(3*x/100.0));
            }
            else{
                printf("���ź�����û���н����ٽ�������\n\n");
            }
        }
        else
        {
            printf("��������%d�Σ��ٷ�֮���н���\n����Ϊ:%.2f\n\n",times,(3*x/100.0));
        }

    }
    return 0;
}
