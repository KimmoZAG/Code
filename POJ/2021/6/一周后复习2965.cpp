# include<iostream>

using namespace std;
char an[4][4];
int n = 100;
int step[100][200] = {0};
int ann[100], bnn[100];
int nm[100], jk[100];

bool unlocked();
void meiju(int a,int b, int times);
void chang(int i,int j);


bool unlocked()
{
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(an[i][j] != '-')  return false;
        }
    } 
    return true;
}

void chang(int i,int j)
{
    an[i][j] == '+' ? an[i][j] = '-' : an[i][j] = '+';
    if(i - 1 >= 0) an[i - 1][j] == '+' ? an[i - 1][j] = '-' : an[i - 1][j] = '+';
    if(i - 2 >= 0) an[i - 2][j] == '+' ? an[i - 2][j] = '-' : an[i - 2][j] = '+';
    if(i - 3 >= 0) an[i - 3][j] == '+' ? an[i - 3][j] = '-' : an[i - 3][j] = '+';
    if(i + 1 < 4) an[i + 1][j] == '+' ? an[i + 1][j] = '-' : an[i + 1][j] = '+';
    if(i + 2 < 4) an[i + 2][j] == '+' ? an[i + 2][j] = '-' : an[i + 2][j] = '+';
    if(i + 3 < 4) an[i + 3][j] == '+' ? an[i + 3][j] = '-' : an[i + 3][j] = '+';
    if(j - 1 >= 0) an[i][j - 1] == '+' ? an[i][j - 1] = '-' : an[i][j - 1] = '+';
    if(j - 2 >= 0) an[i][j - 2] == '+' ? an[i][j - 2] = '-' : an[i][j - 2] = '+';
    if(j - 3 >= 0) an[i][j - 3] == '+' ? an[i][j - 3] = '-' : an[i][j - 3] = '+';
    if(j + 1 < 4) an[i][j + 1] == '+' ? an[i][j + 1] = '-' : an[i][j + 1] = '+';
    if(j + 2 < 4) an[i][j + 2] == '+' ? an[i][j + 2] = '-' : an[i][j + 2] = '+';
    if(j + 3 < 4) an[i][j + 3] == '+' ? an[i][j + 3] = '-' : an[i][j + 3] = '+';
}

void meiju(int a,int b, int times)
{
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(i < a || (i == a && j <= b))   continue;
            chang(i, j);
            ann[times] = i + 1;
            bnn[times] = j + 1;
            if(unlocked() && times < n)
            {
                n = times;
                //这种存储方式，正好符合递归的基本规律，根据题意，仅有唯一解，
                //故可在满足条件之后直接返回，也加快了程序速度
                for(int k = 1;k <= times;k++)
                {
                    nm[k] = ann[k];
                    jk[k] = bnn[k];
                }
                return;
            }
            meiju(i, j, times + 1);
            chang(i, j);
        }
    }
}

int main(void)
{
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            cin >> an[i][j];
        }
    }    
    meiju(-1, -1, 1);
    cout << n << endl;
    for(int i = 1;i <= n;i++)
    {
        cout << nm[i] << " " << jk[i] << endl;
    }
    return 0;
}