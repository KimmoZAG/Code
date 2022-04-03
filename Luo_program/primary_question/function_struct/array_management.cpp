# include<iostream>

using namespace std;

int main(void)
{
    int arr[1024][1024];
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < 1024;i++)
    {
        for(j = 0;j < 1024;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    system("pause");
}