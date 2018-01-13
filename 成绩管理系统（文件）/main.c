/*
    c   字符数组    结构体    菜单   文件操作
    程序功能    学生成绩管理系统，菜单选择功能，对成绩信息增删改查,读写文件
    时间        2018-1-4
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentStruct
{
    char no[10];
    char name[20];
    char gender[4];
    char birth[20];   /*出生年月*/
	float english;   /*英语成绩*/
	float math;    /*数学英语成绩*/
	float mcu;    /*计算机成绩*/
    float score;
}student[100];
//学生总数
int total=0;
//函数声明
void returnMenu();
void menu();
void selectStudent(int);
void viewStudent();
void deleteStudent();
void alterStudent();
void orderStudent();
void inputStudent();
void totalScore();
void readFile();
void writeFile();
void orderByTotal();
void cal();
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
    char no[10];
    int m=0,i=0;
    printf("输入学号：\n");
    scanf("%s",no);
    for(i=0;i<total;i++)
    {
        if(strcmp(student[i].no,no)==0)
        {
            m=1;
        }
    }
    if(m==1)
    {
         printf("学号已存在！请重新输入\n");
         inputStudent();
    }
    strcpy(student[total].no,no);
    printf("输入学生姓名：\n");
    scanf("%s",student[total].name);
    printf("输入学生性别：\n");
    scanf("%s",student[total].gender);
    printf("输入学生出生年月：\n");
    scanf("%s",student[total].birth);
    printf("输入英语成绩：\n");
    scanf("%f",&student[total].english);
    printf("输入数学成绩：\n");
    scanf("%f",&student[total].math);
    printf("输入计算机成绩：\n");
    scanf("%f",&student[total].mcu);
    student[total].score=student[total].english+student[total].math+student[total].mcu;
    total++; //录入一个学生信息，学生总数加1
    printf("输入成功!\n");
    returnMenu();
}
void selectStudent(int x)
{
    int i,isexist=0;
    char no[10],name[10];
    if(x==1)
    {
        printf("输入要查询的学号：\n");
        scanf("%s",no);
        for(i=0;i<total;i++)
        {
            if(strcmp(student[i].no,no)==0)
            {
                isexist=1;//如果学号存在，则isexist变量置1
                printf("学生学号  学生姓名  学生性别    学生生日      英语成绩    数学成绩   计算机成绩   总分\n");
                printf("%s\t   ",student[i].no);
                printf("%s\t     ",student[i].name);
                printf("%s\t     ",student[i].gender);
                printf("%s\t",student[i].birth);
                printf("%.2f\t  ",student[i].english);
                printf("%.2f\t    ",student[i].math);
                printf("%.2f\t",student[i].mcu);
                printf("%.2f\n",student[i].score);
            }
        }
        if(isexist==0)//如果学号不存在，则提示无此学生
        {
            printf("无此学生信息\n");
        }
    }
    if(x==2)
    {
        printf("输入要查询的姓名：\n");
        scanf("%s",&name);
        for(i=0;i<total;i++)
        {
            if(strcmp(student[i].name,name)==0)
            {
                isexist=1;//如果学号存在，则isexist变量置1
                printf("学生学号  学生姓名  学生性别    学生生日      英语成绩    数学成绩   计算机成绩   总分\n");
                printf("%s\t   ",student[i].no);
                printf("%s\t     ",student[i].name);
                printf("%s\t     ",student[i].gender);
                printf("%s\t",student[i].birth);
                printf("%.2f\t  ",student[i].english);
                printf("%.2f\t    ",student[i].math);
                printf("%.2f\t",student[i].mcu);
                printf("%.2f\n",student[i].score);
            }
        }
        if(isexist==0)//如果学号不存在，则提示无此学生
        {
            printf("无此学生信息\n");
        }
    }
    if(x==3)
    {
        printf("不及格信息\n");
        for(i=0;i<total;i++)
        {
            if((student[i].english<60)||(student[i].math<60)||(student[i].mcu<60))
            {
                isexist=1;//如果学号存在，则isexist变量置1
                printf("学生学号  学生姓名  学生性别    学生生日      英语成绩    数学成绩   计算机成绩   总分\n");
                printf("%s\t   ",student[i].no);
                printf("%s\t     ",student[i].name);
                printf("%s\t     ",student[i].gender);
                printf("%s\t",student[i].birth);
                printf("%.2f\t  ",student[i].english);
                printf("%.2f\t    ",student[i].math);
                printf("%.2f\t",student[i].mcu);
                printf("%.2f\n",student[i].score);
            }
        }
        if(isexist==0)//如果学号不存在，则提示无此学生
        {
            printf("无学生信息\n");
        }
    }
    printf("查询结束！\n");
    returnMenu();
}

