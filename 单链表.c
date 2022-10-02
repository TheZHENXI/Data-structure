/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-02 09:50:11
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-02 14:04:14
 * @FilePath: /CCODE/数据结构/单链表.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct SListNode
{
    int data;
    struct SListNode* next;
}SLTNode;

SLTNode* BuyListNode(int);
void SListPushBuck(SLTNode**,int);
void SListPushFront(SLTNode**,int);
void SListPopFront(SLTNode**);
void SListPopBuck(SLTNode**);
void SListPrint(SLTNode**);
SLTNode* SListFind(SLTNode*,int);
void SListInsert(SLTNode**,int);
void SListDelete(SLTNode**,int);

/*----------------------------------*/
void SLTnodetest1()
{
    SLTNode* plist = NULL;
    SListPushBuck(&plist,1);
    SListPushBuck(&plist,2);
    SListPushBuck(&plist,3);
    SListPushBuck(&plist,4);
    SListPushFront(&plist,5);
    SListPushFront(&plist,6);
    SListPopFront(&plist);
    SListPopBuck(&plist);
    SListPopBuck(&plist);
    SListPrint(&plist);

}
void SLTnodetest2()
{
    SLTNode* plist = NULL;
    SListPushBuck(&plist,1);
    SListPushBuck(&plist,2);
    SListPushBuck(&plist,3);
    SListPushBuck(&plist,4);
    SListPushFront(&plist,2);
    SListPushFront(&plist,6);
    SLTNode* pos = SListFind(plist,2);
    while(pos)
    {
        printf("节点的值为:%p %d\n",pos,pos->data);
        pos = SListFind(pos->next,2);
    }
    SListPrint(&plist);
    
}

int main()
{
    // SLTnodetest1();
    SLTnodetest2();
    return 0;
}
/*----------------------------------*/
//创建新节点
SLTNode* BuyListNode(int x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    newnode->data = x;
    newnode->next = NULL;
    
    return newnode;
}
//尾插
void SListPushBuck(SLTNode** pphead,int x)
{
    if(*pphead == NULL)
    {
        //创建一个节点
        *pphead = BuyListNode(x);
    }
    else
    {
        //找到尾节点
        SLTNode* tail = *pphead;
        while(tail->next)
        {
            tail = tail->next;
        }
        tail->next = BuyListNode(x);
    }
}
//头插
void SListPushFront(SLTNode** pphead,int x)
{
    SLTNode* tmp = BuyListNode(x);
    tmp->next = *pphead;
    *pphead = tmp;
}
//打印
void SListPrint(SLTNode** pphead)
{
    SLTNode* cur = *pphead;
    while(cur)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}
//头删
void SListPopFront(SLTNode** pphead)
{
    //1.空链表调用
    assert(*pphead != NULL);
    //2.一个及多个节点
    SLTNode* next = (*pphead)->next;
    free(*pphead);
    *pphead = next;
}
//尾删
void SListPopBuck(SLTNode** pphead)
{
    //1.空链表
    assert(*pphead != NULL);
    //2.一个节点
    if((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL; 
    }
    //3.多个节点
    else
    {
        SLTNode* curPre = NULL;
        SLTNode* cur = *pphead;
        while(cur->next)
        {
            curPre = cur;
            cur = cur->next;
        }
        free(cur);
        cur = NULL;
        curPre->next = NULL;

    }
}
//查找
SLTNode* SListFind(SLTNode* phead,int x)
{
    SLTNode* cur = phead;
    while (cur)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
//指定位置插入(指定位置之后)
void SListInsert(SLTNode**,int);
//指定位置删除
void SListDelete(SLTNode**,int);
