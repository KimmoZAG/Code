# include<iostream>
# include<map>
# include<string>

using namespace std;

map <int,int>   ditu;
map <int,char>   sign;
int n, m, i;
void creat(int n,int m);
void move(int n,int m,int i);

void creat(int n,int m)
{
    int k = n * m, line = n;
    while(k != 0)
    {
        ditu[k--] = -1;
    }
    k = 1;
    while(line-- != 0)
    {
        string inst;
        cin >> inst;
        for(int q = 0;inst[q] != '\0';q++)
        {
            sign[k++] = inst[q];
        }
    }
}

void move(int n,int m,int i)
{
    int signh = 1,signl = i, times = 0;
    ditu[i] = times++;
    while(1)
    {
        //east东 west西 north北 south南
        switch(sign[(signh-1) * m + signl])
        {
            case 'E':
                signl++;
                break;
            case 'W':
                signl--;
                break;
            case 'N':
                signh--;
                break;
            case 'S':
                signh++;
                break;
        }
        if(signh > n || signl > m || signh < 1 || signl < 1)    
        {
            cout << times <<" step(s) to exit" << endl;
            break;
        }
        else if(ditu[(signh-1) * m + signl] != -1)
        {
            cout << ditu[(signh-1) * m + signl] << " step(s) before a loop of " << times - ditu[(signh-1) * m + signl] << " step(s)" << endl;
            break;
        }
        else
        {
            ditu[(signh-1) * m + signl] = times++;
        }
    }
}

int main()
{
    while(cin >> n >> m >> i)
    {
        if(n == 0 && m == 0 && i == 0)  break;
        creat(n, m);//创建初始地图
        move(n, m, i);
    }
    return 0;
}