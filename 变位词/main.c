/*
    c   �ַ�����    string
    ������    �����������ʣ��ж�����ĸ�Ƿ���ͬ����Ϊ��λ�ʣ����Ǳ�λ�������y���������n
    ʱ��        2018-1-1
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    while(1)
    {
        char a[10],b[10],inputa[10],inputb[10],c,d,temp;
        int i=0,j=0,k=0,m=0,x,y;
        printf("��������������(�س��ָ�)\n");
        scanf("%s",inputa);
        scanf("%s",inputb);
        while(((c=inputa[i])!='\0'))
        {
            if(isalpha(c))
            {
                a[j]=c;
                j++;
            }
            i++;
        }
        a[j]='\0';
        i=0;
        while(((d=inputb[i])!='\0'))
        {
            if(isalpha(d))
            {
                b[k]=d;
                k++;
            }
            i++;
        }
        b[k]='\0';
        i=0;
        if(j==k)
        {
            for (j = 0; j < k - 1; j++)
            for (i = 0; i < k - 1 - j; i++)
            {
                if(a[i] > a[i + 1])
                {
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
                if(b[i] > b[i + 1])
                {
                    temp = b[i];
                    b[i] = b[i + 1];
                    b[i + 1] = temp;
                }
            }
            if(strcmp(a,b)==0)
            {
                printf("y\n");
            }else{
                printf("n\n");
            }
        }else{
            printf("n\n");
        }
    }
    return 0;
}
