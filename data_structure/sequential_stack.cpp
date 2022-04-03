# include<stdio.h>
# include<stdlib.h>
//����˳��ջ�Ľṹ��
typedef struct sequential_stack
{
    int *top;
    int *bottom;
    int length;
}stack;
//��ʼ��ջ
int InitStack(stack* k, int len)
{
    (*k).bottom = (int *)malloc(len * sizeof(int));
    if((*k).bottom == NULL)
    {
        printf("��ʼ��ʧ�ܣ�\n");
        exit(0);
    }
    (*k).top = (*k).bottom;
    (*k).length = len;
    return 0;
}
//��ջ�в���Ԫ��
int Push(stack *k, int x)
{
    if((*k).top - (*k).bottom == (*k).length)
    {
        printf("ջ�������޷����롣");
        exit(0);
    }
    *(*k).top = x;
    (*k).top++;
    return 0;
}
//���ջ���ӵ͵���
int Displaystack(stack k)
{
    if(k.bottom == k.top)
    {
        printf("��ջ");
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
//����Ԫ�أ�Ԫ��Ϊ���һ������ջ��Ԫ��
int Pop(stack *k)
{
    if((*k).bottom == (*k).top)
    {
        printf("��ջ���޷�����Ԫ�ء�");
    }
    (*k).top--;
    printf("����Ԫ��Ϊ��%d", *(*k).top);
    return 0;
}

int main(void)
{
    stack k;
    int length, innum;
    printf("Ԥ��ջ�ĳ���Ϊ��");
    scanf("%d", &length);
    InitStack(&k, length);
    while(length-- != 0)
    {
        printf("���������������֣�");
        scanf("%d", &innum);
        Push(&k, innum);
    }
    Displaystack(k);
    printf("\n");
    Pop(&k);
    system("pause");
    return 0;
}