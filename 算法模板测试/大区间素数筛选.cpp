/*
*prime DIstance
*����һ������[L,U],�ҵ����ڵľ�����������������ĺ�
*���о�����Զ����������
*1 <= L < U <= 2147483647
*���䳤�Ȳ�����1000000
*����Ҫɸѡ��[L,U]֮�������
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAXN = 100010;
int prime[MAXN+1];

//�ҵ����е�����
void getprime()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2; i <= MAXN ; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j = 1 ; j <= prime[0]&&prime[j] <= MAXN/i; j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
bool notprime[1000010];
int prime2[1000010];

//�ҵ�ָ�������ڵ�������ŵ�prime2������
void getprime2(int L, int R)
{
    memset(notprime,0,sizeof(notprime));
    if(L < 2)
        L = 2;
    for(int i = 1; i < prime[0]&&(long long)prime[i]*prime[i] <= R; i++)
    {
        int S = L/prime[i] + (L%prime[i] > 0);
        if(S == 1)
            S = 2;
        for(int j = S; (long long)j * prime[i]<= R; j++)
        {
            if((long long)j * prime[i] >= L)
                notprime[j*prime[i]-L] = true;
        }
    }
    prime2[0] = 0;
    for(int i = 0 ; i <= R-L; i++)
    {
        if(!notprime[i])
            prime2[++prime2[0]] = i + L;
    }
}
int main()
{
     getprime();
     int L, U;
     while(scanf("%d%d",&L,&U) == 2)
     {
         getprime2(L,U);

         if(prime2[0] < 2)
            printf("There are no adjacent primes.\n");
         else
         {
             int x1 = 0, x2 = 100000000, y1 = 0, y2 = 0;
             for(int i = 1 ; i < prime2[0]; i++)
             {
                 if(prime2[i+1]-prime2[i] < x2-x1)//�ҵ���������ĵ�
                 {
                     x1 = prime2[i];
                     x2 = prime2[i+1];
                 }
                 if(prime2[i+1]-prime2[i]>y2-y1)//�ҵ�������Զ�ĵ�
                 {
                     y1 = prime2[i];
                     y2 = prime2[i+1];
                 }
             }
             printf("%d,%d are closest, %d,%d are most distant.\n",x1,x2,y1,y2);
         }
     }
    return 0;
}
