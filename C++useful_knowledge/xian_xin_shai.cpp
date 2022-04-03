# include<iostream>
 
# define N 100000000

int prime[N] = {0};
int allnum[N] = {0};

void isprime(){
    prime[0] = 0;
    for(int i = 2;i <= N;i++){
        if(!allnum[i]) prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0] && prime[j] * i <= N;j++)
        {
                allnum[prime[j] * i] = 1;
                if(i % prime[j] == 0) break;
        }
    }
}
//理解算法原理，不能记住代码含义。。。
//几个重要的地方1.j <= prime[0]         2.
int main(void)
{   
    allnum[0] = allnum[1] = 1;
    isprime();
    for(int i = 0;i < N;i++)
    {
        if(allnum[i] != 1)
        printf("%d\n", i);
    }
    system("pause");
    return 0;
}
