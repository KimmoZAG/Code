# include<iostream>

using namespace std;
int s, d;
void count();

void count()
{
    int profit;
    int aver;
    for(int a = 2;a <= 6;a += 2)
    {
        aver = s * (5 - a / 2) - a / 2 * d; 
        profit = s * (12 - a) - a * d;
        if(profit > 0 && aver < 0)
        { 
            printf("%d\n", profit);
            return;
        }
    }
    int a = 9;
    if(s - d * 4 < 0 && s * (12 - a) - a * d > 0)   
    {
        printf("%d\n", s * (12 - a) - a * d);
        return;
    }
    printf("Deficit\n");
}
int main()
{
    while(scanf("%d %d", &s, &d) != EOF)    count();
    system("pause");
    return 0;
}