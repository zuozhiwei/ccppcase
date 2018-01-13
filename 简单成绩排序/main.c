/*
    c   字符数组    结构体    菜单   冒泡
    程序功能    学生信息排序，菜单选择功能，对信息进行录入和排序
    时间        2018-1-5
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>

struct studentStruct
{
    int no;
    char name[20];
    char age[10];
    int score;
}student[100];
//学生总数
int total=0;
//函数声明
void returnMenu();
void menu();
void viewStudent();
void orderStudent();
void inputStudent();
//函数定义
void returnMenu()
{
    char x;
    printf("是否返回主菜单？\n(y：返回；n：不返回)\n");
    fflush(stdin);
    x=getchar();
    if(x=='y')
    {
        system("cls");
        menu();
    }else{
        system("cls");
        printf("退出系统...");
        exit(0);
    }
}

void inputStudent()    //录入学生信息
{
    printf("输入学号：\n");
    scanf("%d",&student[total].no);
    printf("输入学生姓名：\n");
    scanf("%s",student[total].name);
    printf("输入成绩：\n");
    scanf("%d",&student[total].score);
    total++; //录入一个学生信息，学生总数加1
    printf("输入成功!\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("学号 姓名 成绩\n");
    for(i=0;i<total;i++)
    {
        printf("%d %s %d\n",student[i].no,student[i].name,student[i].score);
    }
    printf("显示成功！");
    returnMenu();
}
void orderStudent()
{
    int i,j;
    struct studentStruct studentTemp;
    for(i=0;i<total-1;i++)
    {
        for(j=0;j<total-i-1;j++)
        {
            if(student[j].score<student[j+1].score)
            {
                studentTemp = student[j];
                student[j]=student[j+1];
                student[j+1]=studentTemp;
            }
        }
    }
    viewStudent();
}
void menu()
{
    int x=0;
    printf("-------------\n");
    printf("学生成绩管理系统：\n");
    printf("1.录入学生信息\n");
    printf("2.排序显示\n");
    printf("-------------\n");
    scanf("%d",&x);
    if(x==1)
    {
        inputStudent();
    }
    else if(x==2)
    {
        orderStudent();
    }else{
        printf("输入有误！\n");
        returnMenu();
    }
}
int main()
{
    menu();
    return 0;
}
