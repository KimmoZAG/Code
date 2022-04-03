# include<iostream>
# include<cmath>
# include<vector>

int main(void)
{
    int prime_num[10000] = {0};
    int n = 1;
    prime_num[0] = 2;
    for(int i = 3;i <= 10000;i++)
    {
        int flag = 0;
        for(int k = 2;k < sqrt(i) + 1;k++)
        {
            if (0 == i % k) flag = 1;
        }
        if(flag == 0) prime_num[n++] = i;
    }
    int top;
    scanf("%d", &top);
    for(int k = 4;k <= top;k += 2)
    {   
        int one, another, flag = 0;
        for(int w = 0;prime_num[w] != 0;w++)
        {
            one = prime_num[w];
            another = k - one;
            for(int p = w;prime_num[p] != 0;p++)
            {
                if(another == prime_num[p])
                {
                    printf("%d=%d+%d\n", k, one, another);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }
    }
    system("pause");
    return 0;
}