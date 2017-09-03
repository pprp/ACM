/*
@theme: 01 �������� - һά����
@writer:pprp
@begin:14::43
@end:15:30
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

const int maxn = 3500;
int w[maxn],v[maxn];
int dp[13000];
int N, M;

int main()
{
    //    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        for(int i = 1; i <= N ; i++)
        {
            scanf("%d%d",&w[i],&v[i]);
        }
        for(int i = 1 ; i <= N ; i++)
        {
            for(int j = M ; j >= w[i] ; j--)
            {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        printf("%d\n",dp[M]);
        memset(dp,0,sizeof(dp));
    }


    return 0;
}