void  alterStudent()
{
    int i,isexist=0;
    char no[10];
    printf("输入要修改的学生学号：\n");
    scanf("%s",&no);
    for(i=0;i<total;i++)
    {
        if(strcmp(student[i].no,no)==0)
        {
            isexist=1;
            printf("输入学生姓名：\n");
            scanf("%s",student[i].name);
            printf("输入学生性别：\n");
            scanf("%s",student[i].gender);
            printf("输入学生生日：\n");
            scanf("%s",student[i].birth);
            printf("输入英语成绩：\n");
            scanf("%f",&student[i].english);
            printf("输入数学成绩：\n");
            scanf("%f",&student[i].math);
            printf("输入数据库成绩：\n");
            scanf("%f",&student[i].mcu);
        }
    }
    if(isexist==0)
    {
        printf("无此学生信息\n");
        return;
    }
    printf("修改成功！\n");
    writeFile();
    printf("写入新文件成功\n");
    returnMenu();
}

void deleteStudent()
{
    int i,j,isexist=0;
    char no[10];
    printf("输入要删除的学生学号：\n");
    scanf("%s",&no);
    for(i=0;i<total;i++)
    {
        if(strcmp(student[i].no,no)==0)
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
    if(isexist==0)
    {
        printf("无此学生信息\n");
        return;
    }
    printf("删除成功!\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("学号 姓名 性别     生日       英语   数学   计算机  总分\n");
    for(i=0;i<total;i++)
    {
        printf("%s %s  %s  %s %.2f %.2f %.2f %.2f\n",student[i].no,student[i].name,student[i].gender,student[i].birth,student[i].english,student[i].math,student[i].mcu,student[i].score);
    }
    printf("显示成功！");
    returnMenu();
}
void orderByTotal()
{
    int i,j;
    struct studentStruct studentTemp;
    for(i=0;i<total-1;i++)
    {
        for(j=0;j<total-i-1;j++)
        {
            if(student[j].score>student[j+1].score)
            {
                studentTemp = student[j];
                student[j]=student[j+1];
                student[j+1]=studentTemp;
            }
        }
    }
    viewStudent();
}
void orderStudent()
{
    int x,i,j;
    struct studentStruct studentTemp;
    printf("-------------\n");
    printf("1.按数学成绩排序\n2.按英语成绩排序\n3.按计算机成绩排序\n");
    printf("-------------\n");
    scanf("%d",&x);
    if(x==1)
    {
        for(i=0;i<total-1;i++)
        {
            for(j=0;j<total-i-1;j++)
            {
                if(student[j].math>student[j+1].math)
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
                if(student[j].english>student[j+1].english)
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
                if(student[j].mcu>student[j+1].mcu)
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

//从文件写入
void readFile()
{
    int i=0,j=0,k=0;
    char strLine[200];
    FILE *fp;
    fp=fopen("studb.txt","r+");
    if(fp==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    while (!feof(fp))                                   //循环读取每一行，直到文件尾
    {
        fgets(strLine,200,fp);                  //将fp所指向的文件一行内容读到strLine缓冲区
        while(strLine[j]!=0x20)
        {
            student[i].no[j]=strLine[j];
            j++;
        }
        j++;
        while(strLine[j]!=0x20)
        {
            student[i].name[k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        while(strLine[j]!=0x20)
        {
            student[i].gender[k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        while(strLine[j]!=0x20)
        {
            student[i].birth[k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        char cenglish[10];
        while(strLine[j]!=0x20)
        {
            cenglish[k]=strLine[j];
            k++;
            j++;
        }
        (student[i].english)=atof(cenglish);
        j++;
        k=0;
        char cmath[10];
        while(strLine[j]!=0x20)
        {
            cmath[k]=strLine[j];
            k++;
            j++;
        }
        (student[i].math) = atof(cmath);
        j++;
        k=0;
        char cmcu[10];
        while(strLine[j]!='\0')
        {
            cmcu[k]=strLine[j];
            k++;
            j++;
        }
        student[i].mcu=atof(cmcu);
        j=0;
        k=0;
        i++;
        total++;
    }
    i=0;
    for(i=0;i<total;i++)
    {
        student[i].score=student[i].english+student[i].math+student[i].mcu;
    }
    printf("读入成功！正在返回菜单...\n");
    returnMenu();
}
void cal()
{
    int x=0,i=0;
    float englishTotal=0,mathTotal=0,mcuTotal=0;
    printf("1.统计个人平均成绩\n2.统计各单科平均成绩\n");
    scanf("%d",&x);
    if(x==1)
    {
        printf("学号 姓名 平均分\n");
        for(i=0;i<total;i++)
        {
            printf("%s  %s  %.2f\n",student[i].no,student[i].name,(student[i].score/3.0));
        }
    }
    if(x==2)
    {
        for(i=0;i<total;i++)
        {
            englishTotal+=(student[i].english);
            mathTotal+=(student[i].math);
            mcuTotal+=(student[i].mcu);
        }
        printf("英语  数学  计算机\n");
        printf("%.2f %.2f %.2f\n",(englishTotal/total),(mathTotal/total),(mcuTotal/total));
    }
    returnMenu();
}

//写出到文件
void writeFile()
{
    int i=0;
    FILE *fp;
    fp=fopen("newstudb.txt","w");
    if(fp==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    if(total==0)
    {
        printf("信息为空，不能写入！正在返回菜单...");
        return;
    }
    for(i=0;i<total;i++)
    {
        fprintf(fp,"%s %s %s %s %f %f %f %f\n",student[i].no,student[i].name,student[i].gender,student[i].birth,student[i].english,student[i].math,student[i].mcu,student[i].score);//格式化写入文件（追加至文件末尾）
    }
    fclose(fp);
    printf("写入成功！正在返回菜单...\n");
    returnMenu();
}

void menu()
{
    int x=0;
    printf("-------------\n");
    printf("学生成绩管理系统：\n");
    printf("1.从数据库读入学生信息\n");
    printf("2.按学号查询学生信息\n");
    printf("3.按姓名查询学生信息\n");
    printf("4.查询所有学生信息\n");
    printf("5.根据单科成绩进行排序\n");
    printf("6.添加学生信息\n");
    printf("7.删除学生信息\n");
    printf("8.修改学生信息\n");
    printf("9.统计不及格学生信息\n");
    printf("10.统计平均成绩\n");
    printf("0.退出\n");
    printf("-------------\n");
    scanf("%d",&x);
    switch(x)
    {
        case 0:
            printf("退出系统...\n");
            exit(0);
            break;
        case 1:
            readFile();
            break;
        case 2:
            selectStudent(1);
            break;
        case 3:
            selectStudent(2);
            break;
        case 4:
            viewStudent();
            break;
        case 5:
            orderStudent();
            break;
        case 6:
            inputStudent();
            break;
        case 7:
            deleteStudent();
            break;
        case 8:
            alterStudent();
            break;
        case 9:
            selectStudent(3);
            break;
        case 10:
            cal();
            break;
        default:
            printf("输入有误！\n");
            returnMenu();
    }
}
int main()
{
    menu();
    return 0;
}
