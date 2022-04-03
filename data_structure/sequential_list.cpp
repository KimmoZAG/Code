# include<stdio.h>
# include<windows.h>                

typedef struct sequential_list
{
    int a[100];
    int length;
}list;

int Initlist(list* p)
{
    (*p).length = 0;
    return 0;
}

int Insert(list* p, int place, int x)
{
    if(place > 100)
    {
        printf(" 超出最大长度！");
        exit(0);
    }
    for(int i = place;i < 99;i++)
    {
        (*p).a[i + 1] = (*p).a[i];
    }
    (*p).a[place] = x;
    (*p).length++;
    return 0;
}

int Delete(list* p, int place)
{
    for(int i = place;i < 99;i++)
    {
        (*p).a[i] = (*p).a[i + 1]; 
    }
    (*p).length--;
    return 0;
}

int main(void)
{           
    list p;
    int len, place;
    Initlist(&p);
    printf("请输入链表长度：");
    scanf("%d", &len);
    for(int i = 0;i < len;i++)   Insert(&p, i, i + 1);
    for(int i = 0;i < p.length;i++)    printf("%d ", p.a[i]);
    printf("\n");
    printf("你要删除的元素位置是：");
    scanf("%d", &place);
    Delete(&p, place);
    for(int i = 0;i < p.length;i++)    printf("%d ", p.a[i]);
    system("pause");
    return 0;
}