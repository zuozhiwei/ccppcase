/*
    c   字符数组    结构体    string   菜单
    程序功能    学生成绩管理系统，菜单选择功能，对成绩信息增删改查
    时间        2018-1-3
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
    char gender[4];
    int clanguage;
    int english;
    int database;
    int score;
}student[100];
//学生总数
int total=0;
//函数声明
void returnMenu();
void menu();
void selectStudent();
void viewStudent();
void deleteStudent();
void alterStudent();
void orderStudent();
void inputStudent();
void totalScore();
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
    printf("输入学生年龄：\n");
    scanf("%s",student[total].age);
    printf("输入C语言成绩：\n");
    scanf("%d",&student[total].clanguage);
    printf("输入英语成绩：\n");
    scanf("%d",&student[total].english);
    printf("输入数据库成绩：\n");
    scanf("%d",&student[total].database);
    student[total].score=student[total].clanguage+student[total].english+student[total].database;
    total++; //录入一个学生信息，学生总数加1
    printf("输入成功!\n");
    returnMenu();
}
void selectStudent()
{
    int no,i,isexist=0;
    printf("输入要查询的学号：\n");
    scanf("%d",&no);
    for(i=0;i<total;i++)
    {
        if(student[i].no==no)
        {
            isexist=1;//如果学号存在，则isexist变量置1
            printf("学生学号 学生姓名 学生年龄 C语言成绩 英语成绩 数据库成绩\n");
            printf("%d\t  ",student[i].no);
            printf("%s\t ",student[i].name);
            printf("%s\t ",student[i].age);
            printf("%d\t ",student[i].clanguage);
            printf("%d\t ",student[i].english);
            printf("%d\n",student[i].database);
        }
    }
    if(isexist==0)//如果学号不存在，则提示无此学生
    {
        printf("无此学生信息\n");
        return;
    }
    printf("查询成功！\n");
    returnMenu();
}

void  alterStudent()
{
    int no,i,isexist=0;
    printf("输入要修改的学生学号：\n");
    scanf("%d",&no);
    for(i=0;i<total;i++)
    {
        if(student[i].no==no)
        {
            isexist=1;
            printf("输入学生姓名：\n");
            scanf("%s",student[i].name);
            printf("输入学生年龄：\n");
            scanf("%s",student[i].age);
            printf("输入C语言成绩：\n");
            scanf("%d",&student[i].clanguage);
            printf("输入英语成绩：\n");
            scanf("%d",&student[i].english);
            printf("输入数据库成绩：\n");
            scanf("%d",&student[i].database);
        }
    }
    if(isexist==0)//如果图书编号不存在，则提示无此图书
    {
        printf("无此学生信息\n");
        return;
    }
    printf("修改成功！\n");
    returnMenu();
}

void deleteStudent()
{
    int no,i,j,isexist=0;
    printf("输入要删除的学生学号：\n");
    scanf("%d",&no);
    for(i=0;i<total;i++)
    {
        if(student[i].no==no)
        {
            isexist=1;
            if(i==total-1)
            {
                total--;
            }else
            {
                for(j=i+1;j<total;j++)
                {
                    student[j-1]=student[j];
                }
                total--;
            }
            break;
        }
    }
    if(isexist==0)
    {
        printf("无此学生信息\n");
        return;
    }
    printf("删除成功!\n");
    returnMenu();
}
void totalScore()
{
    int i=0;
    printf("学号  总分：\n");
    for(i=0;i<total;i++)
    {
        printf("%d\t%d\n",student[i].no,student[i].score);
    }
    printf("查看总分成功...\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("学号 姓名 年龄 C语言 英语 数据库\n");
    for(i=0;i<total;i++)
    {
        printf("%d %s %s   %d    %d    %d\n",student[i].no,student[i].name,student[i].age,student[i].clanguage,student[i].english,student[i].database);
    }
    printf("显示成功！");
    returnMenu();
}
void orderStudent()
{
    int x,i,j;
    struct studentStruct studentTemp;
    printf("-------------\n");
    printf("1.按学号排序\n2.按c语言成绩排序\n3.按英语成绩排序\n4.按数据库成绩排序\n");
    printf("-------------\n");
    scanf("%d",&x);
    if(x==1)
    {
        for(i=0;i<total-1;i++)
        {
            for(j=0;j<total-i-1;j++)
            {
                if(student[j].no>student[j+1].no)
                {
                    studentTemp = student[j];
                    student[j]=student[j+1];
                    student[j+1]=studentTemp;
                }
            }
        }
    }
    if(x==2)
    {
        for(i=0;i<total-1;i++)
        {
            for(j=0;j<total-i-1;j++)
            {
                if(student[j].clanguage>student[j+1].clanguage)
                {
                    studentTemp = student[j];
                    student[j]=student[j+1];
                    student[j+1]=studentTemp;
                }
            }
        }
    }
    if(x==3)
    {
        for(i=0;i<total-1;i++)
        {
            for(j=0;j<total-i-1;j++)
            {
                if(student[j].english>student[j+1].english)
                {
                    studentTemp = student[j];
                    student[j]=student[j+1];
                    student[j+1]=studentTemp;
                }
            }
        }
    }
    if(x==4)
    {
        for(i=0;i<total-1;i++)
        {
            for(j=0;j<total-i-1;j++)
            {
                if(student[j].database>student[j+1].database)
                {
                    studentTemp = student[j];
                    student[j]=student[j+1];
                    student[j+1]=studentTemp;
                }
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
    printf("2.查询学生信息\n");
    printf("3.修改学生信息\n");
    printf("4.删除学生信息\n");
    printf("5.成绩总分\n");
    printf("6.排序显示\n");
    printf("-------------\n");
    scanf("%d",&x);
    if(x==1)
    {
        inputStudent();
    }
    else if(x==2)
    {
        selectStudent();
    }
    else if(x==3)
    {
        alterStudent();
    }
    else if(x==4)
    {
        deleteStudent();
    }
    else if(x==5)
    {
        totalScore();
    }
    else if(x==6)
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
