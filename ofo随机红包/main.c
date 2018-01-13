/*
    c    随机数
    程序功能    模拟ofo骑行随机红包
    时间        2018-1-13
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int times=0;
    srand((unsigned)time(NULL));
    while(1)
    {
        int x=0;
        times++;
        printf("请输入任意整数来开始骑行\n");
        scanf("%d",&x);
        printf("骑行结束\n");
        x = rand()%100+1;
        if(times<3)
        {
            printf("您已骑行%d次\n",times);
            if(x>(50-times*10))
            {
                printf("您已中奖!奖金为:%.2f\n\n",(3*x/100.0));
            }
            else{
                printf("很遗憾，您没有中奖！再接再厉！\n\n");
            }
        }
        else
        {
            printf("您已骑行%d次，百分之百中奖！\n奖金为:%.2f\n\n",times,(3*x/100.0));
        }

    }
    return 0;
}
