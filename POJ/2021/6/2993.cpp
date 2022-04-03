# include<iostream>
# include<map>
# include<string>

using namespace std;

map <int, char> sign;
void printmap();
void create();

void create()
{
    string iline, iline1;
    for(int i = 1;i < 65;i++)   sign[i] = '0';
    cin >> iline1 >> iline1 >> iline >> iline;
    for(int i = 0;iline1[i] != '\0';i++)    if(iline1[i] < 91 && iline1[i] > 64)    sign[iline1[i+1] - 96 + (104 - iline1[i+2] - 48)*8] = iline1[i];
    for(int i = 0;iline[i] != '\0';i++)     if(iline[i] < 91 && iline[i] > 64)  sign[iline[i+1] - 96 + (104 - iline[i+2] - 48)*8] = iline[i] + 32;
    for(int i = 0;iline1[i] != '\0';i++)    if(iline1[i] > 96 && iline1[i] < 123 && iline[i-1] < 48)    sign[iline1[i] - 96 + (104 - iline1[i+1] - 48)*8] = 'P';
    for(int i = 0;iline[i] != '\0';i++)     if(iline1[i] > 96 && iline1[i] < 123 && iline[i-1] < 48)    sign[iline[i] - 96 + (104 - iline[i+1] - 48)*8] = 'p';
}

void printmap()
{
    int line = 1, num = 1;
    while(line++ < 9)
    {
        cout << "+---+---+---+---+---+---+---+---+" << endl;
        if(line % 2 == 0)
        {
            while(1)
            {
                cout << '|';
                if(num % 2 != 0)
                {
                    if(sign[num] == '0') cout << "...";
                    else cout << '.'<<sign[num] << '.' ;
                }
                else
                {
                    if(sign[num] == '0') cout << ":::";
                    else cout << ':'<<sign[num] << ':' ;
                }
                num++;
                if((num - 1) % 8 == 0)    
                {   
                    cout << '|' << endl;
                    break;
                }
            }
        }
        else
        {
            while(1)
            {
                cout << '|';
                if(num % 2 != 0)
                {
                    if(sign[num] == '0') cout << ":::";
                    else cout << ':'<<sign[num] << ':';
                }
                else
                {
                    if(sign[num] == '0') cout << "...";
                    else cout << '.'<<sign[num] << '.';
                }
                num++;
                if((num - 1) % 8 == 0)    
                {   
                    cout << '|' << endl;
                    break;
                }
            }
        }
    }
    cout << "+---+---+---+---+---+---+---+---+" << endl;
}


int main(void)
{
    create();
    printmap();
    system("pause");
    return 0;
}   