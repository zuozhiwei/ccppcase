/*
    c   �ַ�����    �˵�
    ������    �����������������
    ʱ��        2018-1-8
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
char name[50][50];
//��������
void menu();
void input();
void deletes();
void order();
//���뺯��
void input()
{
    printf("����ѧ��������\n");
    scanf("%s",name[total]);
    total++;
    printf("����ɹ������ڷ��ز˵�...\n");
    menu();
}
//ɾ����Ϣ
void deletes()
{
    char name1[50];
    int i=0,j=0;
    printf("����Ҫɾ����������\n");
    scanf("%s",name1);
    for(i=0;i<total;i++)
    {
        if(strcmp(name1,name[i])==0)
        {
            if(i==total-1)
            {
                total--;
            }else
            {
                for(j=i+1;j<total;j++)
                {
                    strcpy(name[j-1],name[j]);
                }
                total--;
            }
            break;
        }
    }
    printf("\nɾ���ɹ������ڷ��ز˵�...\n");
    menu();
}

//������
void order()
{
    int i=0,j=0;
    char temp[50];
    for(i=0;i<total-1;i++)
    {
        for(j=0;j<total-i-1;j++)
        {
            if(strcmp(name[j],name[j+1])>0)
            {
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
            }
        }
    }
    for(i=0;i<total;i++)
    {
        printf("%s\n",name[i]);
    }
    printf("����ɹ������ڷ��ز˵�...\n");
    menu();
}

//�˵�
void menu()
{
    int n;
    printf("ѧ����������\n");
    printf("1.��������\n2.ɾ������\n3.����\n");
    while(1)
    {
        scanf("%d",&n);
        if(1==n)
        {
            input();
        }
        if(2==n)
        {
            deletes();
        }
        if(3==n)
        {
            order();
        }
    }
}
//������
int main()
{
    menu();
    return 0;
}
