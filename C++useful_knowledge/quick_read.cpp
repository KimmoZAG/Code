//这里对读数方法进行一次学习
/*
    一般，我们在C中习惯“ scanf 和 printf 输入和输出 ”;C++中习惯“ cin 和 cout 输入和输出 ”;
    但是实际上两者的速度在对大量数据进行读取时是不一样的
        有如下规律：speed---scanf >> cin;
                   speed---printf >> cout;//同时printf能够提供更简单操作的数据输出格式。
                   
*/
# include<iostream>

using namespace std;

inline int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x*f;
}

int main(void)
{
    int one;
    one = read();
    printf("%d\n", one);
    system("pause");
    return 0;
}