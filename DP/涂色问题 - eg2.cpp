/*
@param:dp ����
@writer:pprp
@declare:�����򵥵�dp����������������ɫ������������̲����ڵ�����n��Ԫ�ص����
@begin:10:10
@end:10:28
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

/*
״̬ȷ�����������һλ����ɫȷ��״̬
f(n,0):���һλ�Ǻ�ɫ������
f(n,1):���һλ����ɫ������
f(n,2):���һλ����ɫ������
״̬ת�ƣ�
f(n,0) = f(n-1,0) + f(n-1,1) + f(n-1,2)
f(n,1) = f(n-1,0) + f(n-1,1)
f(n,2) = f(n-1,0) + f(n-1,2)
��ʼ������
f(1,0) = 1;
f(1,1) = 1;
f(1,2) = 1;
���մ𰸣�
f(n,0) + f(n,1) +��(n,2);
*/

// top down
int dp1[101][3] = {0};

void init()
{
    dp1[1][0] = dp1[1][1] = dp1[1][2] = 1;
}

int fun(int n,int m)
{
    if(dp1[n][m] != 0)
        return dp1[n][m];

    if(m == 0) dp1[n][0] = fun(n-1,0) + fun(n-1,1) + fun(n-1,2);
    if(m == 1) dp1[n][1] = fun(n-1,0) + fun(n-1,1);
    if(m == 2) dp1[n][2] = fun(n-1,0) + fun(n-1,2);

    return dp1[n][m];
}

//bottom up
int dp2[101][3] = {3};
int build()
{
    dp2[1][0] = dp2[1][1] = dp2[1][2] = 1;
    for(int i = 2; i < 101 ; i++)
    {
        dp2[i][0] = dp2[i-1][0] + dp2[i-1][1] + dp2[i-1][2];
        dp2[i][1] = dp2[i-1][0] + dp2[i-1][1];
        dp2[i][2] = dp2[i-1][0] + dp2[i-1][2];
    }
}
int fun2(int n)
{
    return dp2[n][0] + dp2[n][1] + dp2[n][2];
}

//run
int main()
{
    int a;
    cin >> a;
    init();
    build();

    cout << fun(a,0) + fun(a,1) + fun(a,2) << endl;
    cout << fun2(a) << endl;
    return 0;
}
