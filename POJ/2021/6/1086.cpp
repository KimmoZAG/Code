# include<iostream>

using namespace std;
int pp[21];
int ww[21];
char kuo[42];
int len;

void mange(int len, int ww[21], char kuo[21]){
    int q = 0;
    for(int i = 1;i <= len;i++)
    {
        int count = 0;
        for(int k = 0;k < len * 2;k++){
            if(kuo[k] == ')')   count++;
            if(count == i){
                int flag = 1, count2 = 1;
                for(int h = k - 1;h >= 0;h--){
                    if(kuo[h] == ')'){
                        flag++;
                        count2++;
                    }
                    if(kuo[h] == '(')   flag--;
                    if(flag == 0){
                        ww[q++] = count2;
                        break;
                    }
                }
                break;
            } 
        }
    }
    int i;
    for(i = 0;i < len - 1;i++) printf("%d ",ww[i]);
    printf("%d\n", ww[i]);
}

void encode(int len, int pp[21], char kuo[21]){
    int pla = 0, nl;
    while(pla != pp[0]) kuo[pla++] = '(';
    nl = pla - 1;
    kuo[pla++] = ')';
    for(int i = 1;i < len;i++){
        int num = pp[i] - pp[i-1];
        if(num != 0){
            int num2 = num;
            while(num--){
                kuo[pla++] = '(';
                nl++;
            }  
            kuo[pla++] = ')';
        }
        else{
            kuo[pla++] = ')';
        }
    }
    for(int i = 0;i < len * 2;i++)  if(kuo[i] != '(' && kuo[i] != ')')  kuo[pla++] = ')';
}

int main(void)
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &len);
        for(int k = 0;k < len;k++)
        {
            scanf("%d", &pp[k]);
        }
        encode(len, pp, kuo);
        mange(len,ww,kuo);
    }
    system("pause");
    return 0;
}