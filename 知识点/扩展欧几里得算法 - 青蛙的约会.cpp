#include <iostream>
using namespace std;
typedef long long ll;
ll x, y, m, n, L,tx,ty;
ll ex_gcd(ll a, ll b, ll&x, ll&y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ans = ex_gcd(b,a%b,x,y);
    int tmp = x;
    x = y;
    y = tmp - a/b * y;
    return ans;
}
int main()
{
    cin >> tx >> ty >> m >> n >> L;
    ll M = ex_gcd(n-m,L,x,y);
    if((tx-ty)%M || m == n)
        cout << "Impossible" << endl;
    else
    {
        ll bb = L/M;//��������Ժ��y��ϵ��
        x = x*((tx-ty)/M);//�ҵ����ܴ��ڵı�����ϵ������ 14x+3y and 28x+6y
        x = (x%bb+bb)%bb;//�ҵ���С��������
        cout << x << endl;
    }
    return 0;
}
