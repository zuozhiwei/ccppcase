/*
    c   �ַ�����    �ṹ��    �˵�   �ļ�����
    ������    ѧ���ɼ�����ϵͳ���˵�ѡ���ܣ��Գɼ���Ϣ��ɾ�Ĳ�,��д�ļ�
    ʱ��        2018-1-4
    ����        ��־ΰ
    ����        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentStruct
{
    char no[10];
    char name[20];
    char gender[4];
    char birth[20];   /*��������*/
	float english;   /*Ӣ��ɼ�*/
	float math;    /*��ѧӢ��ɼ�*/
	float mcu;    /*������ɼ�*/
    float score;
}student[100];
//ѧ������
int total=0;
//��������
void returnMenu();
void menu();
void selectStudent(int);
void viewStudent();
void deleteStudent();
void alterStudent();
void orderStudent();
void inputStudent();
void totalScore();
void readFile();
void writeFile();
void orderByTotal();
void cal();
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
    char no[10];
    int m=0,i=0;
    printf("����ѧ�ţ�\n");
    scanf("%s",no);
    for(i=0;i<total;i++)
    {
        if(strcmp(student[i].no,no)==0)
        {
            m=1;
        }
    }
    if(m==1)
    {
         printf("ѧ���Ѵ��ڣ�����������\n");
         inputStudent();
    }
    strcpy(student[total].no,no);
    printf("����ѧ��������\n");
    scanf("%s",student[total].name);
    printf("����ѧ���Ա�\n");
    scanf("%s",student[total].gender);
    printf("����ѧ���������£�\n");
    scanf("%s",student[total].birth);
    printf("����Ӣ��ɼ���\n");
    scanf("%f",&student[total].english);
    printf("������ѧ�ɼ���\n");
    scanf("%f",&student[total].math);
    printf("���������ɼ���\n");
    scanf("%f",&student[total].mcu);
    student[total].score=student[total].english+student[total].math+student[total].mcu;
    total++; //¼��һ��ѧ����Ϣ��ѧ��������1
    printf("����ɹ�!\n");
    returnMenu();
}
void selectStudent(int x)
{
    int i,isexist=0;
    char no[10],name[10];
    if(x==1)
    {
        printf("����Ҫ��ѯ��ѧ�ţ�\n");
        scanf("%s",no);
        for(i=0;i<total;i++)
        {
            if(strcmp(student[i].no,no)==0)
            {
                isexist=1;//���ѧ�Ŵ��ڣ���isexist������1
                printf("ѧ��ѧ��  ѧ������  ѧ���Ա�    ѧ������      Ӣ��ɼ�    ��ѧ�ɼ�   ������ɼ�   �ܷ�\n");
                printf("%s\t   ",student[i].no);
                printf("%s\t     ",student[i].name);
                printf("%s\t     ",student[i].gender);
                printf("%s\t",student[i].birth);
                printf("%.2f\t  ",student[i].english);
                printf("%.2f\t    ",student[i].math);
                printf("%.2f\t",student[i].mcu);
                printf("%.2f\n",student[i].score);
            }
        }
        if(isexist==0)//���ѧ�Ų����ڣ�����ʾ�޴�ѧ��
        {
            printf("�޴�ѧ����Ϣ\n");
        }
    }
    if(x==2)
    {
        printf("����Ҫ��ѯ��������\n");
        scanf("%s",&name);
        for(i=0;i<total;i++)
        {
            if(strcmp(student[i].name,name)==0)
            {
                isexist=1;//���ѧ�Ŵ��ڣ���isexist������1
                printf("ѧ��ѧ��  ѧ������  ѧ���Ա�    ѧ������      Ӣ��ɼ�    ��ѧ�ɼ�   ������ɼ�   �ܷ�\n");
                printf("%s\t   ",student[i].no);
                printf("%s\t     ",student[i].name);
                printf("%s\t     ",student[i].gender);
                printf("%s\t",student[i].birth);
                printf("%.2f\t  ",student[i].english);
                printf("%.2f\t    ",student[i].math);
                printf("%.2f\t",student[i].mcu);
                printf("%.2f\n",student[i].score);
            }
        }
        if(isexist==0)//���ѧ�Ų����ڣ�����ʾ�޴�ѧ��
        {
            printf("�޴�ѧ����Ϣ\n");
        }
    }
    if(x==3)
    {
        printf("��������Ϣ\n");
        for(i=0;i<total;i++)
        {
            if((student[i].english<60)||(student[i].math<60)||(student[i].mcu<60))
            {
                isexist=1;//���ѧ�Ŵ��ڣ���isexist������1
                printf("ѧ��ѧ��  ѧ������  ѧ���Ա�    ѧ������      Ӣ��ɼ�    ��ѧ�ɼ�   ������ɼ�   �ܷ�\n");
                printf("%s\t   ",student[i].no);
                printf("%s\t     ",student[i].name);
                printf("%s\t     ",student[i].gender);
                printf("%s\t",student[i].birth);
                printf("%.2f\t  ",student[i].english);
                printf("%.2f\t    ",student[i].math);
                printf("%.2f\t",student[i].mcu);
                printf("%.2f\n",student[i].score);
            }
        }
        if(isexist==0)//���ѧ�Ų����ڣ�����ʾ�޴�ѧ��
        {
            printf("��ѧ����Ϣ\n");
        }
    }
    printf("��ѯ������\n");
    returnMenu();
}

