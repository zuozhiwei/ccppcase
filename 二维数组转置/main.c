/*
    c   ��ά����
    ������    ����3*4�ľ����ж������Ƿ��и���������и��������ѣ�����������
                ���ת�����
    ʱ��        2017-12-08
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[3][4],i,j;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            if(a[i][j]<0){
                printf("a[%d][%d] is a minus ,input a positive integer\n",i,j);
                scanf("%d",&a[i][j]);
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
