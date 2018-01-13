/*
    c   �ַ�����    �ṹ��    string   �˵�
    ������    ѧ���ɼ�����ϵͳ���˵�ѡ���ܣ��Գɼ���Ϣ��ɾ�Ĳ�
    ʱ��        2018-1-3
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
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
//ѧ������
int total=0;
//��������
void returnMenu();
void menu();
void selectStudent();
void viewStudent();
void deleteStudent();
void alterStudent();
void orderStudent();
void inputStudent();
void totalScore();
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

void inputStudent()    //¼��ѧ����Ϣ
{
    printf("����ѧ�ţ�\n");
    scanf("%d",&student[total].no);
    printf("����ѧ��������\n");
    scanf("%s",student[total].name);
    printf("����ѧ�����䣺\n");
    scanf("%s",student[total].age);
    printf("����C���Գɼ���\n");
    scanf("%d",&student[total].clanguage);
    printf("����Ӣ��ɼ���\n");
    scanf("%d",&student[total].english);
    printf("�������ݿ�ɼ���\n");
    scanf("%d",&student[total].database);
    student[total].score=student[total].clanguage+student[total].english+student[total].database;
    total++; //¼��һ��ѧ����Ϣ��ѧ��������1
    printf("����ɹ�!\n");
    returnMenu();
}
void selectStudent()
{
    int no,i,isexist=0;
    printf("����Ҫ��ѯ��ѧ�ţ�\n");
    scanf("%d",&no);
    for(i=0;i<total;i++)
    {
        if(student[i].no==no)
        {
            isexist=1;//���ѧ�Ŵ��ڣ���isexist������1
            printf("ѧ��ѧ�� ѧ������ ѧ������ C���Գɼ� Ӣ��ɼ� ���ݿ�ɼ�\n");
            printf("%d\t  ",student[i].no);
            printf("%s\t ",student[i].name);
            printf("%s\t ",student[i].age);
            printf("%d\t ",student[i].clanguage);
            printf("%d\t ",student[i].english);
            printf("%d\n",student[i].database);
        }
    }
    if(isexist==0)//���ѧ�Ų����ڣ�����ʾ�޴�ѧ��
    {
        printf("�޴�ѧ����Ϣ\n");
        return;
    }
    printf("��ѯ�ɹ���\n");
    returnMenu();
}

void  alterStudent()
{
    int no,i,isexist=0;
    printf("����Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
    scanf("%d",&no);
    for(i=0;i<total;i++)
    {
        if(student[i].no==no)
        {
            isexist=1;
            printf("����ѧ��������\n");
            scanf("%s",student[i].name);
            printf("����ѧ�����䣺\n");
            scanf("%s",student[i].age);
            printf("����C���Գɼ���\n");
            scanf("%d",&student[i].clanguage);
            printf("����Ӣ��ɼ���\n");
            scanf("%d",&student[i].english);
            printf("�������ݿ�ɼ���\n");
            scanf("%d",&student[i].database);
        }
    }
    if(isexist==0)//���ͼ���Ų����ڣ�����ʾ�޴�ͼ��
    {
        printf("�޴�ѧ����Ϣ\n");
        return;
    }
    printf("�޸ĳɹ���\n");
    returnMenu();
}

void deleteStudent()
{
    int no,i,j,isexist=0;
    printf("����Ҫɾ����ѧ��ѧ�ţ�\n");
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
        printf("�޴�ѧ����Ϣ\n");
        return;
    }
    printf("ɾ���ɹ�!\n");
    returnMenu();
}
void totalScore()
{
    int i=0;
    printf("ѧ��  �ܷ֣�\n");
    for(i=0;i<total;i++)
    {
        printf("%d\t%d\n",student[i].no,student[i].score);
    }
    printf("�鿴�ֳܷɹ�...\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("ѧ�� ���� ���� C���� Ӣ�� ���ݿ�\n");
    for(i=0;i<total;i++)
    {
        printf("%d %s %s   %d    %d    %d\n",student[i].no,student[i].name,student[i].age,student[i].clanguage,student[i].english,student[i].database);
    }
    printf("��ʾ�ɹ���");
    returnMenu();
}
void orderStudent()
{
    int x,i,j;
    struct studentStruct studentTemp;
    printf("-------------\n");
    printf("1.��ѧ������\n2.��c���Գɼ�����\n3.��Ӣ��ɼ�����\n4.�����ݿ�ɼ�����\n");
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
    printf("ѧ���ɼ�����ϵͳ��\n");
    printf("1.¼��ѧ����Ϣ\n");
    printf("2.��ѯѧ����Ϣ\n");
    printf("3.�޸�ѧ����Ϣ\n");
    printf("4.ɾ��ѧ����Ϣ\n");
    printf("5.�ɼ��ܷ�\n");
    printf("6.������ʾ\n");
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
        printf("��������\n");
        returnMenu();
    }
}
int main()
{
    menu();
    return 0;
}
