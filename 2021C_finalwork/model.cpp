# include<stdio.h>
# include<iostream>
# include<stdlib.h>
# include<time.h>
# include<windows.h>
# include<string.h>
# include<string>
# include<cstdio>

using namespace std;

string main_name;
int times = 0;
int place;
typedef struct all_gain
{
    string name;
    int num = 0;
} ag[71];
ag income;

//��������
void mode_select(char *a);
void judge_mode(char *a);
void begin_instruction(char *a);
void shilian();
void danchou();
void count_all();
void end_instruction();
int improve_onerate();
void declear_kachi();
int is_right();
int rand_deal(int a, int b, int c);
int rand_deal(int a, int b, int c)
{
    int fi = 1 % c;
    while(b)
    {
        if(b & 1) fi = 1ll * fi * a % c;
        a = 1ll * a * a % c;
        b >>= 1;
    }
    return fi;
}

//���ܣ���Ա���ƴ���
void declear_kachi()
{
    income[1].name = "��껽�";
    income[2].name = "��껽ܵ�����<���>";
    income[3].name = "����";
    income[4].name = "���ܵ�����<����ơ>";
    income[5].name = "������";
    income[6].name = "�����̵�����<������>";
    income[7].name = "������";
    income[8].name = "�����ڵ�����<ը��>";
    income[9].name = "�ŵ�";
    income[10].name = "�ŵѵ�����<����>";
    income[11].name = "��˳ƽ";
    income[12].name = "��˳ƽ������<���>";
    income[13].name = "�ƽ���";
    income[14].name = "�ƽ��ε�����<ũҩ>";
    income[15].name = "�����";
    income[16].name = "����ε�����<����>";
    income[17].name = "���";
    income[18].name = "��ϵ�����<ˮ��>";
    income[19].name = "���";
    income[20].name = "��溵�����<��ֽ>";
    income[21].name = "����";
    income[22].name = "����������<ʪ��>";
    income[23].name = "½־��";
    income[24].name = "½־�������<py�α�>";
    income[25].name = "������";
    income[26].name = "�����ȵ�����<�˶���>";
    income[27].name = "�����";
    income[28].name = "����������<�ֻ�>";
    income[29].name = "���ɸ�";
    income[30].name = "���ɸ�������<�˶��ֻ�>";
    income[31].name = "������";
    income[32].name = "������������<����>";
    income[33].name = "����Ρ";
    income[34].name = "����Ρ������<����>";
    income[35].name = "����";
    income[36].name = "����������<���>";
    income[37].name = "���";
    income[38].name = "��䭵�����<��׹>";
    income[39].name = "���";
    income[40].name = "��῵�����<¿��>";
    income[41].name = "��Ԫ��";
    income[42].name = "��Ԫ�������<ħ����Ů����>";
    income[43].name = "֣��";
    income[44].name = "֣�������<steamӲ��>";
    income[45].name = "������";
    income[46].name = "�����õ�����<��ݼݼ>";
    income[47].name = "������";
    income[48].name = "�����������<����>";
    income[49].name = "��ԥ��";
    income[50].name = "��ԥ��������<��˿��>";
    income[51].name = "��˼��";
    income[52].name = "��˼�ܵ�����<��ͷ>";
    income[53].name = "����";
    income[54].name = "���ܵ�����<������>";
    income[55].name = "������";
    income[56].name = "������������<Ƥ��>";
    income[57].name = "������";
    income[58].name = "�����ܵ�����<��˿��>";
    income[59].name = "�Ž�";
    income[60].name = "�Ž�������<�����ڿ�>";
}

//���ܣ�ʮ��
void shilian()
{
    int a, rate_plus;
    cout << "��ϲ�������鵽�ˣ�\n";
    if(main_name != "0000")
    {
        rate_plus = 10;
    }
    else
    {
        rate_plus = 0;
    }
    for(int i = 0;i < 10;i++)
    {
        int b = rand() % 940 + 61;
        int c = rand() % 940 + 61;
        int d = 60 + rate_plus + 1;
        a = rand_deal(b, c, d) + 1;
        if(a > 60)
        {
            a = place;
        }
        if(a == 0) a = rand() % 61 + 1;
        if(a % 2 == 0 && income[a - 1].num == 0)//����鵽������ж�û�����������
        {
            Sleep(200);
            cout << income[a - 1].name << endl;
            times++;
            income[a - 1].num++;
        }
        else if(a % 2 != 0 && income[a].num == 0)//�鵽�������������Ϊ��
        {
            Sleep(200);
            cout << income[a].name << endl;
            times++;
            income[a].num++;
        }
        else if(a % 2 != 0 && income[a].num != 0)
        {
            a++;
            Sleep(200);
            cout << income[a].name << endl;
            times++;
            income[a].num++;
        }
        else
        {
            Sleep(200);
            cout << income[a].name << endl;
            times++;
            income[a].num++;
        }
    }
}

