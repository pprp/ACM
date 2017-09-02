/*
@theme:tmp�����������
@writer:pprp
@begin:10:00
@end:14:32
@declare���Ӷ�ΪO(n^2)
@error:dp[i] = MAX(dp[j]+1,dp[i]),dp[i] = 1��ʼ��Ϊ1
@date:2017/9/2
*/

#include <bits/stdc++.h>

using namespace std;

int arr[10010],tmp[10010];
int len;

/*
״̬���壺�õ�tmp����
tmp[i]:������Ƕ������г���Ϊi��LIS,���Ľ����С�п����Ƕ��٣�
       ���ԽС�Ǿ�Խ���ױ�ȡ��
tmp�е�Ԫ�����ϸ������
״̬ת�ƣ�
        if( dp[j] = i )
            tmp[i] = min(arr[j])
�������--�ö��ֵķ���ȥ��
if(tmp[i] < arr[n] && tmp[i+1] >= arr[n] )
    f[n] = i+1 .... i ������ǳ���

*/

//���ֲ���,��tmp�н��ж��ֲ���arr[i]
//��tmp������и���
void bisearch(int x)
{
    int left=1,mid,right=len;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(tmp[mid]<x)
            left=mid+1;
        else
            right=mid-1;
    }
    tmp[left]=x;
}

int main()
{
    int N;
    while(cin >> N && N)
    {
        len=1;
        cin >> arr[0];
        tmp[len]=arr[0];

        for(int i=1; i<N; i++)
        {
            scanf("%d",&arr[i]);

            if(arr[i] > tmp[len])//�����ǰiָ���arr��ֵ����tmp��ǰ��ֵ
            {
                len++;
                tmp[len]=arr[i];
            }//��tmp�����м���arr��ֵ
            else
                bisearch(arr[i]);//��tmp�н��в����ҵ��ľͽ������
            //�����lower_bound�Ļ���������
            //*lower_bound(tmp,tmp+len,arr[i]) = arr[i];
        }
        printf("%d\n",len);
    }
    return 0;
}
