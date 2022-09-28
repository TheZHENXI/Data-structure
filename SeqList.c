#include <stdio.h>
#include <stdlib.h>

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
    int input = 0;
    //创建顺序表
    SL list;
    SeqListInit(&list);

    SeqListPushBuck(&list,1);
    SeqListPushBuck(&list,2);

    SeqListPushFront(&list,9);
    SeqListPrint(&list);
    SeqListPopFront(&list);
    SeqListPrint(&list);

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

int main()
{
    testSL1();
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