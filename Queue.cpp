#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef int QueueDataType;
typedef struct QueueNode
{
    struct QueueNode* next;
    QueueDataType data;
};
typedef struct Queue
{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;
void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);
void QueuePush(Queue* ps,QueueDataType x);
void QueuePop(Queue* ps);
QueueDataType StackTop(Queue* ps);
int QueueSize(Queue* ps);
bool QueueEmpty(Queue* ps);
/***********************************************************/

void TestQueue()
{
    ;
}

int main()
{
    TestQueue();
    return 0;
}
/***********************************************************/void StackInit(ST* ps);
void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);
void QueuePush(Queue* ps,QueueDataType x);
void QueuePop(Queue* ps);
QueueDataType StackTop(Queue* ps);
int QueueSize(Queue* ps);
bool QueueEmpty(Queue* ps);
