# include<iostream>
# include<string>
# include<cmath>
# include<windows.h>
#include<fstream>

using namespace std;

typedef struct all_student_grades{
    string name[1005];
    int a[1005];
    int b[1005];
    int c[1005];
    int all[1005];
}ag;

int main(void)
{
    ag a;
    int n;
    ofstream OutFile("Test.txt"); 
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a.name[i] >> a.a[i] >> a.b[i] >> a.c[i];
        a.all[i] = a.a[i] + a.b[i] + a.c[i];
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(abs(a.a[i] - a.a[j]) <= 5 && abs(a.b[i] - a.b[j]) <= 5 && abs(a.c[i] - a.c[j]) <= 5 && abs(a.all[i] - a.all[j]) <= 10)
            {
                OutFile << a.name[i] << " " << a.name[j] << "\n";
                cout << a.name[i] << " " << a.name[j] << "\n";
            }
        }
        //printf("%s\n", a.name[i].c_str());  c_str()将string转为char型以供%s识别
    }
    OutFile.close();
    system("pause");
    return 0;
}
