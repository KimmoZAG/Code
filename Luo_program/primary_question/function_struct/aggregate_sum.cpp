# include<iostream>
# include<vector>
# include<cmath>
# include<windows.h>

using namespace std;

long count_num(vector <int> a)
{
    long sum = 0;
    for(int i : a)
    {
        sum += i;
    }
    sum = sum * pow(2,a.size() - 1);
    return sum;
}

int main(void)
{
    vector <int> a;
    int innum, sum = 0;
    while (scanf("%d", &innum) == 1)
    {
        a.push_back(innum);
    }
    printf("%ld", count_num(a));
    system("pause");
    return 0;
}