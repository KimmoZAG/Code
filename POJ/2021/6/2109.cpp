# include<iostream>
# include<cmath>

using namespace std;

int main(void)
{
    double a, b, c;
    while(scanf("%lf %lf", &a, &b) != EOF)
    {
        printf("%.0lf\n", pow(b, 1.0 / a));
    }
    return 0;
}