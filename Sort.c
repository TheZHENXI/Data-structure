/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-24 19:50:54
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-25 22:29:04
 * @FilePath: /CCODE/object/Sort.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>

int GetMid(int* a,int begin,int end);
/********************************辅助函数**************************************/
//交换函数
void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//打印函数
void Print(int* a,int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
/********************************插入排序**************************************/
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
/********************************选择排序**************************************/


/*********************************快排**************************************/
//快速排序
//1.单趟排序   得到左边都比4小，右边都比4大 
// 2 3 8 5 1 4 -> 2 3 1  4   8 5
int PartSort(int* a,int begin,int end)
{   
    int mid = GetMid(a,begin,end);
    swap(&a[mid],&a[end]);
    
    int KeyIndex = end;
    while(begin < end)
    {
        while(begin < end && a[begin] <= a[KeyIndex])//在等于时也得后移，避免卡死
        {
            begin++;
        }
        while(begin < end && a[end] >= a[KeyIndex])
        {
            end--;
        }
        swap(&a[begin],&a[end]);
    }
    swap(&a[begin],&a[KeyIndex]);

    return begin;//返回key调整后的位置
}
//2.整体（多趟） 利用递归实现
void QuickSort(int* a,int left,int right)
{
    Print(a,6);
    if(left >= right)
        return;
    
    int index = PartSort(a,left,right);
    QuickSort(a,left,index-1);
    QuickSort(a,index+1,right);
}
//3.三数取中：规避最坏的情况（每次都取到最小或者最大值）出现
int GetMid(int* a,int begin,int end)
{   //begin  >  mid    end
    int mid = begin + end;
    if(a[begin] < a[mid])
    {
        if(a[mid] < a[end])
            return mid;
        else if(a[end] < a[begin])
            return begin;
        else
            return end;
    }
    else
    {
        if(a[mid] > a[end])
            return mid;
        else if(a[end] > a[begin])
            return begin;
        else
            return end;
    }
}
/********************************主函数**************************************/
int main()
{
    int a[] = {6,5,4,3,2,1};
    Print(a,sizeof(a)/sizeof(int));
    // InsertSort(a,sizeof(a)/sizeof(int));
    // Print(a,sizeof(a)/sizeof(int));
    //ShellSort(a,sizeof(a)/sizeof(int));
    QuickSort(a,0,sizeof(a)/sizeof(int)-1);

    return 0;
}
