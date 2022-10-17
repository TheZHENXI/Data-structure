#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef int StackDataType;
typedef struct stack
{
    StackDataType* data;
    int top;
    int capacity;
}ST;
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps,StackDataType x);
void StackPop(ST* ps);
StackDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
/***********************************************************/

void TestStack()
{
    ST ps;
    StackInit(&ps);
    StackPush(&ps,1);
    StackPush(&ps,2);
    StackPush(&ps,3);
    StackPush(&ps,4);
    StackPush(&ps,5);
    StackPop(&ps);
    while(!StackEmpty(&ps))
    {
        printf("%d ",StackTop(&ps));
        StackPop(&ps);
    }
    StackDestroy(&ps);
}

int main()
{
    TestStack();
    return 0;
}
/***********************************************************/
void StackInit(ST* ps)
{
    assert(ps);
    ps->data = NULL;
    ps->capacity = 0;
    ps->top = 0;
}
void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = 0;
    ps->top = 0;
}
void StackPush(ST* ps,StackDataType x)
{
    assert(ps);

    if(ps->capacity == ps->top)
    {
        int newcapacity =  ps->capacity == 0? 4:ps->capacity*2;
        int* tmp = (int*)realloc(ps->data,sizeof(int)*newcapacity);
        if(tmp == NULL)
        {
            printf("relloc fail");
            exit(-1);
        }
        else
        {
            ps->data = tmp;
            ps->capacity = newcapacity;
        }
    }
    ps->data[ps->top] = x;
    ps->top++;
}
void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    ps->top--;
}
StackDataType StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));

    return ps->data[ps->top-1];
}
int StackSize(ST* ps)
{
    assert(ps);

    return ps->top;
}
bool StackEmpty(ST* ps)
{
    return ps->top == 0;
}
