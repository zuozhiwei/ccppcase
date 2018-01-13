/*
    c   字符数组    菜单    string
    程序功能    飞机票选座，打印飞机票信息
    时间        2018-1-7
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
char name[50][50],idcard[50][50];
int seat[50][27][6];
//函数声明
void select();
int chartonum(char);
char numtochar(int);
int selectseat(int);
void view();
//输入函数
void select()
{
    int row=0;
    printf("请选择排数：（1~2为公务舱，3~27为经济舱）\n");
    scanf("%d",&row);
    printf("您选择的排数为%d\n",row);
    if(selectseat(row)==1)
    {
        printf("选定座位，请输入个人信息\n");
        printf("输入姓名：\n");
        scanf("%s",name[total]);
        printf("输入身份证号：\n");
        scanf("%s",idcard[total]);
        total++;
    }
    else
    {
        printf("选座错误，请重新选择！\n");
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
        printf("您选择的是公务舱，可供选择的座位有：\n");
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
        printf("\n请输入座位号：\n");
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
        printf("您选择的是经济舱，可供选择的座位有：\n");
        for(j=0;j<6;j++)
        {
            if(occupied[j]==0)
            {
                printf("%c ",numtochar(j));
            }
        }
        printf("\n请输入座位号：\n");
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
    printf("姓名 身份证号码 座位号码 \n");
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
    printf("------------\n订飞机票系统\n1.选座位\n2.打印清单\n------------\n");
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
