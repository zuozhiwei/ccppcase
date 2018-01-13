/*
    c   字符数组    结构体    菜单
    程序功能    学生信息管理系统，菜单选择功能，对成绩信息增删改查,无成绩
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
    char birth[20];
    char address[20];
    char phone[20];
    char email[20];
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
    printf("输入学生年龄：\n");
    scanf("%s",student[total].age);
    printf("输入学生性别：\n");
    scanf("%s",student[total].gender);
    printf("输入学生生日：\n");
    scanf("%s",student[total].birth);
    printf("输入学生地址：\n");
    scanf("%s",student[total].address);
    printf("输入电话：\n");
    scanf("%s",student[total].phone);
    printf("输入email：\n");
    scanf("%s",student[total].email);
    total++; //录入一个学生信息，学生总数加1
    printf("输入成功!\n");
    returnMenu();
}
void selectStudent()
{
    int no,x,i,isexist=0;
    char name[20];
    printf("1.按学号查询\n2.按姓名查询\n");
    scanf("%d",&x);
    if(x==1){
        printf("输入要查询的学号：\n");
        scanf("%d",&no);
        for(i=0;i<total;i++)
        {
            if(student[i].no==no)
            {
                isexist=1;//如果学号存在，则isexist变量置1
                printf("学号 姓名 年龄 性别 生日 地址 电话 email\n");
                printf("%d  ",student[i].no);
                printf("%s ",student[i].name);
                printf("%s ",student[i].age);
                printf("%s ",student[i].gender);
                printf("%s ",student[i].birth);
                printf("%s ",student[i].address);
                printf("%s ",student[i].phone);
                printf("%s\n",student[i].email);
            }
        }
    }
    if(x==2){
        printf("输入要查询的姓名：\n");
        scanf("%s",&no);
        for(i=0;i<total;i++)
        {
            if(strcmp(student[i].name,name)==0)
            {
                isexist=1;//如果学号存在，则isexist变量置1
                printf("学号 姓名 年龄 性别 生日 地址 电话 email\n");
                printf("%d  ",student[i].no);
                printf("%s ",student[i].name);
                printf("%s ",student[i].age);
                printf("%s ",student[i].gender);
                printf("%s ",student[i].birth);
                printf("%s ",student[i].address);
                printf("%s ",student[i].phone);
                printf("%s\n",student[i].email);
            }
        }
    }
    if(isexist==0)//如果学号不存在，则提示无此学生
    {
        printf("无此学生信息\n");
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
            printf("输入学生性别：\n");
            scanf("%s",student[i].gender);
            printf("输入学生生日：\n");
            scanf("%s",student[i].birth);
            printf("输入学生地址：\n");
            scanf("%s",student[i].address);
            printf("输入电话：\n");
            scanf("%s",student[i].phone);
            printf("输入email：\n");
            scanf("%s",student[i].email);
        }
    }
    if(isexist==0)
    {
        printf("无此学生信息\n");
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
                    //strcpy(name[j-1],name[j]);
                }
                total--;
            }
            break;
        }
    }
    if(isexist==0)//如果图书编号不存在，则提示无此图书
    {
        printf("无此学生信息\n");
    }
    printf("删除成功!\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("学号 姓名 年龄 性别 生日 地址 电话 email\n");
    for(i=0;i<total;i++)
    {
        printf("%d %s %s %s %s %s %s %s\n",student[i].no,student[i].name,student[i].age,student[i].gender,student[i].birth,student[i].address,student[i].phone,student[i].email);
    }
    printf("显示成功！");
    returnMenu();
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
    printf("5.浏览学生信息\n");
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
        viewStudent();
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
