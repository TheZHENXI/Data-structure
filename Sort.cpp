/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-24 19:50:54
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-27 22:56:20
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
//选择
void SelectSort(int* a,int begin,int end)
{
;
}
//堆排序
//1.向下调整算法(小堆)
void Adjustdown(int* a,int n,int root)
{
    int parent = root;
    int child = 2 * parent + 1;
    while(child < n)
    {
        if(child+1 < n && a[child+1] < a[child])
        {
            child++;
        }
        if(a[child] < a[parent])
        {
            swap(&a[child],&a[parent]);
            parent = child;
            child = 2*parent + 1;
        }
        else
        {
            break;
        }
    }
}
//2.构建小堆
void BuildMinheap(int* a,int n)
{
    for(int i = (n-2)/2;i >= 0;i--)
    {
        Adjustdown(a,n,i);
    }
}
//3.堆排序
void HeapSort(int* a,int n)
{
    BuildMinheap(a,n);

    int end = n-1;
    while(end > 0)
    {
        swap(&a[0],&a[end]);
        Adjustdown(a,end,0);
        end--;
    }

}
/*********************************快排**************************************/
//快速排序：时间复杂度O(NlogN),空间复杂度O(logN)
//1.单趟排序(左右指针)   得到左边都比4小，右边都比4大 
// 2 3 8 5 1 4 -> 2 3 1  4   8 5
int PartSort1(int* a,int begin,int end)
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
//单趟排序(挖坑法) 2 3 8 5 1【4】 开始【4】为坑 
//2 3  8 5 1【4】  
//2 3【8】5 1 8 
//2 3 1  5【1】8
//2 3 1 【5】5 8
//2 3 1  4  5 8
int PartSort2(int* a,int begin,int end)
{
    int mid = GetMid(a,begin,end);
    swap(&a[mid],&a[end]);

    int Key = a[end];
    while(begin < end)
    {
        //begin找比key大的值，放到坑里
        while(begin < end && a[begin] <= Key)  begin++;
        a[end] = a[begin];
        //end找比Key小的值，放到坑里
        while(begin < end && a[end] >= Key)  end--;
        a[begin] = a[end];
    }
    a[begin] = Key;
    
    return begin;
}
//单趟排序(前后指针法) 2 3 8 5 1 4
int PartSort3(int* a,int begin,int end)
{
    int mid = GetMid(a,begin,end);
    swap(&a[mid],&a[end]);
    
    int KeyIndex = end;
    int Prev = begin - 1;
    int cur = begin;
    while(cur < end)
    {
        if(a[cur] < a[KeyIndex] && ++Prev != cur)
        {
            swap(&a[Prev],&a[cur]);
        }
        cur++;
    }
    swap(&a[++Prev],&a[KeyIndex]);

    return Prev;
}
//2.整体（多趟） 利用递归实现
void QuickSort(int* a,int left,int right)
{
    if(left >= right)
        return;
    
    int index = PartSort3(a,left,right);
    QuickSort(a,left,index-1);
    QuickSort(a,index+1,right);
}
//2.整体（多趟） 非递归实现（利用栈模拟)
void QuickSortNonR(int* a,int left,int right)
{
    Stack st;
    InitStack(&st);

    StackPush(&st,right);
    StackPush(&st,left);
    //只要栈不为空，就一直排，然后往下分割，直到都分割区间为1或者不存在
    while(!IsEmptyStack(&st))
    {
        int begin = StackTop(&st);
        StackPop(&st);
        int end = StackTop(&st);
        StackPop(&st);
        //大区间依然用单趟排 [begin,end]
        int div = PartSort3(a,begin,end);
        //[begin,div-1] div [div+1,end]
        //判断分割区间的合法性，合法则入栈，否则结束
        if(div+1 < end)/
        {
            StackPush(&st,end);
            StackPush(&st,div+1);
        }
        if(div-1 > begin)
        {
            StackPush(&st,div-1);
            StackPush(&st,begin);
        }
    }
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
//归并：递归实现
void _MergeSort(int* a,int left,int right,int* tmp)
{
	if(left >= right)
		return ;
	//将[left,mid]、[mid+1,right]分别排好序
	int mid = (left+right)/2;
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);
	//将[left,mid]与[mid+1,right]合并排序
	int begin1 = left,end1 = mid;
	int begin2 = mid+1,end2 = right;
	int index = begin1;
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//将归并好的数组，拷贝到原数组
	for(int i = left;i <= right;i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a,0,n-1,tmp);
	free(tmp);
}
//归并：非递归实现（注意边界）
void MergeTwoArr(int* a,int begin1,int end1,int begin2,int end2,int* tmp)
{
    int left = begin1,right = end2;
	int index = begin1;
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//将归并好的数组，拷贝到原数组
	for(int i = left;i <= right;i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSortNonR(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	int gap = 1;
	while(gap < n)
	{
		for(int i = 0;i < n;i += 2*gap)//单趟合并
		{
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i,end1 = i+gap-1;
			int begin2 = i+gap,end2 = i+2*gap-1;
			//合并时只有第一组，第二组不存在，便不需要合并
			//例如gap =2 时，防止 2 6 4 8 6 7 这种情况
			if(begin2 >=n)
				break;
			//合并时第二组的数组只有部分数据，需要修正end2的边界
			//防止 2 6 4 8 6 7 1 这种情况
			if(end2 >= n)
				end2 = n-1;
			MergeTwoArr(a,begin1,end1,begin2,end2,tmp);
		}
		gap *= 2;
	}
	free(tmp);
}
/********************************主函数**************************************/
int main()
{
    int a[] = {6,5,2,1,4,3};
    Print(a,sizeof(a)/sizeof(int));
    // InsertSort(a,sizeof(a)/sizeof(int));
    // Print(a,sizeof(a)/sizeof(int));
    //ShellSort(a,sizeof(a)/sizeof(int));
    //QuickSort(a,0,sizeof(a)/sizeof(int)-1);
    HeapSort(a,sizeof(a)/sizeof(int));
    Print(a,sizeof(a)/sizeof(int));

    return 0;
}
