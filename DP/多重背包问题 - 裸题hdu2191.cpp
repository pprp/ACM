/*
@theme:hdu2191 �봨����
@writer:pprp
@begin:16:25
@end:16:59
@declare:���ر�������
@error:�����Ǵ������ҽ���
@date:2017/9/3
*/

#include <bits/stdc++.h>

using namespace std;
int M, N;//M money N kinds
const int maxn = 110;
int w[maxn],v[maxn],num[maxn];
int dp[maxn*40];

int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    cin >> cas;
    while(cas--)
    {
        memset(dp,0,sizeof(dp));
        cin >> M >> N;
        for(int i = 1; i <= N ; i++)
        {
            cin >> w[i] >> v[i] >> num[i];
        }

        for(int i = 1 ; i <= N; i++ )
        {
            for(int k = 1 ; k <= num[i]; k++)//1��˳������ν
            {
                for(int j = M; j >= w[i] ; j--)//2�������������
                {
                    dp[j] = max(dp[j],dp[j-w[i]]+v[i]);//3�������Ѿ����ظ������ˣ����Ծ�û�б�Ҫ��k*w[i]�Ĺ�����
                }
            }
        }
        cout << dp[M] << endl;
    }

    return 0;
}
