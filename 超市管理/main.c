/*
	c   字符数组    结构体    string   菜单  文件操作
	程序功能    超市管理，录入商品，卖掉商品，盈利，判断应该进什么货
	时间        2018-1-2
	作者        左志伟
	邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct productStruct
{
    char name[20];
	float price;
	int number;
	char limitDate[20];
	float asset;
}product[100];
//商品总数
int total=0;
//函数声明
void returnMenu();
void menu();
void viewProduct();
void deleteProduct();
void alterProduct();
void orderByAsset();
void inputProduct();
void readFile();
void orderByLimitDate();
void sale();
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

void inputProduct()    //录入商品信息
{
    char name[10];
    int m=0,i=0,x;
    printf("1.录入新商品\n2.修改商品数量\n");
    scanf("%d",&x);
    if(x==1)
    {
        printf("输入商品名称：\n");
        scanf("%s",name);
        for(i=0;i<total;i++)
        {
            if(strcmp(product[i].name,name)==0)
            {
                m=1;
            }
        }
        if(m==1)
        {
             printf("商品已存在！请重新输入\n");
             inputProduct();
        }
        strcpy(product[total].name,name);
        printf("输入价格：\n");
        scanf("%f",&product[total].price);
        printf("输入数量：\n");
        scanf("%d",&product[total].number);
        printf("输入保质期：\n");
        scanf("%s",product[total].limitDate);
        total++; //录入一个商品信息，商品总数加1
    }
    if(x==2)
    {
        printf("输入商品名称：\n");
        scanf("%s",name);
        for(i=0;i<total;i++)
        {
            if(strcmp(product[i].name,name)==0)
            {
                printf("输入要修改的数量\n");
                scanf("%d",&product[i].number);
                m=1;
            }
        }
        if(m!=1)
        {
             printf("商品不存在！请重新输入\n");
             inputProduct();
        }
    }
    printf("输入成功!\n");
    returnMenu();
}

void  alterProduct()
{
    int i,isexist=0;
    char name[20];
    printf("输入要修改的商品名称：\n");
    scanf("%s",name);
    for(i=0;i<total;i++)
    {
        if(strcmp(product[i].name,name)==0)
        {
            isexist=1;
            printf("输入商品价格：\n");
            scanf("%f",&product[i].price);
        }
    }
    if(isexist==0)
    {
        printf("无此商品信息\n");
    }
    printf("修改结束！\n");
    returnMenu();
}

void deleteProduct()
{
    int i,j,isexist=0;
    char name[20];
    printf("输入要删除的商品名称：\n");
    scanf("%s",name);
    for(i=0;i<total;i++)
    {
        if(strcmp(product[i].name,name)==0)
        {
            isexist=1;
            if(i==total-1)
            {
                total--;
            }else
            {
                for(j=i+1;j<total;j++)
                {
                    product[j-1]=product[j];
                    //strcpy(name[j-1],name[j]);
                }
                total--;
            }
            break;
        }
    }
    if(isexist==0)
    {
        printf("无此商品信息\n");
    }
    printf("下架结束!\n");
    returnMenu();
}
void viewProduct()
{
    int i=0;
    printf("商品名称 价格 数量 保质期\n");
    for(i=0;i<total;i++)
    {
        printf("%s   %.2f  %d %s\n",product[i].name,product[i].price,product[i].number,product[i].limitDate);
    }
    printf("显示成功！");
    returnMenu();
}
void orderByLimitDate()
{
    int i,j;
    struct productStruct productTemp;
    for(i=0;i<total-1;i++)
    {
        for(j=0;j<total-i-1;j++)
        {
            if(strcmp(product[j].limitDate,product[j+1].limitDate)>0)
            {
                productTemp = product[j];
                product[j]=product[j+1];
                product[j+1]=productTemp;
            }
        }
    }
    viewProduct();
}

//从文件写入
void readFile()
{
    int i=0,j=0,k=0;
    char strLine[200];
    FILE *fp;
    fp=fopen("product.txt","r+");
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
            product[i].name[j]=strLine[j];
            j++;
        }
        j++;
        char cprice[20];
        k=0;
        while(strLine[j]!=0x20)
        {
            cprice[k]=strLine[j];
            k++;
            j++;
        }
        product[i].price=atof(cprice);
        j++;
        k=0;
        char cnumber[20];
        while(strLine[j]!=0x20)
        {
            cnumber[k]=strLine[j];
            k++;
            j++;
        }
        product[i].number=atoi(cnumber);
        j++;
        k=0;
        while(strLine[j]!='\0')
        {
            product[i].limitDate[k]=strLine[j];
            k++;
            j++;
        }
        j=0;
        k=0;
        i++;
        total++;
    }
    i=0;
    printf("读入成功！正在返回菜单...\n");
    returnMenu();
}

void sale()
{
    char name[20];
    int m=0,i=0,inumber=0;
    printf("输入商品名称：\n");
    scanf("%s",name);
    for(i=0;i<total;i++)
    {
        if(strcmp(product[i].name,name)==0)
        {
            printf("输入卖出数量\n");
            scanf("%d",&inumber);
            if(product[i].number<inumber)
            {
                printf("无足够库存,重新输入\n");
                sale();
            }else{
                product[i].number-=inumber;
                product[i].asset+=product[i].price*inumber;
                printf("收益为:%f\n",product[i].asset);
            }
            m=1;
        }
    }
    if(m!=1)
    {
         printf("商品不存在！请重新输入\n");
         sale();
    }
    returnMenu();
}

void orderByAsset()
{
    int i,j;
    struct productStruct productTemp;
    for(i=0;i<total-1;i++)
    {
        for(j=0;j<total-i-1;j++)
        {
            if(product[j].asset<product[j+1].asset)
            {
                productTemp = product[j];
                product[j]=product[j+1];
                product[j+1]=productTemp;
            }
        }
    }
    printf("应该多进口的商品是:%s\n",product[0].name);
    returnMenu();
}
void menu()
{
    int x=0;
    printf("-------------\n");
    printf("超市管理系统：\n");
    printf("1.录入数据\n");
    printf("2.显示\n");
    printf("3.修改商品信息\n");
    printf("4.添加商品信息\n");
    printf("5.删除商品信息\n");
    printf("6.根据保质期进行排序\n");
    printf("7.收益\n");
    printf("8.统计进口商品\n");
    printf("9.剩余商品信息\n");
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
            viewProduct();
            break;
        case 3:
            alterProduct();
            break;
        case 4:
            inputProduct();
            break;
        case 5:
            deleteProduct();
            break;
        case 6:
            orderByLimitDate();
            break;
        case 7:
            sale();
            break;
        case 8:
            orderByAsset();
            break;
        case 9:
            viewProduct();
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
