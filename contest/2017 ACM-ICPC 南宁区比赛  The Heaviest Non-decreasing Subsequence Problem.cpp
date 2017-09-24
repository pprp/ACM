//ac : L
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 1000000+1000

using namespace std;

int a[N];
int dp[N];

int binarySearch(int key,int l,int r)
{
    while(l <= r)
    {
        int mid = (l + r)>>1;
        if(key>=dp[mid] && key<=dp[mid+1])
            return mid;
        else if(key>dp[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return 0;
}

int main()
{
    int cnt = 0;
    int tmp;
    while(cin >> tmp)
    {
        if(tmp < 0)
        {}
        else if(tmp >= 10000)
        {
            for(int i=0; i<5; i++)//�ȼ۳�5��
            {
                a[cnt++] = tmp-10000;
            }
        }
        else
        {
            a[cnt++] = tmp;
        }
    }

    dp[1]=a[0];  //��ʼ��
    int len=1;
    for (int i=1; i<cnt; i++)
    {
        if (a[i] >= dp[len])
            dp[++len] = a[i];  //������Խ���len����ͽ���
        else  //�������һ������滻���滻��
        {
            int j = upper_bound(dp+1,dp+len+1,a[i])-dp;  //�ҵ���һ����������d���±�
            dp[j] = a[i];
        }
    }

    cout<<len<<endl;

    return 0;
}
