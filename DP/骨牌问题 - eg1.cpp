/*
@param:dp ����
@writer:pprp
@declare:�����򵥵�dp
@begin:9:00
@end:10:00
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

//δ�Ż����������
int fun(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;

    return fun(n-1) + fun(n-2);
}

//�Զ����µļ��仯
//top down С�ĵݻع���
int dp[101] = {1,1,2};
int fun2(int n)
{
    if(dp[n] != 0)
        return dp[n];
    return fun2(n-1) + fun(n-2);
}

//�Ե�����
//������һ��Ҫ��ĸ����Ҫ���ܵ���ע��ݻ��ܷ�
int dp2[101] = {0};
void build()
{
    dp2[1] = 1;
    dp2[2] = 2;
    for(int i = 3 ; i < 101; i++)
     dp2[i] = dp2[i-1] + dp2[i-2];
}
int fun3(int n)
{
    return dp2[n];
}

int main()
{
    build();
    int a;
    while(cin >> a)
    {
        cout << fun(a) << endl;
        cout << fun2(a) << endl;
        cout << fun3(a) << endl;
    }

    return 0;
}
