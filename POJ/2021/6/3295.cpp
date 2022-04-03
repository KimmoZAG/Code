# include<iostream>

using namespace std;
char inch[101];
int lpl;

bool step(char inch[101], int uu)
{
    lpl++;
    switch(inch[lpl])
    {
        case 'p':return uu&1;
        case 'q':return(uu >> 1)&1;
        case 'r':return(uu >> 2)&1;
        case 's':return(uu >> 3)&1;
        case 't':return(uu >> 4)&1;
        case 'N':return !step(inch, uu); 
        case 'K':return step(inch, uu) & step(inch, uu);
        case 'A':return step(inch, uu) | step(inch, uu);
        case 'C':return !step(inch, uu) | step(inch, uu);
        case 'E':return step(inch, uu) == step(inch, uu);   
    }
}
bool judge(char inch[101])
{
    for(int i = 0;i < 32;i++)
    {
        lpl = -1;
        if(!step(inch,i))    return 0;
    }
    return 1;
}
int main(void)
{
    while(1)
    {
        cin >> inch;
        if(inch[0] == '0') break;
        if(judge(inch)) printf("tautology\n");
        else    printf("not\n");
    }
    return 0;
}