//���ܣ�����
void danchou()
{
    int a;
    int rate_plus;
    if(main_name != "0000")
    {
        rate_plus = 10;
    }
    else
    {
        rate_plus = 0;
    }
    int b = rand() % 940 + 61;
    int c = rand() % 940 + 61;
    int d = 60 + rate_plus + 1;
    a = rand_deal(b, c, d) + 1;
    if(a > 60)
    {
        a = place;
    }
    if(a == 0) a = rand() % 61 + 1;
    if(a % 2 == 0 && income[a-1].num == 0)//����鵽������ж�û�����������
    {   
        Sleep(200);
        cout << income[a - 1].name << endl;
        times++;
        income[a - 1].num++;
    }
    else if(a % 2 != 0 && income[a].num == 0)//�鵽�������������Ϊ��
    {
        Sleep(200);
        cout << income[a].name << endl;
        times++;
        income[a].num++;
    }
    else if(a % 2 != 0 && income[a].num != 0)
    {
        a++;
        Sleep(200);
        cout << income[a].name << endl;
        times++;
        income[a].num++;
    }
    else
    {
        cout << income[a].name << endl;
        times++;
        income[a].num++;
    }
    return;
}

//���ܣ��ܽ�ս��
void count_all()
{
    for(int i = 0;i < 60;i++)
    {
        if(income[i].num != 0)
        {
            cout << "�����" << income[i].num << "��" <<income[i].name << endl;
            Sleep(500);
        }
    }
    return;
}

//Ѱ��ģʽѡ��
void mode_select(char *a)
{
    printf("ѡ�����Ѱ��ģʽ��\n");
    Sleep(300);
    printf("1->ʮ��Ѱ��\n2->����Ѱ��\n3->�ܽ�ս��\n���»س���ʼѡ��");
    cin >> a;
    judge_mode(a);
    return;
}

//����ѡ��������Ӧ�ĳ���
void judge_mode(char *a)
{
    if('1' == *a)
    {
        shilian();
    }
    else if('2' == *a)
    {
        danchou();
    }
    else if('3' == *a)
    {
        count_all();
        return;
    }
    else
    {
        printf("�����˷Ƿ����ݣ����������룡\n");
        mode_select(a);
    }
    if(times + 1 > 100)
    {
        cout << "�ô�Ѱ���ѽ�����" << endl;
    }
    else
    {
        mode_select(a);
    }
    return;
}

//��ͷ��ʾ
void begin_instruction(char *a)
{
    printf("��ӭ����04912001��ԱѰ�ã��˴�Ѱ��Ϊ�޶�Ѱ�ã�\n");
    printf("�Ƿ���Ҫ���ĳ��ͬѧ�ı��ʣ�\n");
    printf("�������������ɣ�(����Ҫ��Ҫ����0000)\n");
    printf("���»س���������:");
    cin >> main_name;
    cout << "���������" + main_name << endl;
    while(1)
    {
        if(1 == is_right())
        {
            break;
        }
        else
        {
            printf("����������ݷǷ������������룡\n");
            cin >> main_name;
            cout << "���������" + main_name << endl;
        }
    }
    if(main_name != "0000")
    {
        cout << "������߶�" + main_name + "�ĳ�����" << endl;
        cout << "���Ժ�......" <<endl;
        place = improve_onerate();
        Sleep(1000);
        cout << "��߳ɹ���" << endl;
    }
    mode_select(a);
    return;
}

//������
void end_instruction()
{
    printf("�˴�Ѱ�ý������ļ�\"stdout.txt\"�Ѿ�����ô�Ѱ�ý��\n");
    freopen("stdout.txt","w",stdout);
    for(int i = 1;i <= 60;i += 2)
    {
        if(income[i].num != 0)
        {
            cout << "�����" << income[i].num << "��" <<income[i].name << endl;
        }
    }
    for(int i = 2;i <= 60;i += 2)
    {
        if(income[i].num != 0)
        {
            cout << "�����" << income[i].num << "��" <<income[i].name << endl;
        }
    }
    fclose(stdout);
    return;
}

int improve_onerate()
{
    int i, k;
    for(i = 1;i < 61;i++)
    {
        if(main_name == income[i].name)
        {
            for(k = 61;k < 71;k += 2)
            {
                income[k].name = main_name;
                income[k + 1].name = income[i + 1].name;
            }
            break;
        }
    }
    return i;
}

int is_right()
{
    int i, flag;
    for(i = 1;i < 61;i++)
    {
        if(main_name == income[i].name)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1 || main_name == "0000")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(void)
{
    freopen("in2.txt","r",stdin);
    char a;
    srand(time(NULL));//���ݵ�ǰʱ�����������
    declear_kachi();
    begin_instruction(&a);
    end_instruction();
    fclose(stdin);
    Sleep(5000);
    return 0;  
}