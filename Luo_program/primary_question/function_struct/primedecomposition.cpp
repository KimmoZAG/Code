# include<iostream>
# include<cmath>

using namespace std;

long isprime(long k)
{
    for(long i = 2;i < sqrt(k+1);i++)
    {
        if(k % i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    long a, i, j;
    scanf("%ld", &a);
    for(i = 2;i < sqrt(a+1);i++)
    {
        if(isprime(i) && a % i == 0)
        {
            j = a / i;
            if(isprime(j)) 
            {
                printf("%ld\n", j);
                break;
            }
        }
    }
    system("pause");
    return 0;
}