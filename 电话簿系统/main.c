/*
    c   �ַ�����    �˵�   �ļ�����
    ������    �绰��ϵͳ����ϵ�˵���ɾ�Ĳ飬��д�ļ�
    ʱ��        2018-1-6
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
char name[50][50],danwei[50][50],phone[50][50],email[50][50];
//��������
void menu();
void input();
void alter();
void view();
void select();
void readFile();
void writeFile();
//���뺯��
void input()
{
    printf("��������ϵ����Ϣ��\n");
    printf("���� ������λ �绰���� email\n");
    printf("����������\n");
    scanf("%s",name[total]);
    printf("���빤����λ��\n");
    scanf("%s",danwei[total]);
    printf("����绰���룺\n");
    scanf("%s",phone[total]);
    printf("����email��\n");
    scanf("%s",email[total]);
    total++;
    printf("����ɹ������ڷ��ز˵�...\n");
    menu();
}
//ɾ����Ϣ
void deletes()
{
    char phoneinput[50];
    int i=0,j=0;
    printf("����Ҫɾ���ĺ��룺\n");
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
    printf("\nɾ���ɹ������ڷ��ز˵�...\n");
    menu();
}
//�޸���Ϣ
void alter()
{
    int i=0;
    char phoneTemp[50],nameTemp[50],danweiTemp[50],emailTemp[50];
    printf("����Ҫ�޸ĵ��ֻ���:\n");
    scanf("%s",phoneTemp);
    printf("����������\n");
    scanf("%s",nameTemp);
    printf("���빤����λ��\n");
    scanf("%s",danweiTemp);
    printf("����email��\n");
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
    printf("\n�޸ĳɹ������ڷ��ز˵�...\n");
    menu();
}
//��ѯ��Ϣ
void select()
{
    char nameTemp[50],phoneTemp[50];
    int i=0,n=0;
    i=0;

    printf("1.��������ѯ\n2.���绰�����ѯ\n");
    scanf("%d",&n);
    //��������ѯ
    if(n==1)
    {
        printf("\n����Ҫ��ѯ������:\n");
        scanf("%s",nameTemp);
        for(i=0;i<total;i++)
        {
            if(strcmp(nameTemp,name[i])==0)
            {
                printf("�绰��:\n%s",phone[i]);
                break;
            }
        }
        printf("\n��ѯ�ɹ������ڷ��ز˵�...\n");
        menu();
    }
    //���绰�����ѯ
    if(n==2)
    {
        printf("\n����Ҫ��ѯ�ĵ绰����:\n");
        scanf("%s",phoneTemp);
        for(i=0;i<total;i++)
        {
            if(strcmp(phoneTemp,phone[i])==0)
            {
                printf("������:\n%s",name[i]);
                break;
            }
        }
        printf("\n��ѯ�ɹ������ڷ��ز˵�...\n");
        menu();
    }
}
//��ʾ������Ϣ
void view()
{
    int i=0;
    printf("���� ������λ �绰���� email\n");
    for(i=0;i<total;i++)
    {
        printf("%s %s %s %s\n",name[i],danwei[i],phone[i],email[i]);
    }
    printf("\n�鿴�ɹ������ڷ��ز˵�...\n");
    menu();
}
//������
void order()
{
    int i=0,j=0,n=0;
    char temp[50];
    printf("1.���绰��������\n2.��������ĸ����\n");
    scanf("%d",&n);
    //���绰��������
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
    //����������
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
    printf("����ɹ������ڷ��ز˵�...");
    menu();
}
//д�����ļ�
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
        printf("�绰��Ϊ�գ�����д�룡���ڷ��ز˵�...");
        return;
    }
    //fprintf(fp,"%s %s %s %s",name[0],danwei[0],phone[0],email[0]);//��ʽ��д���ļ���׷�����ļ�ĩβ��
    for(i=0;i<total;i++)
    {
        fprintf(fp,"%s %s %s %s\n",name[i],danwei[i],phone[i],email[i]);//��ʽ��д���ļ���׷�����ļ�ĩβ��
    }
    fclose(fp);
    printf("д��ɹ������ڷ��ز˵�...\n");
    menu();
}
//���ļ�д��
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
    while (!feof(fp))                                   //ѭ����ȡÿһ�У�ֱ���ļ�β
    {
        fgets(strLine,200,fp);                  //��fp��ָ����ļ�һ�����ݶ���strLine������
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
    printf("����ɹ������ڷ��ز˵�...\n");
    menu();
}
//�˵�
void menu()
{
    int n;
    printf("�绰������\n");
    printf("1.�����º���\n2.ɾ������\n3.��ʾ���к���\n4.�޸ĺ���\n5.����\n6.��ѯ\n7.���ļ�����\n8.д�뵽�ļ�\n");
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
//������
int main()
{
    menu();
    return 0;
}
