/*
    c   素数
    程序功能    输出一个数里面所有的素数
    时间        2018-1-3
    作者        左志伟
    邮箱        zuozhiwei0@qq.com
*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int isSuShu(int x){
    int i = 0,y=0;
    y=(int)(sqrt((double)x))+1;
    for(i=2;i<=y;i++){
        if((x%10)!=1){
            return 0;
        }
        if((x%i)==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a=0,j=0;
    int tem[1500];
    while(scanf("%d",&a)!=EOF){
        int k=0;
        if(!(a>=2&&a<=10000)){
            exit(1);
        }
        for(j=2;j<a;j++){
            if(isSuShu(j)==1){
                //printf("%d ",j);
                tem[k] =j;
                k++;
            }
        }
        if(k==0){
            printf("-1");
        }else{
            for(j=0;j<k-1;j++){
                printf("%d ",tem[j]);
            }
            printf("%d",tem[k-1]);
        }
        printf("\n");
    }
    return 0;
}
