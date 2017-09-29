/*
����ɸѡ��ɸѡ��С�ڵ���MAXN��������
prime[0]��ŵ��������ĸ���
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100;
int prime[MAXN+1];
void getprime()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2; i <= MAXN ; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0] && prime[j] <= MAXN/i ; j++)//���ﲻҪд��MAXN/i
        {
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main()
{

    getprime();
    for(int i = 1 ; i <= prime[0]; i++)
    {
        cout << prime[i] << endl;
    }
    cout << endl;

    cout << prime[0] << endl;
    return 0;
}
