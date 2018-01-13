/*
    c   字符数组    结构体    菜单
    程序功能    图书馆管理系统，图书信息的增删改查
    时间        2018-1-3
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/
#include <stdio.h>
#include <stdlib.h>
int books=0; //定义图书类别的总数
struct book //定义图书结构体
{
    int no; //图书编号
    char jieyueren[20]; //借阅人姓名
    int day; //借阅天数
    int total;  //图书总量
    int kucun;  //图书库存
    char name[100]; //书名
    char author[100];   //作者
}book1[100];//定义结构体
//函数声明
void menu();
void input();
void deletebooks();
void selectbooks();
void alterbooks();
void jieyue();

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

//函数定义
void input()    //录入图书信息
{
    printf("输入图书编号：\n");
    scanf("%d",&book1[books].no);
    printf("输入图书借阅人：\n");
    scanf("%s",book1[books].jieyueren);
    printf("输入借阅天数：\n");
    scanf("%d",&book1[books].day);
    printf("输入图书总量：\n");
    scanf("%d",&book1[books].total);
    printf("输入图书库存：\n");
    scanf("%d",&book1[books].kucun);
    printf("输入图书名称：\n");
    scanf("%s",book1[books].name);
    printf("输入图书作者：\n");
    scanf("%s",book1[books].author);
    books++; //录入一个图书信息，图书类型总数加1
    returnMenu();
}
void jieyue()   //借阅图书
{
    int no,i,isexist=0;
    printf("输入借阅图书编号：\n");
    scanf("%d",&no);    //输入图书编号赋值给no
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)
        {
            isexist=1;//如果图书编号存在，则isexist变量置1
            printf("输入借阅人姓名：\n");
            scanf("%s",book1[i].jieyueren);
            printf("输入借阅天数：\n");
            scanf("%d",&book1[i].day);
            book1[i].kucun--;//修改图书信息
        }
    }
    if(isexist==0)//如果图书编号不存在，则提示无此图书
    {
        printf("无此图书\n");
    }
    returnMenu();
}

void deletebooks() //删除图书信息
{
    int no,i,isexist=0;
    printf("输入要删除的图书编号：\n");
    scanf("%d",&no);
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)//把编号和总量和库存都设成0，认为已经删除此图书
        {
            isexist=1;//如果图书编号存在，则isexist变量置1
            book1[i].no=0;
            book1[i].total=0;
            book1[i].kucun=0;
        }
    }
    if(isexist==0)//如果图书编号不存在，则提示无此图书
    {
        printf("无此图书\n");
    }
    returnMenu();
}
void selectbooks() //查询图书信息
{
    int no,i,isexist=0;
    printf("输入要查询的图书编号：\n");
    scanf("%d",&no);
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)
        {
            isexist=1;//如果图书编号存在，则isexist变量置1
            printf("图书编号：\n");
            printf("%d\n",book1[i].no);
            printf("图书借阅人：\n");
            printf("%s\n",book1[i].jieyueren);
            printf("借阅天数：\n");
            printf("%d\n",book1[i].day);
            printf("图书总量：\n");
            printf("%d\n",book1[i].total);
            printf("图书库存：\n");
            printf("%d\n",book1[i].kucun);
            printf("图书名称：\n");
            printf("%s\n",book1[i].name);
            printf("图书作者：\n");
            printf("%s\n",book1[i].author);
        }
    }
    if(isexist==0)//如果图书编号不存在，则提示无此图书
    {
        printf("无此图书\n");
    }
    returnMenu();
}
void alterbooks()  //修改图书信息
{
    int no,i,isexist=0;
    printf("输入要修改的图书编号：\n");
    scanf("%d",&no);
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)
        {
            isexist=1;//如果图书编号存在，则isexist变量置1
            printf("输入图书借阅人：\n");
            scanf("%s",book1[i].jieyueren);
            printf("输入借阅天数：\n");
            scanf("%d",&book1[i].day);
            printf("输入图书总量：\n");
            scanf("%d",&book1[i].total);
            printf("输入图书库存：\n");
            scanf("%d",&book1[i].kucun);
            printf("输入图书名称：\n");
            scanf("%s",book1[i].name);
            printf("输入图书作者：\n");
            scanf("%s",book1[i].author);
        }
    }
    if(isexist==0)//如果图书编号不存在，则提示无此图书
    {
        printf("无此图书\n");
    }
    returnMenu();
}
//菜单函数
void menu()
{
    int x = 0;
    printf("图书借阅管理系统\n");
    printf("1.图书信息录入\n2.图书借阅\n3.图书删除\n4.图书查询\n5.图书信息修改\n");
    scanf("%d",&x);//根据不同的输入调用不同的函数
    if(x==1)
    {
        input();
    }
    if(x==2)
    {
        jieyue();
    }
    if(x==3)
    {
        deletebooks();
    }
    if(x==4)
    {
        selectbooks();
    }
    if(x==5)
    {
        alterbooks();
    }
}
//主函数
int main ()
{
    menu();
    return 0;
}
