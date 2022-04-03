# include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=100000001;
int P[N],a,b,ans,sum;
bool Isp[N];
void Euler(int x){
    for(int i=2;i<=x;i++)
    {
        if(Isp[i])  P[++P[0]]=i;
        for(int j=1;i*P[j]<=x && j<=P[0];j++){
            Isp[i*P[j]]=false;
            if(i%P[j]==0) break;
        }
    }
}
bool hw(int x)
{
    int x2=x,y=0;
    while (x2!=0)
    {
        y=y*10+x2%10;
        x2/=10;
    } 
    if (x==y) return true;
    else return false;
}
int main()
{
    memset(Isp,true,sizeof(Isp));Isp[1]=0;
    scanf("%d %d",&a,&b);
    Euler(b);
    for(int i=a;i<=b;i++)
        if(hw(i) && Isp[i]){
            printf("%d,",i);
            sum++;
            if(sum%9==0) printf("\n");
        }
    printf("\n%d",sum);
    system("pause");
    return 0;
}