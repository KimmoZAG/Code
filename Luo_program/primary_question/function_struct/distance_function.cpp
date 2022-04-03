# include<iostream>
# include<cmath>

typedef struct abc{
    double a[2];
    double b[2];
    double c[2];
}triange;
//typedef 给结构体改名，同时可以直接添加指针型的名

double algorithm(double a[],double b[],double c[])
{
    double ai, bi, ci;
    ai = sqrt(pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2));
    bi = sqrt(pow((c[0] - b[0]), 2) + pow((c[1] - b[1]), 2));
    ci = sqrt(pow((c[0] - a[0]), 2) + pow((c[1] - a[1]), 2));
    return ai + bi + ci;
}

int main(void)
{
    triange tri;
    scanf("%lf %lf %lf %lf %lf %lf",&tri.a[0],&tri.a[1],&tri.b[0],&tri.b[1],&tri.c[0],&tri.c[1]);
    printf("%.2f", algorithm(tri.a,tri.b,tri.c));
    return 0;
}