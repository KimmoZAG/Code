# include<iostream>
# include<vector>
# include<windows.h>

using namespace std;

int main(void)
{
    vector <int> a;
    int innum[100];
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &innum[i]);
    }
    for(int i = 0;i < n;i++)
    {
        int flag = 0;
        if(innum[i] == 1) flag = 1;
        for(int k = 2;k < innum[i];k++)
        {
            if(0 == innum[i] % k)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            a.push_back(innum[i]);
        }
    }
    for(int i = 0;i < a.size() - 1;i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[a.size() - 1]);
    system("pause");
    return 0;
}