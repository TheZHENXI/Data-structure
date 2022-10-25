#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* data;
	int capacity;
	int size;
}Heap;

void adjustdown(HPDataType*a,int n,int root);
void HeapSort(HPDataType*a,int n);
void HeapInit(Heap*php,HPDataType*a,int n);
void HeapDetroy(Heap*php);
void HeapPush(Heap*php,HPDataType x);
void HeapPop(Heap*php);
HPDataType HeapTop(Heap*php);
void AdjustUp(HPDataType* a,int n,int pos);
void test();
void HeapDestroy(Heap* hp);
/****************************************************************/
int main()
{
	test();
	return 0;
}
void test()
{
    Heap hp;
    HPDataType a[] = {7,2,1,9,5};
    HeapInit(&hp,a,5);
	HeapSort(hp.data,5);
	HeapPush(&hp, 6);
	int ret = HeapTop(&hp);
	HeapPop(&hp);
	HeapDestroy(&hp);
}
//交换
void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//小堆的向下调整算法
void adjustdown(HPDataType* a,int n,int root)//左右都为小堆
{
	int parent = root,child = 2*parent + 1;
	while(child < n)
	{
		if(child+1 < n && a[child+1] < a[child])
		{
			child++;
		}
		if(a[child] < a[parent])
		{
			swap(&a[child],&a[parent]);
		}
		else
		{
			break;
		}
		parent = child;
		child  = 2*parent + 1;
	}
}
//建小堆
void BuildMinHeap(HPDataType*a,int n)
{
	for(int i = (n-1-1)/2;i >=0;i--)
	{
		adjustdown(a,n,i);
	}
}
//堆排序，降序
void HeapSort(HPDataType*a,int n)
{
	//1.构建堆O(N)
	BuildMinHeap(a,n);
	//2.每次取出最小值，放到数组最后NlogN
	int end = n - 1;
	while(end > 0)
	{
		swap(&a[0],&a[end]);//取出最小值，放到数组最后
		
		//继续去次小的数
		adjustdown(a,end,0);
		end--;
	}
	
}
void HeapInit(Heap*php,HPDataType*a,int n)
{
	php->data = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(php->data,a,sizeof(HPDataType)*n);
	php->capacity = n;
	php->size = n;
}
void AdjustUp(HPDataType* a,int n,int pos)
{
	int child = pos,parent = (child-1)/2;
	while(child > 0)
	{
		if(a[child] < a[parent])
		{
			swap(&a[child],&a[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child-1)/2;
	}
}
void HeapPush(Heap*php,HPDataType x)//Push到数组尾端进去后，需要调整，保持堆的性质
{
	assert(php);
	if(php->capacity == php->size)
	{
		php->data = (HPDataType*)realloc(php->data,sizeof(HPDataType)*2*php->capacity);
	}
	php->data[php->size++] = x;
	//放进去后向上调整，保持堆的性质
	AdjustUp(php->data,php->size,php->size - 1);
}
void HeapPop(Heap*php)//从数组头上Pop
{
	assert(php);
	assert(php->size > 0);
	
	swap(&php->data[0],&php->data[php->size -1]);
	php->size--;
	adjustdown(php->data,php->size,0);
}
HPDataType HeapTop(Heap*php)
{
	return php->data[0];
}
void HeapDestroy(Heap*php)
{
	free(php->data);
	php->data = NULL;
	free(php);
}

