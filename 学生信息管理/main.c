/*
    c   �ַ�����    �ṹ��    �˵�
    ������    ѧ����Ϣ����ϵͳ���˵�ѡ���ܣ��Գɼ���Ϣ��ɾ�Ĳ�,�޳ɼ�
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
    char birth[20];
    char address[20];
    char phone[20];
    char email[20];
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
    printf("����ѧ�����䣺\n");
    scanf("%s",student[total].age);
    printf("����ѧ���Ա�\n");
    scanf("%s",student[total].gender);
    printf("����ѧ�����գ�\n");
    scanf("%s",student[total].birth);
    printf("����ѧ����ַ��\n");
    scanf("%s",student[total].address);
    printf("����绰��\n");
    scanf("%s",student[total].phone);
    printf("����email��\n");
    scanf("%s",student[total].email);
    total++; //¼��һ��ѧ����Ϣ��ѧ��������1
    printf("����ɹ�!\n");
    returnMenu();
}
void selectStudent()
{
    int no,x,i,isexist=0;
    char name[20];
    printf("1.��ѧ�Ų�ѯ\n2.��������ѯ\n");
    scanf("%d",&x);
    if(x==1){
        printf("����Ҫ��ѯ��ѧ�ţ�\n");
        scanf("%d",&no);
        for(i=0;i<total;i++)
        {
            if(student[i].no==no)
            {
                isexist=1;//���ѧ�Ŵ��ڣ���isexist������1
                printf("ѧ�� ���� ���� �Ա� ���� ��ַ �绰 email\n");
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
        printf("����Ҫ��ѯ��������\n");
        scanf("%s",&no);
        for(i=0;i<total;i++)
        {
            if(strcmp(student[i].name,name)==0)
            {
                isexist=1;//���ѧ�Ŵ��ڣ���isexist������1
                printf("ѧ�� ���� ���� �Ա� ���� ��ַ �绰 email\n");
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
    if(isexist==0)//���ѧ�Ų����ڣ�����ʾ�޴�ѧ��
    {
        printf("�޴�ѧ����Ϣ\n");
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
            printf("����ѧ���Ա�\n");
            scanf("%s",student[i].gender);
            printf("����ѧ�����գ�\n");
            scanf("%s",student[i].birth);
            printf("����ѧ����ַ��\n");
            scanf("%s",student[i].address);
            printf("����绰��\n");
            scanf("%s",student[i].phone);
            printf("����email��\n");
            scanf("%s",student[i].email);
        }
    }
    if(isexist==0)
    {
        printf("�޴�ѧ����Ϣ\n");
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
                    //strcpy(name[j-1],name[j]);
                }
                total--;
            }
            break;
        }
    }
    if(isexist==0)//���ͼ���Ų����ڣ�����ʾ�޴�ͼ��
    {
        printf("�޴�ѧ����Ϣ\n");
    }
    printf("ɾ���ɹ�!\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("ѧ�� ���� ���� �Ա� ���� ��ַ �绰 email\n");
    for(i=0;i<total;i++)
    {
        printf("%d %s %s %s %s %s %s %s\n",student[i].no,student[i].name,student[i].age,student[i].gender,student[i].birth,student[i].address,student[i].phone,student[i].email);
    }
    printf("��ʾ�ɹ���");
    returnMenu();
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
    printf("5.���ѧ����Ϣ\n");
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
        printf("��������\n");
        returnMenu();
    }
}
int main()
{
    menu();
    return 0;
}
