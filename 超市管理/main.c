/*
	c   �ַ�����    �ṹ��    string   �˵�  �ļ�����
	������    ���й���¼����Ʒ��������Ʒ��ӯ�����ж�Ӧ�ý�ʲô��
	ʱ��        2018-1-2
	����        ��־ΰ
	����        zuozhiwei0@qq.com
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
//��Ʒ����
int total=0;
//��������
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
//��������
void returnMenu()
{
    char x;
    printf("�Ƿ񷵻����˵���\n(y�����أ�n��������)\n");
    fflush(stdin);
    x=getchar();
    if(x=='y')
    {
        system("cls");
        menu();
    }else{
        system("cls");
        printf("�˳�ϵͳ...");
        exit(0);
    }
}

void inputProduct()    //¼����Ʒ��Ϣ
{
    char name[10];
    int m=0,i=0,x;
    printf("1.¼������Ʒ\n2.�޸���Ʒ����\n");
    scanf("%d",&x);
    if(x==1)
    {
        printf("������Ʒ���ƣ�\n");
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
             printf("��Ʒ�Ѵ��ڣ�����������\n");
             inputProduct();
        }
        strcpy(product[total].name,name);
        printf("����۸�\n");
        scanf("%f",&product[total].price);
        printf("����������\n");
        scanf("%d",&product[total].number);
        printf("���뱣���ڣ�\n");
        scanf("%s",product[total].limitDate);
        total++; //¼��һ����Ʒ��Ϣ����Ʒ������1
    }
    if(x==2)
    {
        printf("������Ʒ���ƣ�\n");
        scanf("%s",name);
        for(i=0;i<total;i++)
        {
            if(strcmp(product[i].name,name)==0)
            {
                printf("����Ҫ�޸ĵ�����\n");
                scanf("%d",&product[i].number);
                m=1;
            }
        }
        if(m!=1)
        {
             printf("��Ʒ�����ڣ�����������\n");
             inputProduct();
        }
    }
    printf("����ɹ�!\n");
    returnMenu();
}

void  alterProduct()
{
    int i,isexist=0;
    char name[20];
    printf("����Ҫ�޸ĵ���Ʒ���ƣ�\n");
    scanf("%s",name);
    for(i=0;i<total;i++)
    {
        if(strcmp(product[i].name,name)==0)
        {
            isexist=1;
            printf("������Ʒ�۸�\n");
            scanf("%f",&product[i].price);
        }
    }
    if(isexist==0)
    {
        printf("�޴���Ʒ��Ϣ\n");
    }
    printf("�޸Ľ�����\n");
    returnMenu();
}

void deleteProduct()
{
    int i,j,isexist=0;
    char name[20];
    printf("����Ҫɾ������Ʒ���ƣ�\n");
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
        printf("�޴���Ʒ��Ϣ\n");
    }
    printf("�¼ܽ���!\n");
    returnMenu();
}
void viewProduct()
{
    int i=0;
    printf("��Ʒ���� �۸� ���� ������\n");
    for(i=0;i<total;i++)
    {
        printf("%s   %.2f  %d %s\n",product[i].name,product[i].price,product[i].number,product[i].limitDate);
    }
    printf("��ʾ�ɹ���");
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

//���ļ�д��
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
    while (!feof(fp))                                   //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strLine,200,fp);                  //��fp��ָ����ļ�һ�����ݶ���strLine������
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
    printf("����ɹ������ڷ��ز˵�...\n");
    returnMenu();
}

void sale()
{
    char name[20];
    int m=0,i=0,inumber=0;
    printf("������Ʒ���ƣ�\n");
    scanf("%s",name);
    for(i=0;i<total;i++)
    {
        if(strcmp(product[i].name,name)==0)
        {
            printf("������������\n");
            scanf("%d",&inumber);
            if(product[i].number<inumber)
            {
                printf("���㹻���,��������\n");
                sale();
            }else{
                product[i].number-=inumber;
                product[i].asset+=product[i].price*inumber;
                printf("����Ϊ:%f\n",product[i].asset);
            }
            m=1;
        }
    }
    if(m!=1)
    {
         printf("��Ʒ�����ڣ�����������\n");
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
    printf("Ӧ�ö���ڵ���Ʒ��:%s\n",product[0].name);
    returnMenu();
}
void menu()
{
    int x=0;
    printf("-------------\n");
    printf("���й���ϵͳ��\n");
    printf("1.¼������\n");
    printf("2.��ʾ\n");
    printf("3.�޸���Ʒ��Ϣ\n");
    printf("4.�����Ʒ��Ϣ\n");
    printf("5.ɾ����Ʒ��Ϣ\n");
    printf("6.���ݱ����ڽ�������\n");
    printf("7.����\n");
    printf("8.ͳ�ƽ�����Ʒ\n");
    printf("9.ʣ����Ʒ��Ϣ\n");
    printf("0.�˳�\n");
    printf("-------------\n");
    scanf("%d",&x);
    switch(x)
    {
        case 0:
            printf("�˳�ϵͳ...\n");
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
            printf("��������\n");
            returnMenu();
    }
}
int main()
{
    menu();
    return 0;
}
