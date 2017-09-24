//ac F
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=1e6+10;

#define mm(a) memset(a,0,sizeof(a))

int num1[maxn*4];
int num[maxn*4],X[maxn*4];
struct edge
{
    int l,r,h;
    int s;//sΪ1���±ߣ�sΪ-1���ϱ�
    edge() {};
    edge(int a,int b,int c,int d) : l(a),r(b),h(c),s(d) {}
    bool operator<(const edge &n)const
    {
        return h<n.h;
    }
} ss[maxn];

void pushup(int le,int ri,int node)
{
    if(num1[node])
        num[node]=X[ri+1]-X[le];//�ڸ��µ�ʱ�򣬿��������������ص��������Ͳ�������ǰ��ô���£����ǽ�le��ri����
    else if(le==ri)
        num[node]=0;           //Ȼ��X[ri+1]-X[le]��ֵ���и��£��������ظ��ĳ���
    else
        num[node]=num[node<<1]+num[node<<1|1];
}
void update(int l,int r,int add,int le,int ri,int node)
{
    if(l<=le&&ri<=r)
    {
        num1[node]+=add;//������������
        pushup(le,ri,node);
        return ;
    }
    int t=(le+ri)>>1;
    if(l<=t) update(l,r,add,le,t,node<<1);
    if(r>t) update(l,r,add,t+1,ri,node<<1|1);
    pushup(le,ri,node);
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
        {
            cout << "*" << endl;
            break;
        }
        int a,b,c,d;
        int k=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            X[k]=a;
            ss[k++]=edge(a,c,b,1);
            X[k]=c;
            ss[k++]=edge(a,c,d,-1);
        }
        sort(X,X+k);
        sort(ss,ss+k);
        int k1=1;
        for(int i=1; i<k; i++) //��X������ɢ��
        {
            if(X[i]!=X[i-1]) X[k1++]=X[i];
        }
        mm(num);
        mm(num1);
        int ans=0;
        for(int i=0; i<k-1; i++)
        {
            int l=lower_bound(X,X+k1,ss[i].l)-X;
            int r=lower_bound(X,X+k1,ss[i].r)-X-1;
            update(l,r,ss[i].s,0,k1-1,1);
            ans+=num[1]*(ss[i+1].h-ss[i].h);//num[1]Ϊ��ǰ��������ܳ���
        }
        cout << ans << endl;
    }
    return 0;
}
