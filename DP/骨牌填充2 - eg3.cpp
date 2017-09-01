/*
@param:dp ����
@writer:pprp
@declare:�����򵥵�dp�� ����2*1 & 3*1 L�͹�������2*n�ĸ��ӣ��м����ķ�
@begin:10:36
@end:11:00
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

/*
״̬������
f(n) ������Ƿ�n*2������ʱ��ķ�����
״̬ת�ƣ�
�������ǿ��2*1�ģ�f(n) = f(n-1) + f(n-2)
�������ǿ��3*1�ģ�f(n) = f(n-3) + f(n-4) + ... + f(0)�����ڶԳƵĹ�ϵ��Ҫ��2
�ۺ������� f(n) = f(n-1) + f(n-2) + 2 * (f(n-3) + f(n-4) +...+ f(0))
�߽�״̬��f(0) = 1; f(1) = 1; f(2) = 2;
*/

//top down
int dp[101] = {0};
void init()
{
    dp[0] = dp[1] = 1;
    dp[2] = 2;
}
int fun(int n)
{
    init();
    if(dp[n] != 0) return dp[n];
    dp[n] = 2 * fun(n-1) + fun(n-3);
    return dp[n];
}

//bottom up
int dp2[101] = {};

void build()
{
    dp2[0] = dp2[1] = 1;
    dp2[2] = 2;

    for(int i = 3 ; i < 101 ; i++)
        dp2[i] = 2 * dp2[i-1] + dp2[i-3];
}

int fun2(int n)
{
    return dp2[n];
}

int main()
{
    int a;
    srand((int)time(NULL));
    a = rand()%100;

    build();
    cout << fun(a) << endl;
    cout << fun2(a) << endl;

    return 0;
}
