/*
    c   �ַ�����    �˵�    string
    ������    ��ӰԺѡ���������ӰƱ��Ϣ
    ʱ��        2018-1-7
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
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
    printf("��ѡ��������\n");
    scanf("%d",&row);
    printf("��ѡ�������Ϊ%d\n",row);
    if(selectseat(row)==1)
    {
        printf("ѡ����λ\n");
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
    int occupied[15]={0};
    {
        char ss;
        for(i=0;i<total;i++)
        {
            for(j=0;j<15;j++)
            {
                if(seat[i][row][j]==1)
                {
                    occupied[j]=1;
                }
            }
        }
        printf("�ɹ�ѡ�����λ�У�\n");
        for(j=0;j<15;j++)
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
    else if(x=='D')
    {
        return 3;
    }
    else if(x=='E')
    {
        return 4;
    }
    else if(x=='F')
    {
        return 5;
    }
    else if(x=='G')
    {
        return 6;
    }
    else if(x=='H')
    {
        return 7;
    }
    else if(x=='I')
    {
        return 8;
    }
    else if(x=='J')
    {
        return 9;
    }
    else if(x=='K')
    {
        return 10;
    }
    else if(x=='L')
    {
        return 11;
    }
    else if(x=='M')
    {
        return 12;
    }
    else if(x=='N')
    {
        return 13;
    }
    else if(x=='O')
    {
        return 14;
    }
    else
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
        return 'D';
    }
    else if(x==4)
    {
        return 'E';
    }
    else if(x==5)
    {
        return 'F';
    }
    else if(x==6)
    {
        return 'G';
    }
    else if(x==7)
    {
        return 'H';
    }
    else if(x==8)
    {
        return 'I';
    }
    else if(x==9)
    {
        return 'J';
    }
    else if(x==10)
    {
        return 'K';
    }
    else if(x==11)
    {
        return 'L';
    }
    else if(x==12)
    {
        return 'M';
    }
    else if(x==13)
    {
        return 'N';
    }
    else if(x==14)
    {
        return 'O';
    }else
    {
        return 'x';
    }
}
void view()
{
    int i=0,j=0,k=0,row;
    char seatchar;
    printf("��Ӱ���� ��ӳʱ�� ��λ���� \n");
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
        printf("�ɻ���   1��1��   %d%c\n",row,seatchar);
    }
}
void menu()
{
    int n=0;
    printf("------------\n����ӰƱϵͳ\n1.ѡ��λ\n2.��ӡ��ӰƱ\n------------\n");
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
