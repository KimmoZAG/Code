#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,s;
double map[105]={0},g1[105][105]={0},g2[101][101]={0},v;
int floyd()
{
	int i,j,k;
	double d[105];
	for(i=1;i<=n;i++)d[i]=map[i];
	for(k=1;k<=n;k++)
	   for(i=1;i<=n;i++)
	      for(j=1;j<=n;j++)
	      	if((map[i]-g2[i][j])*g1[i][j]>map[j])map[j]=(map[i]-g2[i][j])*g1[i][j];
	for(i=1;i<=n;i++)
		if(d[i]<map[i])return 1;
	return 0;
}
int main()
{
	cin>>n>>m>>s>>v;
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		int a,b;
		double c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		g1[a][b]=c,g2[a][b]=d;
		g1[b][a]=e,g2[b][a]=f;
	}
	map[s]=v;
	floyd();              
	if(floyd())cout<<"YES\n";
	else cout<<"NO\n";
    system("pause");
}
