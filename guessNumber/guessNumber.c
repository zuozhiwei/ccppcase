#include <stdio.h>
#include <stdlib.h>
//����С���ӣ����������С->���������������->����������²⡣��ϸ���迴��Ŀ¼�µ�ͼƬ
//��������
void menu();
void runGame();
void rules();
void exitGame();
int generateRand();
//�˵�����
void menu()
{
    int m;
    printf("Guess game\n");
    printf("1.New game!\n");
    printf("2.How to play?\n");
    printf("3.Exit game!\n");
    scanf("%d",&m);
    if(m==1)
    {
        runGame();
    }
    if(m==2)
    {
        rules();
    }
    if(m==3)
    {
        exitGame();
    }

}
//���������
int generateRand()
{
    return rand();
    printf("%d",rand());
}
//��Ϸ����
void rules()
{
    printf("���ݲ˵�ѡ����Ӧ���ܡ�\n��ʼ��Ϸ��������һ����ϷҪ�µ����ֵĸ�����Ȼ��������Щ����֮�󣬿�ʼ������\n");
    menu();
}
//�˳�
void exitGame()
{
    exit(0);
}
//��Ϸִ�й���
void runGame()
{
    int i,j,n,num[10],count=0;
    printf("input the total number!(n<9)\n");
    scanf("%d",&n);
    //�������������
    srand((unsigned)time(0));
    //�����������ֵ��num����
    for(i=0;i<n;i++)
    {
        num[i]=generateRand();
    }
    printf("numbers have generated!Please guess.(you should input %d numbers)\n",n);

    //test infomation start���������ɵ������������ɾ��
    printf("-----------\ntest infomation:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
     printf("\n-----------\n");
    //test infomation end �������ɵ������������ɾ��

    while(1)
    {
        int guess[10],vTpT=0,vTPF=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&guess[i]);
        }
        printf("you input is:\n");
        for(i=0;i<n;i++)
        {
            printf("%d ",guess[i]);
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
            if(num[i]==guess[i])
            {
                vTpT++;
            }
            for(j=i+1;j<n;j++)
            {
                if(guess[i]==num[j])
                {
                    vTPF++;
                }
            }
        }
        count++;
        if(vTpT==n)
        {
            printf("You are clever\n");
            printf("You guess  %d  times\n",count);
            break;
        }else
        {
            printf("%dvTpT%dvTPF\n",vTpT,vTPF);
            printf("guess agin\n");
        }
    }
}
int main()
{
    menu();
    return 0;
}
