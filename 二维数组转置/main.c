/*
    c   二维数组
    程序功能    输入3*4的矩阵，判断其中是否有负数，如果有负数则提醒，并输入正数
                最后转置输出
    时间        2017-12-08
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[3][4],i,j;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            if(a[i][j]<0){
                printf("a[%d][%d] is a minus ,input a positive integer\n",i,j);
                scanf("%d",&a[i][j]);
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
