/*
    c   �ַ�����    �˵�    string
    ������    �ɻ�Ʊѡ������ӡ�ɻ�Ʊ��Ϣ
    ʱ��        2018-1-7
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
char name[50][50],idcard[50][50];
int seat[50][27][6];
//��������
void select();
int chartonum(char);
char numtochar(int);
int selectseat(int);
void view();
//���뺯��
void select()
{
    int row=0;
    printf("��ѡ����������1~2Ϊ����գ�3~27Ϊ���òգ�\n");
    scanf("%d",&row);
    printf("��ѡ�������Ϊ%d\n",row);
    if(selectseat(row)==1)
    {
        printf("ѡ����λ�������������Ϣ\n");
        printf("����������\n");
        scanf("%s",name[total]);
        printf("�������֤�ţ�\n");
        scanf("%s",idcard[total]);
        total++;
    }
    else
    {
        printf("ѡ������������ѡ��\n");
        select();
    }
}
int selectseat(int row)
{
    int i=0,j=0,seatnum=0;
    int occupied[6]={0};
    if(row==1||row==2)
    {
        char s;
        for(i=0;i<total;i++)
        {
            for(j=0;j<6;j++)
            {
                if(j==1||j==4)
                {
                    seat[i][row][j]=2;
                    occupied[j]=2;
                }
                if(seat[i][row][j]==1)
                {
                    occupied[j]=1;
                }
            }
        }
        printf("��ѡ����ǹ���գ��ɹ�ѡ�����λ�У�\n");
        for(j=0;j<6;j++)
        {
            if(j==1||j==4)
            {
                continue;
            }
            if(occupied[j]==0)
            {
                printf("%c ",numtochar(j));
            }
        }
        printf("\n��������λ�ţ�\n");
        fflush(stdin);
        s=getchar();
        seatnum = chartonum(s);
        seat[total][row][seatnum]=1;
        return 1;
    }else
    {
        char ss;
        for(i=0;i<total;i++)
        {
            for(j=0;j<6;j++)
            {
                if(seat[i][row][j]==1)
                {
                    occupied[j]=1;
                }
            }
        }
        printf("��ѡ����Ǿ��òգ��ɹ�ѡ�����λ�У�\n");
        for(j=0;j<6;j++)
        {
            if(occupied[j]==0)
            {
                printf("%c ",numtochar(j));
            }
        }
        printf("\n��������λ�ţ�\n");
        fflush(stdin);
        ss=getchar();
        seatnum = chartonum(ss);
        seat[total][row][seatnum]=1;
        return 1;
    }
}
int chartonum(char x)
{
    if(x=='A')
    {
        return 0;
    }
    else if(x=='B')
    {
        return 1;
    }
    else if(x=='C')
    {
        return 2;
    }
    else if(x=='J')
    {
        return 3;
    }
    else if(x=='K')
    {
        return 4;
    }
    else if(x=='L')
    {
        return 5;
    }else
    {
        return 999;
    }
}

char numtochar(int x)
{
    if(x==0)
    {
        return 'A';
    }
    else if(x==1)
    {
        return 'B';
    }
    else if(x==2)
    {
        return 'C';
    }
    else if(x==3)
    {
        return 'J';
    }
    else if(x==4)
    {
        return 'K';
    }
    else if(x==5)
    {
        return 'L';
    }else
    {
        return 'x';
    }
}
void view()
{
    int i=0,j=0,k=0,row;
    char seatchar;
    printf("���� ���֤���� ��λ���� \n");
    for(i=0;i<total;i++)
    {
        for(j=0;j<27;j++)
        {
            for(k=0;k<6;k++)
            {
                if(seat[i][j][k]==1)
                {
                    row=j;
                    seatchar=numtochar(k);
                }
            }
        }
        printf("%s %s %d%c\n",name[i],idcard[i],row,seatchar);
    }
}
void menu()
{
    int n=0;
    printf("------------\n���ɻ�Ʊϵͳ\n1.ѡ��λ\n2.��ӡ�嵥\n------------\n");
    scanf("%d",&n);
    if(n==1)
    {
        select();
    }
    if(n==2)
    {
        view();
    }
}
int main()
{
    while(1)
    {
        menu();
    }
    return 0;
}
