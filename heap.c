#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLdata;

typedef struct SeqList
{
    SLdata* data;
    int size;
    int capacity;

}SL;

void SeqListInit(SL*);
void SeqListPushBuck(SL*, int);
void SeqListPopBuck(SL*);
void SeqListPushFront(SL*, int);
void SeqListPopFront(SL*);
void CheckCapacity(SL*);
void SeqListPrint(SL*);

int SeqListFind(SL*,SLdata x);
void SeqListInsert(SL*,int pos,SLdata x);
void SeqListErase(SL*,int pos);
/*--------------------------------------------*/
void menu()
{
    printf("*************************************\n");
    printf("***********1.尾插       2.尾删********\n");
    printf("***********3.头插       4.头删********\n");
    printf("***********5.Show      6.Sort********\n");
    printf("***********0.Exit********************\n");
}

void testSL1(void)
{   
    // int input = 0;
    //创建顺序表
    SL list;
    SeqListInit(&list);

    SeqListPushBuck(&list,1);
    SeqListPushBuck(&list,2);
    SeqListPushFront(&list,3);
    SeqListPrint(&list);
    int ret = SeqListFind(&list,1);
    printf("%d\n",ret);


    // do
    // {
    //     mean();
    //     printf("请选择>");
    //     scanf("%d",&input);
    //     int num = 0; 
    //     switch (input)
    //     {
    //         case 1:
    //             SeqListPushBuck();
    //             break;
    //         case 2:
    //             Delete(&list);
    //             break;
    //         case 3:
    //             Search(&list);
    //             break;
    //         case 4:
    //             Modify(&list);
    //             break;
    //         case 5:
    //             ShowContact(&list);
    //             break;
    //         case 6:
    //             Sort(&list);
    //             break;            
    //         default:
    //             break;
    //     }
    //     /* code */
    // } while (input);
    // destroy(&list);
}
void testSL2(void)
{   
    //创建顺序表
    SL list;
    SeqListInit(&list);
    SeqListPushBuck(&list,1);
    SeqListPushBuck(&list,2);
    SeqListPushBuck(&list,3);
    SeqListPushBuck(&list,4);
    SeqListPrint(&list);
    SeqListInsert(&list,1,9);
    SeqListPrint(&list);

}
void testSL3(void)
{   
    //创建顺序表
    SL list;
    SeqListInit(&list);
    SeqListInsert(&list,0,1);
    SeqListInsert(&list,1,2);
    SeqListInsert(&list,2,3);
    SeqListInsert(&list,3,4);
    SeqListInsert(&list,0,5);
    SeqListErase(&list,2);
    SeqListErase(&list,0);
    SeqListErase(&list,0);
    SeqListErase(&list,0);

    SeqListPrint(&list);

}

int main()
{
    // testSL1();
    // testSL2();
    testSL3();

    return 0;
}
/*-------------------------------------------------------*/
void SeqListInit(SL* cp)
{
    cp->size = 0;
    cp->capacity = 0;
    cp->data = NULL;

}
void CheckCapacity(SL* cp)
{
    if(cp->capacity == cp->size)
    {
        int newcapacity = cp->capacity == 0 ? 4:2*cp->capacity;
        SLdata* tmp = (SLdata*)realloc(cp->data,newcapacity*sizeof(SLdata));
        if(tmp != NULL)
        {
            cp->data = tmp;
            cp->capacity = newcapacity;
        }
        else
        {
            printf("realloc fail\n");
            exit(-1);
        }
    }

}
void SeqListPushBuck(SL* cp, int num)
{
    CheckCapacity(cp);
    cp->data[cp->size] = num;
    cp->size++;
}
void SeqListPrint(SL* cp)
{
    for(int i = 0;i < cp->size;i++)
    {
        printf("%d ",cp->data[i]);
    }
    printf("\n");
}
void SeqListPopBuck(SL* cp)
{
    if(cp->size > 0)
        cp->size--;
}
void SeqListPushFront(SL* cp, int num)
{
    CheckCapacity(cp);
    int cnt = cp->size;
    while (cnt)
    {
        cp->data[cnt] = cp->data[cnt-1];
        cnt--;
        /* code */
    }
    cp->data[0] = num;
    cp->size++;
}
void SeqListPopFront(SL* cp)
{
    int begin = 1;
    while(begin < cp->size)
    {
        cp->data[begin-1] = cp->data[begin];
        begin++;
    }
    cp->size--;
}
int SeqListFind(SL* cp,SLdata x)
{
    for(int i = 0;i < cp->size;i++)
    {
        if(cp->data[i] == x)
        {
            return i;
        }
    }
    return -1;
}
//任意位置插入，可以替代头插和尾插
void SeqListInsert(SL* cp,int pos,SLdata x)
{
    assert(pos >=0 && pos<= cp->size);

    CheckCapacity(cp);
    int end = cp->size-1;
    while(end >= pos)
    {
        cp->data[end+1] = cp->data[end];
        end--;
    }
    cp->data[pos] = x;
    cp->size++;
}
//删除任意位置的元素
void SeqListErase(SL* cp,int pos)
{   
    assert(pos >=0 && pos< cp->size);
    int begin = pos+1;
    while(begin < cp->size)
    {
        cp->data[begin-1] = cp->data[begin];
        begin++;
    }
    cp->size--;
}