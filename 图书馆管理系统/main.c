/*
    c   �ַ�����    �ṹ��    �˵�
    ������    ͼ��ݹ���ϵͳ��ͼ����Ϣ����ɾ�Ĳ�
    ʱ��        2018-1-3
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/
#include <stdio.h>
#include <stdlib.h>
int books=0; //����ͼ����������
struct book //����ͼ��ṹ��
{
    int no; //ͼ����
    char jieyueren[20]; //����������
    int day; //��������
    int total;  //ͼ������
    int kucun;  //ͼ����
    char name[100]; //����
    char author[100];   //����
}book1[100];//����ṹ��
//��������
void menu();
void input();
void deletebooks();
void selectbooks();
void alterbooks();
void jieyue();

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

//��������
void input()    //¼��ͼ����Ϣ
{
    printf("����ͼ���ţ�\n");
    scanf("%d",&book1[books].no);
    printf("����ͼ������ˣ�\n");
    scanf("%s",book1[books].jieyueren);
    printf("�������������\n");
    scanf("%d",&book1[books].day);
    printf("����ͼ��������\n");
    scanf("%d",&book1[books].total);
    printf("����ͼ���棺\n");
    scanf("%d",&book1[books].kucun);
    printf("����ͼ�����ƣ�\n");
    scanf("%s",book1[books].name);
    printf("����ͼ�����ߣ�\n");
    scanf("%s",book1[books].author);
    books++; //¼��һ��ͼ����Ϣ��ͼ������������1
    returnMenu();
}
void jieyue()   //����ͼ��
{
    int no,i,isexist=0;
    printf("�������ͼ���ţ�\n");
    scanf("%d",&no);    //����ͼ���Ÿ�ֵ��no
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)
        {
            isexist=1;//���ͼ���Ŵ��ڣ���isexist������1
            printf("���������������\n");
            scanf("%s",book1[i].jieyueren);
            printf("�������������\n");
            scanf("%d",&book1[i].day);
            book1[i].kucun--;//�޸�ͼ����Ϣ
        }
    }
    if(isexist==0)//���ͼ���Ų����ڣ�����ʾ�޴�ͼ��
    {
        printf("�޴�ͼ��\n");
    }
    returnMenu();
}

void deletebooks() //ɾ��ͼ����Ϣ
{
    int no,i,isexist=0;
    printf("����Ҫɾ����ͼ���ţ�\n");
    scanf("%d",&no);
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)//�ѱ�ź������Ϳ�涼���0����Ϊ�Ѿ�ɾ����ͼ��
        {
            isexist=1;//���ͼ���Ŵ��ڣ���isexist������1
            book1[i].no=0;
            book1[i].total=0;
            book1[i].kucun=0;
        }
    }
    if(isexist==0)//���ͼ���Ų����ڣ�����ʾ�޴�ͼ��
    {
        printf("�޴�ͼ��\n");
    }
    returnMenu();
}
void selectbooks() //��ѯͼ����Ϣ
{
    int no,i,isexist=0;
    printf("����Ҫ��ѯ��ͼ���ţ�\n");
    scanf("%d",&no);
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)
        {
            isexist=1;//���ͼ���Ŵ��ڣ���isexist������1
            printf("ͼ���ţ�\n");
            printf("%d\n",book1[i].no);
            printf("ͼ������ˣ�\n");
            printf("%s\n",book1[i].jieyueren);
            printf("����������\n");
            printf("%d\n",book1[i].day);
            printf("ͼ��������\n");
            printf("%d\n",book1[i].total);
            printf("ͼ���棺\n");
            printf("%d\n",book1[i].kucun);
            printf("ͼ�����ƣ�\n");
            printf("%s\n",book1[i].name);
            printf("ͼ�����ߣ�\n");
            printf("%s\n",book1[i].author);
        }
    }
    if(isexist==0)//���ͼ���Ų����ڣ�����ʾ�޴�ͼ��
    {
        printf("�޴�ͼ��\n");
    }
    returnMenu();
}
void alterbooks()  //�޸�ͼ����Ϣ
{
    int no,i,isexist=0;
    printf("����Ҫ�޸ĵ�ͼ���ţ�\n");
    scanf("%d",&no);
    for(i=0;i<books;i++)
    {
        if(book1[i].no==no)
        {
            isexist=1;//���ͼ���Ŵ��ڣ���isexist������1
            printf("����ͼ������ˣ�\n");
            scanf("%s",book1[i].jieyueren);
            printf("�������������\n");
            scanf("%d",&book1[i].day);
            printf("����ͼ��������\n");
            scanf("%d",&book1[i].total);
            printf("����ͼ���棺\n");
            scanf("%d",&book1[i].kucun);
            printf("����ͼ�����ƣ�\n");
            scanf("%s",book1[i].name);
            printf("����ͼ�����ߣ�\n");
            scanf("%s",book1[i].author);
        }
    }
    if(isexist==0)//���ͼ���Ų����ڣ�����ʾ�޴�ͼ��
    {
        printf("�޴�ͼ��\n");
    }
    returnMenu();
}
//�˵�����
void menu()
{
    int x = 0;
    printf("ͼ����Ĺ���ϵͳ\n");
    printf("1.ͼ����Ϣ¼��\n2.ͼ�����\n3.ͼ��ɾ��\n4.ͼ���ѯ\n5.ͼ����Ϣ�޸�\n");
    scanf("%d",&x);//���ݲ�ͬ��������ò�ͬ�ĺ���
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
//������
int main ()
{
    menu();
    return 0;
}
