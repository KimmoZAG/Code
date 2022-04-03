//pre_knowledge
/*取模运算
            (a * b) % p == (a % p) * (b % p) % p;
            (a + b) % p == (a % p + b % p) % p;
            a ^ b % p == ((a % p) ^ b) % p;
            快速幂以此为基础展开
*/
/*数学拆解
            我们承认，任何一个数都可以拆分为一个有关2的多项式
            b = cn * 2 ^ n + ..... + c0 * 2 ^ 0;
            其中一共有n+1项;
*/
//算法实现
# include<iostream>

using namespace std;

int power(int a,int b,int c)
{
    int final_num = 1 % c;//如果c为1直接为0
    while(b)
    {
        if(b & 1) final_num = 1ll * final_num * a % c;
        a = 1ll * a * a % c;//这里的a属于未熟的阶段,需要在上一步处理——mol c
        b >>= 1;
    }
    return final_num;
}

int main(void)
{
    int a, b, c;
    int k = power(a, b, c);
    printf("%d", k);
    return 0;
}