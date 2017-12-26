#include <stdio.h>
#include <stdlib.h>
//猜数小例子：输入数组大小->生成随机数的数组->输入新数组猜测。详细步骤看本目录下的图片
//函数声明
void menu();
void runGame();
void rules();
void exitGame();
int generateRand();
//菜单函数
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
//生成随机数
int generateRand()
{
    return rand();
    printf("%d",rand());
}
//游戏规则
void rules()
{
    printf("根据菜单选择相应功能。\n开始游戏后先设置一个游戏要猜的数字的个数，然后输入这些数字之后，开始猜数。\n");
    menu();
}
//退出
void exitGame()
{
    exit(0);
}
//游戏执行过程
void runGame()
{
    int i,j,n,num[10],count=0;
    printf("input the total number!(n<9)\n");
    scanf("%d",&n);
    //设置随机数参数
    srand((unsigned)time(0));
    //生成随机数赋值给num数组
    for(i=0;i<n;i++)
    {
        num[i]=generateRand();
    }
    printf("numbers have generated!Please guess.(you should input %d numbers)\n",n);

    //test infomation start，测试生成的随机数，可以删除
    printf("-----------\ntest infomation:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
     printf("\n-----------\n");
    //test infomation end 测试生成的随机数，可以删除

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
