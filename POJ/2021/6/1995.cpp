# include<iostream>

using namespace std;

int power(int a,int b,int c)
{
    int final_mol = 1 % c;
    while(b)
    {
        if(b & 1) final_mol = 1ll * final_mol * a % c;
        a = 1ll * a * a % c;
        b >>= 1;
    }
    return final_mol;
}

int main(void)
{
    int n, out_num;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        out_num = 0;
        int a, b, c, all;
        scanf("%d", &c);
        scanf("%d", &all);
        for(int j = 0;j < all;j++)
        {
            scanf("%d %d", &a, &b);
            out_num += power(a, b, c);
        }
        printf("%d\n",out_num % c);
    }
    system("pause");
    return 0;
}