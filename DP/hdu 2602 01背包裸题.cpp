/*
@theme: 01 �������� - һά���� hdu 2602
@writer:pprp
@begin:15:34
@end:15:42
@declare:�������01�������� POJ 3624
@error:���ȡ����dp[M]���� dp[M-1],Ȼ��ע�����ݷ�Χdp�����ݷ�Χ��M�ķ�Χ
@date:2017/9/3
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn = 1010;
int dp[maxn];
int w[maxn], v[maxn];
int N, M;

int main()
{
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas--)
    {
        memset(dp,0,sizeof(dp));
        cin >> N >> M;
        for(int i = 0 ; i < N ; i++)
            cin >> v[i];
        for(int i = 0 ; i < N ; i++)
            cin >> w[i];

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = M ; j >= w[i] ; j--)
            {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout << dp[M] << endl;
    }

    return 0;
}
