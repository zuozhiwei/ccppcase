/*
    c   字符数组    菜单
    程序功能    简单姓名的输入和排序
    时间        2018-1-8
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
char name[50][50];
//函数声明
void menu();
void input();
void deletes();
void order();
//输入函数
void input()
{
    printf("输入学生姓名：\n");
    scanf("%s",name[total]);
    total++;
    printf("输入成功！正在返回菜单...\n");
    menu();
}
//删除信息
void deletes()
{
    char name1[50];
    int i=0,j=0;
    printf("输入要删除的姓名：\n");
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
    printf("\n删除成功，正在返回菜单...\n");
    menu();
}

//排序函数
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
    printf("排序成功，正在返回菜单...\n");
    menu();
}

//菜单
void menu()
{
    int n;
    printf("学生姓名序列\n");
    printf("1.加入姓名\n2.删除姓名\n3.排序\n");
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
//主函数
int main()
{
    menu();
    return 0;
}
