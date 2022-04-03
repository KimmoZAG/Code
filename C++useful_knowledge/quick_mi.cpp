//pre_knowledge
/*ȡģ����
            (a * b) % p == (a % p) * (b % p) % p;
            (a + b) % p == (a % p + b % p) % p;
            a ^ b % p == ((a % p) ^ b) % p;
            �������Դ�Ϊ����չ��
*/
/*��ѧ���
            ���ǳ��ϣ��κ�һ���������Բ��Ϊһ���й�2�Ķ���ʽ
            b = cn * 2 ^ n + ..... + c0 * 2 ^ 0;
            ����һ����n+1��;
*/
//�㷨ʵ��
# include<iostream>

using namespace std;

int power(int a,int b,int c)
{
    int final_num = 1 % c;//���cΪ1ֱ��Ϊ0
    while(b)
    {
        if(b & 1) final_num = 1ll * final_num * a % c;
        a = 1ll * a * a % c;//�����a����δ��Ľ׶�,��Ҫ����һ��������mol c
        b >>= 1;
    }
    return final_num;
}

int main(void)
{
    int a, b, c;
    int k = power(a, b, c);
    printf("%d", k);
    return 0;
}