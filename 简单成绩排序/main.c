/*
    c   �ַ�����    �ṹ��    �˵�   ð��
    ������    ѧ����Ϣ���򣬲˵�ѡ���ܣ�����Ϣ����¼�������
    ʱ��        2018-1-5
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
    int score;
}student[100];
//ѧ������
int total=0;
//��������
void returnMenu();
void menu();
void viewStudent();
void orderStudent();
void inputStudent();
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
    printf("����ɼ���\n");
    scanf("%d",&student[total].score);
    total++; //¼��һ��ѧ����Ϣ��ѧ��������1
    printf("����ɹ�!\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("ѧ�� ���� �ɼ�\n");
    for(i=0;i<total;i++)
    {
        printf("%d %s %d\n",student[i].no,student[i].name,student[i].score);
    }
    printf("��ʾ�ɹ���");
    returnMenu();
}
void orderStudent()
{
    int i,j;
    struct studentStruct studentTemp;
    for(i=0;i<total-1;i++)
    {
        for(j=0;j<total-i-1;j++)
        {
            if(student[j].score<student[j+1].score)
            {
                studentTemp = student[j];
                student[j]=student[j+1];
                student[j+1]=studentTemp;
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
    printf("2.������ʾ\n");
    printf("-------------\n");
    scanf("%d",&x);
    if(x==1)
    {
        inputStudent();
    }
    else if(x==2)
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
