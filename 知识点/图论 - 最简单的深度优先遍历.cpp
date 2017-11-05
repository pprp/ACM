### ������� - ��ʽǰ���Ǳ�ʾ��

#### writer��pprp

#### ������
- ��������ǰ�ڵ�ı��Ϊdfs�Ĳ���
- ע�⣺Ҫ���⿪һ��VIS�������Ϳɫ��Ϳ��ɫ�ľͲ�Ҫ��Ϳɫ��
- head����Ӧ��ȫ��-1��VIS����ȫ��0
- ����������Ӧ��ע��һ�� k = edge[k].next

##### �������£�

```
#include <iostream>
#include <cstring>
#include <cstdio>
//ͼ�ı���
using namespace std;
const int maxn = 1000;
int vv,ee;
struct node
{
    int to;
    int w;
    int next;
};

node edge[maxn];
int head[maxn];
bool vis[maxn];

//����
void dfs(int x)
{
    vis[x] = 1;
    cout << x << endl;
    for(int k = head[x]; k != -1; k = edge[k].next)
    {
        if(!vis[edge[k].to])
            dfs(edge[k].to);
    }
}

int main()
{
    int x, y,z ;
    cin >> vv >> ee;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    for(int i = 0 ; i < ee; i++)
    {
        cin >> x >> y >> z;
        edge[i].to = y;
        edge[i].w = z;
        edge[i].next = head[x];
        head[x] = i;
    }
    dfs(0);
    return 0;
}

```
