/*
    c   字符数组    菜单    文件操作
    程序功能    航班信息的增删改查，读写文件
    时间        2018-1-7
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i=0;
FILE *fp;
void menu();
void input();
void alter();
void view();
void select();
void input()
{
    char num[50],start[50],end[50],time[50];
    i=0;
    printf("请录入航班信息：\n");
    printf("航班号 起始点 终止点 确定的飞行时间\n");
    printf("输入航班号：\n");
    scanf("%s",num);
    printf("输入起始点：\n");
    scanf("%s",start);
    printf("输入终止点：\n");
    scanf("%s",end);
    printf("输入确定的飞行时间：\n");
    scanf("%s",time);
    i++;
    fp=fopen("hangban.txt","a");
    if(fp==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    fprintf(fp,"\n%s %s %s %s",num,start,end,time);//格式化写入文件（追加至文件末尾）
    fclose(fp);
    printf("输入成功！正在返回菜单...\n");
    menu();
}
void alter()
{
    char num[50],start[50],end[50],time[50];
    int k=0,j=0;
    char numTemp[50],strall[50][200],strLine[200],strinput[200];
    FILE *fp1;
    printf("输入要修改的航班号:\n");
    scanf("%s",num);
    printf("输入起始点：\n");
    scanf("%s",start);
    printf("输入终止点：\n");
    scanf("%s",end);
    printf("输入确定的飞行时间：\n");
    scanf("%s",time);
    strcpy(strinput,num);
    strcat(strinput," ");
    strcat(strinput,start);
    strcat(strinput," ");
    strcat(strinput,end);
    strcat(strinput," ");
    strcat(strinput,time);
    strcat(strinput,"\n");
    fp=fopen("hangban.txt","r+");
    i=0;
    while (!feof(fp))                                   //循环读取每一行，直到文件尾
    {
        fgets(strLine,200,fp);                  //将fp所指向的文件一行内容读到strLine缓冲区
        strcpy(strall[i],strLine);
        i++;
    }
    for(k=0;k<i;k++)
    {
        j=0;
        while(strall[k][j]!=0x20)
        {
            numTemp[j]=strall[k][j];
            j++;
        }
        if(strcmp(numTemp,num)==0)
        {
            strcpy(strall[k],strinput);
            break;
        }
    }
    fp1=fopen("hangban.txt","w");
    for(k=0;k<i;k++)
    {
        fprintf(fp1,"%s",strall[k]);//格式化写入文件
    }
    printf("\n修改成功，正在返回菜单...\n");
    fclose(fp);
    fclose(fp1);
    menu();
}
void select()
{
    FILE *fpselect;
    char num[50];
    char numTemp[50],strall[50][200],strLine[200];
    int k=0,j=0;
    i=0;
    char strSelect[200];
    printf("\n输入要查询的航班号:\n");
    scanf("%s",num);
    fpselect=fopen("hangban.txt","r+");
    while (!feof(fpselect))                                   //循环读取每一行，直到文件尾
    {
        fgets(strLine,200,fpselect);                  //将fp所指向的文件一行内容读到strLine缓冲区
        strcpy(strall[i],strLine);
        i++;
    }
    for(k=0;k<i;k++)
    {
        j=0;
        while(strall[k][j]!=0x20)
        {
            numTemp[j]=strall[k][j];
            j++;
        }
        if(strcmp(numTemp,num)==0)
        {
            printf("\n航班信息如下：\n%s\n",strall[k]);
            break;
        }
    }
    menu();
    fclose(fpselect);
}
void quit()
{
    exit(0);
}
void view()
{
    char strView[200];
    fp=fopen("hangban.txt","r");
    while (!feof(fp))                                   //循环读取每一行，直到文件尾
    {
        fgets(strView,200,fp);                  //将fp所指向的文件一行内容读到strLine缓冲区
        printf("%s",strView);
    }
    printf("\n查看成功！正在返回菜单...\n");
    fclose(fp);
    menu();
}

void menu()
{
    char n;
    printf("民航业务查询\n");
    printf("N.录入\nU.修改\nS.查询\nB.浏览\nQ.退出\n");
    while(1)
    {
        scanf("%c",&n);
        if('N'==n)
        {
            input();
        }
        if('U'==n)
        {
            alter();
        }
        if('S'==n)
        {
            select();
        }
        if('B'==n)
        {
            view();
        }
        if('Q'==n)
        {
            quit();
        }
    }
}
int main()
{
    menu();
    return 0;
}
