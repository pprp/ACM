/*
@theme:�þ�������ݽ�����Ե��ƹ�ʽ-쳲���������
@writer:pprp
@begin:21:17
@end:19:10
@error:ע��mod��λ�ã���������,Ҫ����������
@date:2017/9/13
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int mod=10000;

struct Mat
{
    ll a[2][2];
};

Mat mat_mul(Mat x, Mat y)
{
    Mat res;
    memset(res.a,0,sizeof(res.a));
    for(int i = 0 ; i < 2; i++)
        for(int j = 0 ; j < 2; j++)
            for(int k = 0 ; k < 2; k++)
            {
                res.a[i][j] += x.a[i][k] * y.a[k][j];
                res.a[i][j] %= mod;
            }
    return res;
}

void quick_pow(ll n)
{
    Mat E,res;
    E.a[0][0] = E.a[0][1] = E.a[1][0] = 1;
    E.a[1][1] = 0;
    memset(res.a,0,sizeof(res.a));

    for(int i = 0 ; i < 2; i++)//���׵�λ����
        res.a[i][i] = 1;

    while(n)
    {
        if(n&1)
            res = mat_mul(res,E);
        E = mat_mul(E,E);
        n >>= 1;
    }
    cout << res.a[0][1] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    ll n;
    while(cin >> n && n != -1)
    {
        quick_pow(n);
    }
    return 0;
}
