#include <stdio.h>
#include <stdlib.h>
int arrayInt[10],n,i,j;
void arrayInput()
{
    printf("输入数组大小（n<10）\n");
    scanf("%d",&n);
    printf("输入数组\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arrayInt[i]);
    }
}

void arraydisp()
{
    printf("数组内容如下：\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arrayInt[i]);
    }
    printf("\n");
}

void arrayOrder()
{
    int temp,min,position;
    for(i=0;i<n-1;i++)
    {
        min=arrayInt[i];
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(arrayInt[j]<min)
            {
                min=arrayInt[j];
                position=j;
            }
        }
        temp=arrayInt[i];
        arrayInt[i]=min;
        arrayInt[position]=temp;
    }
}

int searchHalf(int x)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arrayInt[mid]>x)
        {
            high=mid-1;
        }else if(arrayInt[mid]<x)
        {
            low=mid+1;
        }else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int x;
    arrayInput();
    arraydisp();
    printf("输入要查找的数字:\n");
    scanf("%d",&x);
    arrayOrder();
    printf("排序之后");
    arraydisp();
    if(searchHalf(x))
    {
        printf("%d存在于数组中\n",x);
    }else
    {
        printf("%d不存在于数组中\n",x);
    }
    return 0;
}
