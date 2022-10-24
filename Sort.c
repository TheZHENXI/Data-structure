/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-24 19:50:54
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-24 22:49:19
 * @FilePath: /CCODE/object/Sort.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>

void Print(int* a,int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
//插入排序
void InsertSort(int* a,int n)
{
    //控制end，从0,n-2
    //5 2 7 3 1
    //5 | 2
    //2 5 | 7
    //2 5 7 | 3
    //2 3 5 7 | 1  end最大到n-2的位置
    //1 2 3 5 7 
    for(int i = 0;i < n-1;i++)
    {
        //将end+1的数据插入到[0,end]的有序空间中
        int end = i;
        int tmp = a[end+1];//要插入的数值
        while(end >= 0)
        {
            if(tmp < a[end])
            {
                a[end+1] = a[end];
                end--;
            }
            else
            {
                break;
            }        

        }
        //在遇到比tmp小的数时或者end已经为负数
        a[end+1] = tmp;
    }
}
//希尔排序
void ShellSort(int* a,int n)
{
    int gap = n;
    while(gap > 1)
    {
        //先进行预排，最后插入排序
        gap = gap/3 + 1;
        for(int i = 0;i < n-gap;i++)
        {
            //例如:gap = 3
            //9 8 7 6 5 4 3 2 1 0 
            //|     |     |     |
            //  |     |     | 
            //    |      |    |
            int end = i;
            int tmp = a[end+gap];//要插入的数
            while(end >= 0)
            {
                if(tmp < a[end])
                {
                    a[end+gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end+gap] = tmp;
        }
        Print(a,n);
    }

}
int main()
{
    int a[] = {5,3,6,7,8,1};
    Print(a,sizeof(a)/sizeof(int));
    // InsertSort(a,sizeof(a)/sizeof(int));
    // Print(a,sizeof(a)/sizeof(int));
    ShellSort(a,sizeof(a)/sizeof(int));
    Print(a,sizeof(a)/sizeof(int));
    return 0;
}