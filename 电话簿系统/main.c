/*
    c   字符数组    菜单   文件操作
    程序功能    电话簿系统，联系人的增删改查，读写文件
    时间        2018-1-6
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
char name[50][50],danwei[50][50],phone[50][50],email[50][50];
//函数声明
void menu();
void input();
void alter();
void view();
void select();
void readFile();
void writeFile();
//输入函数
void input()
{
    printf("请输入联系人信息：\n");
    printf("姓名 工作单位 电话号码 email\n");
    printf("输入姓名：\n");
    scanf("%s",name[total]);
    printf("输入工作单位：\n");
    scanf("%s",danwei[total]);
    printf("输入电话号码：\n");
    scanf("%s",phone[total]);
    printf("输入email：\n");
    scanf("%s",email[total]);
    total++;
    printf("输入成功！正在返回菜单...\n");
    menu();
}
//删除信息
void deletes()
{
    char phoneinput[50];
    int i=0,j=0;
    printf("输入要删除的号码：\n");
    scanf("%s",phoneinput);
    for(i=0;i<total;i++)
    {
        if(strcmp(phoneinput,phone[i])==0)
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
//修改信息
void alter()
{
    int i=0;
    char phoneTemp[50],nameTemp[50],danweiTemp[50],emailTemp[50];
    printf("输入要修改的手机号:\n");
    scanf("%s",phoneTemp);
    printf("输入姓名：\n");
    scanf("%s",nameTemp);
    printf("输入工作单位：\n");
    scanf("%s",danweiTemp);
    printf("输入email：\n");
    scanf("%s",emailTemp);

    for(i=0;i<total;i++)
    {
        if(strcmp(phoneTemp,phone[i])==0)
        {
            strcpy(name[i],nameTemp);
            strcpy(danwei[i],danweiTemp);
            strcpy(email[i],emailTemp);
            break;
        }
    }
    printf("\n修改成功，正在返回菜单...\n");
    menu();
}
//查询信息
void select()
{
    char nameTemp[50],phoneTemp[50];
    int i=0,n=0;
    i=0;

    printf("1.按人名查询\n2.按电话号码查询\n");
    scanf("%d",&n);
    //按人名查询
    if(n==1)
    {
        printf("\n输入要查询的人名:\n");
        scanf("%s",nameTemp);
        for(i=0;i<total;i++)
        {
            if(strcmp(nameTemp,name[i])==0)
            {
                printf("电话是:\n%s",phone[i]);
                break;
            }
        }
        printf("\n查询成功，正在返回菜单...\n");
        menu();
    }
    //按电话号码查询
    if(n==2)
    {
        printf("\n输入要查询的电话号码:\n");
        scanf("%s",phoneTemp);
        for(i=0;i<total;i++)
        {
            if(strcmp(phoneTemp,phone[i])==0)
            {
                printf("姓名是:\n%s",name[i]);
                break;
            }
        }
        printf("\n查询成功，正在返回菜单...\n");
        menu();
    }
}
//显示所有信息
void view()
{
    int i=0;
    printf("姓名 工作单位 电话号码 email\n");
    for(i=0;i<total;i++)
    {
        printf("%s %s %s %s\n",name[i],danwei[i],phone[i],email[i]);
    }
    printf("\n查看成功！正在返回菜单...\n");
    menu();
}
//排序函数
void order()
{
    int i=0,j=0,n=0;
    char temp[50];
    printf("1.按电话号码排序\n2.按姓名字母排序\n");
    scanf("%d",&n);
    //按电话号码排序
    if(n==1)
    {
        for(i=0;i<total-1;i++)
        {
            for(j=0;j<total-i-1;j++)
            {
                if(strcmp(phone[j],phone[j+1])>0)
                {
                    strcpy(temp,phone[j]);
                    strcpy(phone[j],phone[j+1]);
                    strcpy(phone[j+1],temp);
                }
            }
        }
    }
    //按人名排序
    if(n==2)
    {
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
    }
    for(i=0;i<total;i++)
    {
        printf("%s %s %s %s\n",name[i],danwei[i],phone[i],email[i]);
    }
    printf("排序成功，正在返回菜单...");
    menu();
}
//写出到文件
void writeFile()
{
    int i=0;
    FILE *fp;
    fp=fopen("dianhuabu.txt","w");
    if(fp==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    if(total==0)
    {
        printf("电话簿为空，不能写入！正在返回菜单...");
        return;
    }
    //fprintf(fp,"%s %s %s %s",name[0],danwei[0],phone[0],email[0]);//格式化写入文件（追加至文件末尾）
    for(i=0;i<total;i++)
    {
        fprintf(fp,"%s %s %s %s\n",name[i],danwei[i],phone[i],email[i]);//格式化写入文件（追加至文件末尾）
    }
    fclose(fp);
    printf("写入成功！正在返回菜单...\n");
    menu();
}
//从文件写入
void readFile()
{
    int i=0,j=0,k=0;
    char strLine[200];
    FILE *fp;
    fp=fopen("dianhuabu.txt","r+");
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
            name[i][j]=strLine[j];
            j++;
        }
        j++;
        while(strLine[j]!=0x20)
        {
            danwei[i][k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        while(strLine[j]!=0x20)
        {
            phone[i][k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        while(strLine[j]!='\0')
        {
            email[i][k]=strLine[j];
            k++;
            j++;
        }
        j=0;
        k=0;
        i++;
        total++;
    }
    printf("读入成功！正在返回菜单...\n");
    menu();
}
//菜单
void menu()
{
    int n;
    printf("电话簿管理\n");
    printf("1.加入新号码\n2.删除号码\n3.显示所有号码\n4.修改号码\n5.排序\n6.查询\n7.从文件读入\n8.写入到文件\n");
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
            view();
        }
        if(4==n)
        {
            alter();
        }
        if(5==n)
        {
            order();
        }
        if(6==n)
        {
            select();
        }
        if(7==n)
        {
            readFile();
        }
        if(8==n)
        {
            writeFile();
        }
    }
}
//主函数
int main()
{
    menu();
    return 0;
}
