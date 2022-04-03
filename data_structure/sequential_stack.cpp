# include<stdio.h>
# include<stdlib.h>
//定义顺序栈的结构体
typedef struct sequential_stack
{
    int *top;
    int *bottom;
    int length;
}stack;
//初始化栈
int InitStack(stack* k, int len)
{
    (*k).bottom = (int *)malloc(len * sizeof(int));
    if((*k).bottom == NULL)
    {
        printf("初始化失败！\n");
        exit(0);
    }
    (*k).top = (*k).bottom;
    (*k).length = len;
    return 0;
}
//向栈中插入元素
int Push(stack *k, int x)
{
    if((*k).top - (*k).bottom == (*k).length)
    {
        printf("栈已满，无法插入。");
        exit(0);
    }
    *(*k).top = x;
    (*k).top++;
    return 0;
}
//输出栈，从低到高
int Displaystack(stack k)
{
    if(k.bottom == k.top)
    {
        printf("空栈");
        exit(0);
    }
    int * bot;
    bot = k.bottom;
    while(bot != k.top)
    {
        printf("%d ",*bot);
        bot++;
    }
    return 0;
}
//弹出元素，元素为最后一个存入栈的元素
int Pop(stack *k)
{
    if((*k).bottom == (*k).top)
    {
        printf("空栈，无法弹出元素。");
    }
    (*k).top--;
    printf("弹出元素为：%d", *(*k).top);
    return 0;
}

int main(void)
{
    stack k;
    int length, innum;
    printf("预计栈的长度为：");
    scanf("%d", &length);
    InitStack(&k, length);
    while(length-- != 0)
    {
        printf("输入你想存入的数字：");
        scanf("%d", &innum);
        Push(&k, innum);
    }
    Displaystack(k);
    printf("\n");
    Pop(&k);
    system("pause");
    return 0;
}