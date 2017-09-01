/*
@param:dp ����
@writer:pprp
@declare:�����򵥵�dp������һ�����������У�
�����ȡ�������ڵ���������ȡ�����ֺ����Ϊ���٣�
@begin:1:05
@end:11:25
@error:Ӧ���Ǵ�1��ʼ���Ǵ�0��ʼ
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

/*
״̬������
f(n)������ǵ�ǰȡ�����λ���Ժ��������ֺ�
״̬ת�ƣ�
f(n) = max(f(n-2),f(n-3) + arr[n];
�߽�״̬��f(0) = 0, f(1) = arr[1], f[2] = max(arr[1],arr[2])
*/

//top down
int arr[101] = {};
int dp[110] = {};

void init()
{
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = max(arr[1],arr[2]);
    dp[3] = max(arr[1]+arr[3],arr[2]);
}

int fun(int n)
{
    init();
    if(dp[n] != 0)
        return dp[n];
    dp[n] = max(fun(n-2),fun(n-3)) + arr[n];
    return dp[n];
}

int dp2[110] = {};
//bottom up
void build()
{
    dp2[0] = 0;
    dp2[1] = arr[1];
    dp2[2] = max(arr[1],arr[2]);

    for(int i = 3; i < 101 ; i++)
    {
        dp2[i] = max(dp2[i-2],dp2[i-3]) + arr[i];
    }
}

int fun2(int n)
{
    return dp2[n];
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> arr[i];

    init();
    build();

    cout << max(fun(4),fun(5)) << endl;
    cout << max(fun2(4),fun2(5)) << endl;
    return 0;
}

