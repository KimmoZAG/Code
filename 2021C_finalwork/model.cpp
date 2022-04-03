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

//函数声明
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

//功能：干员名称存入
void declear_kachi()
{
    income[1].name = "封昊杰";
    income[2].name = "封昊杰的信物<猪鼻>";
    income[3].name = "代杰";
    income[4].name = "代杰的信物<菠萝啤>";
    income[5].name = "吕方程";
    income[6].name = "吕方程的信物<臭袜子>";
    income[7].name = "丁子腾";
    income[8].name = "丁子腾的信物<炸鸡>";
    income[9].name = "闻笛";
    income[10].name = "闻笛的信物<薯条>";
    income[11].name = "古顺平";
    income[12].name = "古顺平的信物<红笔>";
    income[13].name = "黄锦涛";
    income[14].name = "黄锦涛的信物<农药>";
    income[15].name = "李金涛";
    income[16].name = "李金涛的信物<篮球>";
    income[17].name = "张睿诚";
    income[18].name = "张睿诚的信物<水卡>";
    income[19].name = "林婧";
    income[20].name = "林婧的信物<卷纸>";
    income[21].name = "刘政";
    income[22].name = "刘政的信物<湿巾>";
    income[23].name = "陆志朋";
    income[24].name = "陆志朋的信物<py课本>";
    income[25].name = "宁娜娜";
    income[26].name = "宁娜娜的信物<运动裤>";
    income[27].name = "沈楠轲";
    income[28].name = "沈楠轲的信物<手机>";
    income[29].name = "王成付";
    income[30].name = "王成付的信物<运动手环>";
    income[31].name = "王文宁";
    income[32].name = "王文宁的信物<咸鱼>";
    income[33].name = "余征巍";
    income[34].name = "余征巍的信物<鸡尖>";
    income[35].name = "张雯";
    income[36].name = "张雯的信物<鼠标>";
    income[37].name = "张洵";
    income[38].name = "张洵的信物<吊坠>";
    income[39].name = "张峥";
    income[40].name = "张峥的信物<驴子>";
    income[41].name = "赵元祥";
    income[42].name = "赵元祥的信物<魔法少女漫画>";
    income[43].name = "郑语";
    income[44].name = "郑语的信物<steam硬盘>";
    income[45].name = "周婷婷";
    income[46].name = "周婷婷的信物<何菁菁>";
    income[47].name = "吉俊灵";
    income[48].name = "吉俊灵的信物<香烟>";
    income[49].name = "刘豫航";
    income[50].name = "刘豫航的信物<黑丝袜>";
    income[51].name = "王思杰";
    income[52].name = "王思杰的信物<枕头>";
    income[53].name = "向恒杰";
    income[54].name = "向恒杰的信物<紫罗兰>";
    income[55].name = "杨雨龙";
    income[56].name = "杨雨龙的信物<皮包>";
    income[57].name = "余利哲";
    income[58].name = "余利哲的信物<白丝袜>";
    income[59].name = "张健";
    income[60].name = "张健的信物<丁字内裤>";
}

//功能：十连
void shilian()
{
    int a, rate_plus;
    cout << "恭喜您，您抽到了：\n";
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
        if(a % 2 == 0 && income[a - 1].num == 0)//如果抽到信物，但判断没有人物，抽人物
        {
            Sleep(200);
            cout << income[a - 1].name << endl;
            times++;
            income[a - 1].num++;
        }
        else if(a % 2 != 0 && income[a].num == 0)//抽到人物，且人物数量为零
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

//功能：单抽
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
    if(a % 2 == 0 && income[a-1].num == 0)//如果抽到信物，但判断没有人物，抽人物
    {   
        Sleep(200);
        cout << income[a - 1].name << endl;
        times++;
        income[a - 1].num++;
    }
    else if(a % 2 != 0 && income[a].num == 0)//抽到人物，且人物数量为零
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

//功能：总结战果
void count_all()
{
    for(int i = 0;i < 60;i++)
    {
        if(income[i].num != 0)
        {
            cout << "获得了" << income[i].num << "个" <<income[i].name << endl;
            Sleep(500);
        }
    }
    return;
}

//寻访模式选择
void mode_select(char *a)
{
    printf("选择你的寻访模式：\n");
    Sleep(300);
    printf("1->十连寻访\n2->单次寻访\n3->总结战果\n按下回车开始选择：");
    cin >> a;
    judge_mode(a);
    return;
}

//根据选择运行相应的程序
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
        printf("输入了非法数据！请重新输入！\n");
        mode_select(a);
    }
    if(times + 1 > 100)
    {
        cout << "该次寻访已结束！" << endl;
    }
    else
    {
        mode_select(a);
    }
    return;
}

//开头提示
void begin_instruction(char *a)
{
    printf("欢迎进入04912001干员寻访，此次寻访为限定寻访：\n");
    printf("是否需要提高某个同学的爆率？\n");
    printf("输入其姓名即可！(不需要需要输入0000)\n");
    printf("按下回车即可输入:");
    cin >> main_name;
    cout << "您输入的是" + main_name << endl;
    while(1)
    {
        if(1 == is_right())
        {
            break;
        }
        else
        {
            printf("您输入的数据非法，请重新输入！\n");
            cin >> main_name;
            cout << "您输入的是" + main_name << endl;
        }
    }
    if(main_name != "0000")
    {
        cout << "正在提高对" + main_name + "的出货率" << endl;
        cout << "请稍后......" <<endl;
        place = improve_onerate();
        Sleep(1000);
        cout << "提高成功！" << endl;
    }
    mode_select(a);
    return;
}

//结束语
void end_instruction()
{
    printf("此次寻访结束，文件\"stdout.txt\"已经储存该次寻访结果\n");
    freopen("stdout.txt","w",stdout);
    for(int i = 1;i <= 60;i += 2)
    {
        if(income[i].num != 0)
        {
            cout << "获得了" << income[i].num << "个" <<income[i].name << endl;
        }
    }
    for(int i = 2;i <= 60;i += 2)
    {
        if(income[i].num != 0)
        {
            cout << "获得了" << income[i].num << "个" <<income[i].name << endl;
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
    srand(time(NULL));//根据当前时间生成随机数
    declear_kachi();
    begin_instruction(&a);
    end_instruction();
    fclose(stdin);
    Sleep(5000);
    return 0;  
}