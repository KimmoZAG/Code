# include<iostream>
# include<string>
# include<windows.h>

using namespace std;

# define N 10000

typedef struct improve_grades{
    string name;
    int a1;
    int a2;
}ig[N];

int main(void)
{
    ig a;
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i].name >> a[i].a1 >> a[i].a2;
    }
    for(int i = 0;i < n;i++)
    { 
        a[i].a2 = a[i].a2 * 6 / 5;
        a[i].a1 = a[i].a1 + 1;
        if(a[i].a2 > 600)
        {
            cout << a[i].name + " " << a[i].a1 << " 600" << endl;
        }
        else
        {
            cout << a[i].name + " " << a[i].a1 << " " << a[i].a2 << endl;
        }
    }
    system("pause");
    return 0;
}