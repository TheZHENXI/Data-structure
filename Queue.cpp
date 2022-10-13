#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef int QueueDataType;
typedef struct QueueNode
{
    struct QueueNode* next;
    QueueDataType data;
}QueueNode;
typedef struct Queue
{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;
void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);
void QueuePush(Queue* ps,QueueDataType x);
void QueuePop(Queue* ps);
QueueDataType QueueFront(Queue* pq);
QueueDataType QueueBuck(Queue* pq);
int QueueSize(Queue* ps);
bool QueueEmpty(Queue* ps);
/***********************************************************/

void TestQueue()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    QueuePush(&q,4);
    QueuePop(&q);
    QueuePop(&q);
    QueuePop(&q);
    // QueuePop(&q);
    // QueuePop(&q);
    // QueuePop(&q);
    printf("%d ",QueueFront(&q));
    printf("%d ",QueueBuck(&q));
    QueueDestroy(&q);
}

int main()
{
    TestQueue();
    return 0;
}
/***********************************************************/
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->head;
    while(cur)
    {
        QueueNode* tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    pq->head = NULL;
    pq->tail = NULL;
}
void QueuePush(Queue* pq,QueueDataType x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->next = NULL;
    newnode->data = x;
    if(pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    QueueNode* tmp = pq->head->next;
    free(pq->head);
    pq->head = tmp;
    if(pq->head == NULL)//防止整个队列已删完，但tail未置空，成为野指针
        pq->tail = NULL;
}
QueueDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->data;
}
QueueDataType QueueBuck(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->data;
}
int QueueSize(Queue* pq)
{
    int n = 0;
    QueueNode* cur = pq->head;
    while(cur)
    {
        n++;
        cur = cur->next;
    }
    return n;
}
bool QueueEmpty(Queue* pq)
{
    if(pq->head == NULL)
        return true;
    else
        return false;
}
