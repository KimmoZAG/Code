# include<iostream>

typedef struct student_grades{
    int code;
    double a, b, final, all;
}st[1000];

int main(void)
{
    st st1;
    int n;
    double k;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d %lf %lf", &st1[i].code, &st1[i].a, &st1[i].b);
        st1[i].final = st1[i].a * 0.7 + st1[i].b * 0.3;
        st1[i].all = st1[i].a + st1[i].b;
    }
    for(int i = 0;i < n;i++)
    {
        k = st1[i].a * 0.7 + st1[i].b * 0.3;
        if(st1[i].a + st1[i].b > 140 && k >= 80)
        printf("Excellent\n");
        else
        printf("Not excellent\n");
    }
    system("pause");
    return 0;
}