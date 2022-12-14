#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


typedef BTNode* QueueDataType;
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

// void TestQueue()
// {
//     Queue q;
//     QueueInit(&q);
//     QueuePush(&q,1);
//     QueuePush(&q,2);
//     QueuePush(&q,3);
//     QueuePush(&q,4);
//     QueuePop(&q);
//     QueuePop(&q);
//     QueuePop(&q);
//     // QueuePop(&q);
//     // QueuePop(&q);
//     // QueuePop(&q);
//     printf("%d ",QueueFront(&q));
//     printf("%d ",QueueBuck(&q));
//     QueueDestroy(&q);
// }

// int main()
// {
//     TestQueue();
//     return 0;
// }
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
    if(pq->head == NULL)//?????????????????????????????????tail???????????????????????????
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
/**************************************************************************/
/* *******************************??????????????????************************* */
#include <stdio.h>
#include <stdlib.h>

// typedef char BTDataType;
// typedef struct BinaryTreeNode
// {
// 	BTDataType data;
// 	struct BinaryTreeNode* left;
// 	struct BinaryTreeNode* right;
// }BTNode;

//????????????
void PrevOrder(BTNode* root)
{
	if(root == NULL) return;
	
	printf("%c ",root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
	
}
//????????????
void InOrder(BTNode* root)
{
	if(root == NULL) return;
	
	InOrder(root->left);
	printf("%c ",root->data);
	InOrder(root->right);
}
//????????????
void PostOrder(BTNode* root)
{
	if(root == NULL) return;
	
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ",root->data);
}
//???????????????
BTNode* CreatNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
//????????????
int TreeLeafSize(BTNode* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//????????????
int TreeSize(BTNode* root)
{
    if(root == NULL)
        return 0;
    else
        return 1 + TreeSize(root->left) + TreeSize(root->right);
}
//????????????????????????root?????????Pop???????????????????????????????????????
//[1]  [2,3]  [3,4,5] [4,5]  [5]  [NULL]
void BinaryTreeLevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);

    if(root == NULL) return;
    QueuePush(&q,root);

    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);

        printf("%c ",front->data);
        if(front->left != NULL)
            QueuePush(&q,front->left);
        if(front->right != NULL)
            QueuePush(&q,front->right);
    }
    QueueDestroy(&q);
}
//???k???????????????????????????k-1??? ???????????????+????????????
int BinaryTreeKSize(BTNode* root,int k)
{
    if(root == 0)
        return 0;
    if(k == 1)
        return 1;

    return BinaryTreeKSize(root->left,k-1)
    + BinaryTreeKSize(root->right,k-1); 
}
//????????????x?????????
BTNode* BinaryTreeFind(BTNode* root,BTDataType x)
{
    if(root == NULL) return NULL;

    if(root->data == x) return root;

    BTNode* ret = BinaryTreeFind(root->left, x);
    if(ret != NULL)  return ret;
        
    ret = BinaryTreeFind(root->right, x);
    if(ret != NULL)  return ret;

    return NULL;
}
//??????????????????????????????:?????????????????????????????????NULL????????????
int BinaryTreeComlete(BTNode* root)
{
    Queue q;
    QueueInit(&q);

    if(root == NULL) return 1;
    QueuePush(&q,root);

    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);

        if(front == NULL)//??????????????????????????????????????????????????????
        {
            break;
        }

        QueuePush(&q,front->left);
        QueuePush(&q,front->right);
    }
    //??????????????????while????????????????????????NULL???
    //?????????????????????????????????????????????????????????
    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        if(front)
        {
            QueueDestroy(&q);
            return 0;
        }
    }
    QueueDestroy(&q);
    return 1;
}

int main()
{
	BTNode* A = CreatNode('A');
	BTNode* B = CreatNode('B');
	BTNode* C = CreatNode('C');
	BTNode* D = CreatNode('D');
	BTNode* E = CreatNode('E');
    BTNode* F = CreatNode('F');
	A->left  = B;
	A->right = C;
	B->left  = D;
	B->right = E;
    D->left  = F;
	
    // BinaryTreeLevelOrder(A);
    // printf("\n");
    // PrevOrder(A);
    // printf("\n");
    // InOrder(A);
    // printf("\n");
    // PostOrder(A);
    // printf("\n");
    // BTNode*ret = BinaryTreeFind(A,'B');
    // // printf("%c",ret->data);
    // int a = BinaryTreeComlete(A);
    // printf("%d",a);
    int a = TreeSize(A);
    printf("%d",a);
	return 0; 	
}
