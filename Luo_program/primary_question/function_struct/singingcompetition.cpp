# include<iostream>
# include<algorithm>

using namespace std;

typedef struct all_num{
    double grade[20] = {9999};
    double a = 0;
}an[100];

int main(void)
{
    an k;
    int n, m, i;
    double max = 0;
    scanf("%d %d", &n, &m);
    for(i = 0;i < n;i++)
    {
        for(int j = 0;j < m; j++)
        {
            scanf("%lf", &k[i].grade[j]);
        }
        sort(k[i].grade,k[i].grade + m);
        for(int w = 1;w < m - 1;w++)
        {
            k[i].a += k[i].grade[w]; 
        }
        k[i].a = k[i].a / (double(m) - 2.0);
        if(k[i].a > max) max = k[i].a;
    }
    printf("%.2f", max);
    system("pause");
}