void  alterStudent()
{
    int i,isexist=0;
    char no[10];
    printf("����Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
    scanf("%s",&no);
    for(i=0;i<total;i++)
    {
        if(strcmp(student[i].no,no)==0)
        {
            isexist=1;
            printf("����ѧ��������\n");
            scanf("%s",student[i].name);
            printf("����ѧ���Ա�\n");
            scanf("%s",student[i].gender);
            printf("����ѧ�����գ�\n");
            scanf("%s",student[i].birth);
            printf("����Ӣ��ɼ���\n");
            scanf("%f",&student[i].english);
            printf("������ѧ�ɼ���\n");
            scanf("%f",&student[i].math);
            printf("�������ݿ�ɼ���\n");
            scanf("%f",&student[i].mcu);
        }
    }
    if(isexist==0)
    {
        printf("�޴�ѧ����Ϣ\n");
        return;
    }
    printf("�޸ĳɹ���\n");
    writeFile();
    printf("д�����ļ��ɹ�\n");
    returnMenu();
}

void deleteStudent()
{
    int i,j,isexist=0;
    char no[10];
    printf("����Ҫɾ����ѧ��ѧ�ţ�\n");
    scanf("%s",&no);
    for(i=0;i<total;i++)
    {
        if(strcmp(student[i].no,no)==0)
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
    if(isexist==0)
    {
        printf("�޴�ѧ����Ϣ\n");
        return;
    }
    printf("ɾ���ɹ�!\n");
    returnMenu();
}
void viewStudent()
{
    int i=0;
    printf("ѧ�� ���� �Ա�     ����       Ӣ��   ��ѧ   �����  �ܷ�\n");
    for(i=0;i<total;i++)
    {
        printf("%s %s  %s  %s %.2f %.2f %.2f %.2f\n",student[i].no,student[i].name,student[i].gender,student[i].birth,student[i].english,student[i].math,student[i].mcu,student[i].score);
    }
    printf("��ʾ�ɹ���");
    returnMenu();
}
void orderByTotal()
{
    int i,j;
    struct studentStruct studentTemp;
    for(i=0;i<total-1;i++)
    {
        for(j=0;j<total-i-1;j++)
        {
            if(student[j].score>student[j+1].score)
            {
                studentTemp = student[j];
                student[j]=student[j+1];
                student[j+1]=studentTemp;
            }
        }
    }
    viewStudent();
}
void orderStudent()
{
    int x,i,j;
    struct studentStruct studentTemp;
    printf("-------------\n");
    printf("1.����ѧ�ɼ�����\n2.��Ӣ��ɼ�����\n3.��������ɼ�����\n");
    printf("-------------\n");
    scanf("%d",&x);
    if(x==1)
    {
        for(i=0;i<total-1;i++)
        {
            for(j=0;j<total-i-1;j++)
            {
                if(student[j].math>student[j+1].math)
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
                if(student[j].english>student[j+1].english)
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
                if(student[j].mcu>student[j+1].mcu)
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

//���ļ�д��
void readFile()
{
    int i=0,j=0,k=0;
    char strLine[200];
    FILE *fp;
    fp=fopen("studb.txt","r+");
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
            student[i].no[j]=strLine[j];
            j++;
        }
        j++;
        while(strLine[j]!=0x20)
        {
            student[i].name[k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        while(strLine[j]!=0x20)
        {
            student[i].gender[k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        while(strLine[j]!=0x20)
        {
            student[i].birth[k]=strLine[j];
            k++;
            j++;
        }
        j++;
        k=0;
        char cenglish[10];
        while(strLine[j]!=0x20)
        {
            cenglish[k]=strLine[j];
            k++;
            j++;
        }
        (student[i].english)=atof(cenglish);
        j++;
        k=0;
        char cmath[10];
        while(strLine[j]!=0x20)
        {
            cmath[k]=strLine[j];
            k++;
            j++;
        }
        (student[i].math) = atof(cmath);
        j++;
        k=0;
        char cmcu[10];
        while(strLine[j]!='\0')
        {
            cmcu[k]=strLine[j];
            k++;
            j++;
        }
        student[i].mcu=atof(cmcu);
        j=0;
        k=0;
        i++;
        total++;
    }
    i=0;
    for(i=0;i<total;i++)
    {
        student[i].score=student[i].english+student[i].math+student[i].mcu;
    }
    printf("����ɹ������ڷ��ز˵�...\n");
    returnMenu();
}
void cal()
{
    int x=0,i=0;
    float englishTotal=0,mathTotal=0,mcuTotal=0;
    printf("1.ͳ�Ƹ���ƽ���ɼ�\n2.ͳ�Ƹ�����ƽ���ɼ�\n");
    scanf("%d",&x);
    if(x==1)
    {
        printf("ѧ�� ���� ƽ����\n");
        for(i=0;i<total;i++)
        {
            printf("%s  %s  %.2f\n",student[i].no,student[i].name,(student[i].score/3.0));
        }
    }
    if(x==2)
    {
        for(i=0;i<total;i++)
        {
            englishTotal+=(student[i].english);
            mathTotal+=(student[i].math);
            mcuTotal+=(student[i].mcu);
        }
        printf("Ӣ��  ��ѧ  �����\n");
        printf("%.2f %.2f %.2f\n",(englishTotal/total),(mathTotal/total),(mcuTotal/total));
    }
    returnMenu();
}

//д�����ļ�
void writeFile()
{
    int i=0;
    FILE *fp;
    fp=fopen("newstudb.txt","w");
    if(fp==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    if(total==0)
    {
        printf("��ϢΪ�գ�����д�룡���ڷ��ز˵�...");
        return;
    }
    for(i=0;i<total;i++)
    {
        fprintf(fp,"%s %s %s %s %f %f %f %f\n",student[i].no,student[i].name,student[i].gender,student[i].birth,student[i].english,student[i].math,student[i].mcu,student[i].score);//��ʽ��д���ļ���׷�����ļ�ĩβ��
    }
    fclose(fp);
    printf("д��ɹ������ڷ��ز˵�...\n");
    returnMenu();
}

void menu()
{
    int x=0;
    printf("-------------\n");
    printf("ѧ���ɼ�����ϵͳ��\n");
    printf("1.�����ݿ����ѧ����Ϣ\n");
    printf("2.��ѧ�Ų�ѯѧ����Ϣ\n");
    printf("3.��������ѯѧ����Ϣ\n");
    printf("4.��ѯ����ѧ����Ϣ\n");
    printf("5.���ݵ��Ƴɼ���������\n");
    printf("6.���ѧ����Ϣ\n");
    printf("7.ɾ��ѧ����Ϣ\n");
    printf("8.�޸�ѧ����Ϣ\n");
    printf("9.ͳ�Ʋ�����ѧ����Ϣ\n");
    printf("10.ͳ��ƽ���ɼ�\n");
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
            selectStudent(1);
            break;
        case 3:
            selectStudent(2);
            break;
        case 4:
            viewStudent();
            break;
        case 5:
            orderStudent();
            break;
        case 6:
            inputStudent();
            break;
        case 7:
            deleteStudent();
            break;
        case 8:
            alterStudent();
            break;
        case 9:
            selectStudent(3);
            break;
        case 10:
            cal();
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
