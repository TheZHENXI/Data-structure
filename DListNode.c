#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	struct ListNode* prev;
}LNode;

void LNInsert(LNode* pos,int x);
void LNPrint(LNode* phead);
LNode* BuyListNode(int x);
void  LNPushFront(LNode* phead,int x);
void  LNPopFront(LNode* phead);
void LNPushBuck(LNode* phead,int x);
void LNPopBuck(LNode* phead);
LNode* InitList();
LNode* ListFind(LNode* phead,int x);
/****************************************************************/
//pos位置前Insert
void LNInsert(LNode* pos,int x)
{
    assert(pos);
	LNode* posPrev = pos->prev;
	LNode* newnode = BuyListNode(x);
	//phead  node   newnode   node  node
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
//pos位置delete
void LNDelete(LNode* pos)
{
    assert(pos);
    assert(pos-> next != pos);
    //phead  node  
    LNode* posPrev = pos->prev;
    LNode* posNext = pos->next;
    
    free(pos);
    posPrev->next = posNext;
    posNext->prev = posPrev;
}
//打印
void LNPrint(LNode* phead)
{
	LNode* cur = phead->next;
	while(cur != phead)
	{
		printf("%d ",cur->val);
		cur = cur->next;
	}
	printf("\n");
}
//创建新节点
LNode* BuyListNode(int x)
{
	LNode* newnode = (LNode*)malloc(sizeof(LNode));
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	return newnode;
}
//头插
void  LNPushFront(LNode* phead,int x)
{
	//phead   node   node  node
	assert(phead);
	
	LNode* after = phead->next;
	LNode* newnode = BuyListNode(x);
	
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = after;
	after->prev = newnode;
}
//头删
void  LNPopFront(LNode* phead)
{
	//phead   node   node  node
	assert(phead);	
	assert(phead->next != phead);//防止空链表
	
	LNode* after = phead->next;
	LNode* afterAfter = after->next;
	
	phead->next = afterAfter;
	afterAfter->prev = phead;
	free(after);
}
//尾插
void LNPushBuck(LNode* phead,int x)
{
	assert(phead);
	
	LNode* tail = phead->prev;
	LNode* newnode = BuyListNode(x);
	
	//phead          tail   newnode
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
//尾删
void LNPopBuck(LNode* phead)
{
	assert(phead != NULL);//防止使用者用错
	assert(phead->next != phead);//只有哨兵位的时候不在删
	//方法一：
	LNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	/*
	方法二：
	LNode* tail = phead->prev;
	LNode* tailPrev = tail->prev;
	free(tail);
	tailPrev->next = phead;
	phead->prev = tailPrev;
	*/
}
LNode* InitList()
{
    //哨兵位头结点
    LNode* phead = (LNode*)malloc(sizeof(LNode));
    phead->next = phead;
    phead->prev = phead;

    return phead;
}
LNode* ListFind(LNode* phead,int x)
{
    LNode* cur = phead->next;
    while(cur != phead)
    {
        if(cur->val == x)
            return cur;
        cur = cur->next;
    }
    return cur;
}
/****************************************************************/
void testLNode1()
{
    LNode* plist = NULL;
    plist = InitList();
	LNPushBuck(plist,1);
    LNPushBuck(plist,2);
    LNPushBuck(plist,3);
    LNPushBuck(plist,4);
    LNPushBuck(plist,5);
    LNPrint(plist);
    LNPopFront(plist);
    LNPopFront(plist);
    LNPrint(plist);
    LNPushBuck(plist,6);
    LNPushBuck(plist,7);
    LNPushBuck(plist,8);
    LNPrint(plist);
    LNInsert(plist,9);//尾插
    LNInsert(plist->next,9);//头插
    LNode* pos = ListFind(plist,9);
    LNPrint(plist);
    if(pos)
        LNDelete(pos);
    LNPrint(plist);
}

int main()
{
	testLNode1();
	return 0;
}
