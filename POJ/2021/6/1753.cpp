# include<iostream>

using namespace std;
char arr[4][4];
int num = 100;
int flag = 0;
bool is_define();
void deal_arr(int a,int b);
void ch_deal(int i,int j);
bool is_define()
{
    char a = arr[0][0];
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(a != arr[i][j]) return false;
        }
    }
    return true;
}

void ch_deal(int i,int j)
{
    if(arr[i][j] == 'b')
    {
        arr[i][j] = 'w';
        if(i - 1 >= 0)  arr[i - 1][j] == 'w' ? arr[i - 1][j] = 'b' : arr[i - 1][j] = 'w';
        if(i + 1 <= 3)  arr[i + 1][j] == 'w' ? arr[i + 1][j] = 'b' : arr[i + 1][j] = 'w';
        if(j - 1 >= 0)  arr[i][j - 1] == 'w' ? arr[i][j - 1] = 'b' : arr[i][j - 1] = 'w';
        if(j + 1 <= 3)  arr[i][j + 1] == 'w' ? arr[i][j + 1] = 'b' : arr[i][j + 1] = 'w';
    }
    else
    {
        arr[i][j] = 'b';
        if(i - 1 >= 0)  arr[i - 1][j] == 'w' ? arr[i - 1][j] = 'b' : arr[i - 1][j] = 'w';
        if(i + 1 <= 3)  arr[i + 1][j] == 'w' ? arr[i + 1][j] = 'b' : arr[i + 1][j] = 'w';
        if(j - 1 >= 0)  arr[i][j - 1] == 'w' ? arr[i][j - 1] = 'b' : arr[i][j - 1] = 'w';
        if(j + 1 <= 3)  arr[i][j + 1] == 'w' ? arr[i][j + 1] = 'b' : arr[i][j + 1] = 'w';
    }
}

void deal_arr(int a,int b,int n)
{
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(i < a || (i == a && j <= b)) continue;
            ch_deal(i, j);
            if(is_define() && num > n) 
            {
                num = n;
                flag = 1;
            }
            deal_arr(i, j, n + 1);
            ch_deal(i, j);
        }
    }
}

int main(void)
{

    for(int i= 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            cin >> arr[i][j];
        }
    }
    if(is_define())
    {
        flag = 1;
        num = 0;
    }
    else    deal_arr(-1,-1,1);
    if(flag) cout << num << endl;
    else    cout << "Impossible" << endl;
    system("pause");
}