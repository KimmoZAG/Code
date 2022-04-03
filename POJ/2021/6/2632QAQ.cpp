# include<iostream>
# include<string.h>

using namespace std;
int sto[101][101];
int ch, ku, num, order, flag;
int p1[101],p2[101];
// N S W E, 
void initialization(int sto[101][101], int num);
void move(int sto[101][101], int order);
int gonext(int who, int step);
void initialization(int sto[101][101], int num)
{
    int k = 1;
    while(num--)
    {
        int i, j;
        char sta;
        scanf("%d %d %c", &i, &j, &sta);
        p1[k] = i;
        p2[k++] = j;
        switch(sta)
        {
            case 'E':
            {
                sto[i][j] = 0;
                break;
            }
            case 'W':
            {
                sto[i][j] = 180;
                break;
            }
            case 'S':
            {
                sto[i][j] = 270;
                break;
            }
            case 'N':
            {
                sto[i][j] = 90;
                break;
            }
        }
    }
}

void move(int sto[101][101], int order)
{   
    int i, j;
    flag = 2;
    while(order--)
    {
        char whe;
        scanf("%d %c %d", &i, &whe, &j);
        if(flag != 2)   continue;
        switch(whe)
        {
            case 'L':
            {
                sto[p1[i]][p2[i]] = (sto[p1[i]][p2[i]] - j * 90 + 25 * 360) % 360;
                break;
            }
            case 'R':
            {
                sto[p1[i]][p2[i]] = (sto[p1[i]][p2[i]] + j * 90) % 360; 
                break;
            }  
            case 'F':
            {
                flag = gonext(i, j);
            }
        }
    }
    if(flag == 1)
    {
        printf("Robot %d crashes into the wall\n", i);
        return;
    }
    if(flag == 0)
    {
        int m;
        for(m = 1;m <= num;m++) if(p1[0] == p1[m] && p2[0] == p2[m])    break;
        printf("Robot %d crashes into robot %d\n", i, m - 1);
        return;
    }    
    printf("OK\n");
}

int gonext(int who, int step)
{
    while(step--)
    {
        switch(sto[p1[who]][p2[who]])
        {
            case 0:
            {
                int i;
                i = p1[who];
                p1[who] = p1[who] + 1;
                sto[i][p2[who]] = -1;
                if(sto[p1[who]][p2[who]] != -1)
                {
                    p1[0] = p1[who], p2[0] = p2[who]; 
                    return 0;
                }
                if(p1[who] > ch)
                {
                    sto[p1[who]][p2[who]] = -1;
                    return 1;
                } 
                sto[p1[who]][p2[who]] = 0;
                break;
            }
            case 90:
            {
                int i;
                i = p2[who];
                p2[who] = p2[who] + 1;
                sto[p1[who]][i] = -1;
                if(sto[p1[who]][p2[who]] != -1)
                {
                    p1[0] = p1[who], p2[0] = p2[who]; 
                    return 0;
                }
                if(p2[who] > ku)
                {
                    sto[p1[who]][p2[who]] = -1;
                    return 1;
                }
                sto[p1[who]][p2[who]] = 90;
                break;
            }
            case 180:
            {
                int i;
                i = p1[who];
                p1[who] = p1[who] - 1;
                sto[i][p2[who]] = -1;
                if(sto[p1[who]][p2[who]] != -1)
                {
                    p1[0] = p1[who], p2[0] = p2[who]; 
                    return 0;
                }
                if(p1[who] < 0) 
                {
                    sto[p1[who]][p2[who]] = -1;
                    return 1;
                }
                sto[p1[who]][p2[who]] = 180;
                break;
            }
            case 270:
            {
                int i;
                i = p2[who];
                p2[who] = p2[who] - 1;
                sto[p1[who]][i] = -1;
                if(sto[p1[who]][p2[who]] != -1)
                {
                    p1[0] = p1[who], p2[0] = p2[who]; 
                    return 0;
                }
                if(p2[who] < 0)
                {
                    sto[p1[who]][p2[who]] = -1;
                    return 1;
                };
                sto[p1[who]][p2[who]] = 270;
            }
        }
    }
    return 2;
}

int main(void)
{
    memset(sto,-1,sizeof(sto));
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &ch, &ku);
        scanf("%d %d", &num, &order);
        initialization(sto, num);
        for(int i = 1;i <= ch;i++)
        {
            for(int j = 1;j <= ku;j++)
            {
                cout << sto[i][j] << ' ';
            }
            cout << endl;
        }
        move(sto, order);
        for(int i = 1;i <= ch;i++)
        {
            for(int j = 1;j <= ku;j++)
            {
                cout << sto[i][j] << ' ';
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
/*
#include "iostream"
#include "vector"
#include "string.h"
int test = 0;
using namespace std;
const char S[4] = {'N','W','S','E'};
int board[101][101] = {0};
struct Rob
{
    int index;
    int x;
    int y;
    char c;
};
char change(char c,char order,int repeat)
{
    int x = 0;
    switch(c)
    {
    case 'N':  x = 0;  break;
    case 'W':  x = 1;  break;
    case 'S':  x = 2;  break;
    case 'E':  x = 3;  break;
    }
    int ch;
    switch(order)
    {
    case 'L':  ch = 1;  break;
    case 'R':  ch = 3;  break;
    case 'F':  ch = 0;  break;
    }
    x = (x+ch*repeat)%4;
    return S[x];
};
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        memset(board,0,sizeof(board));
        int A,B,N,M;
        cin>>A>>B>>N>>M;
        test = 0;
        vector<Rob> robot;
        Rob R;
        int number = N;
        while(N--)
        {
            cin >> R.x>>R.y>>R.c;
            robot.push_back(R);
            board[R.x][R.y] = number - N;//标记该位置的机器人
        }
        int Index;
        Rob ans;
        while(M--)
        {
            int index,repeat;
           char order;
            cin >>index>>order>>repeat;
            if(test!=0)
            continue;
            Index = index;
            Rob &temprob = robot[index-1];
            board[temprob.x][temprob.y] = 0;//该位置清零
            if(order == 'F')
        {
            while(repeat--)//重复执行命令直到执行完重复步骤或者出现crashes
            {
                if(test!=0)
                continue;
                switch(temprob.c)
                {
                case 'N':  temprob.y += 1;  break;
                case 'W': temprob.x -= 1;  break;
                case 'S': temprob.y -= 1;  break;
                case 'E':  temprob.x += 1;  break;
                }
                if(temprob.x==0||temprob.x==A+1||temprob.y==0||temprob.y==B+1)//撞墙
                {
                  ans = temprob;
                  test = 1;
                  break;
                }
                else if(board[temprob.x][temprob.y]!=0)//撞到一个机器人
                {
                    ans = temprob;
                    test = 2;
                    break;
                }
            }
        }
        else //转换方向
            temprob.c = change(temprob.c,order,repeat);
            if(test==0)
             board[temprob.x][temprob.y] = index;//该位置此时被机器人占了
        }

            if(test==0)
            cout<<"OK"<<endl;
        else if (test==1)
                cout<<"Robot "<<Index<<" crashes into the wall"<<endl;
        else
                cout<<"Robot "<<Index<<" crashes into robot "<<board[ans.x][ans.y]<<endl; 
    }
    return 0;
}*/