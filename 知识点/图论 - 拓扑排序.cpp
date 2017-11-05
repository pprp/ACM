### ��������
#### writer��pprp

#### ������
����һ�����У����������Ϊ0�Ľڵ�ŵ�������

����ýڵ㣬������������������������

�ٴν����и��½ڵ������Ϊ0�ĵ�������
#### �㷨˼·��
ÿ��ѡȡһ�����Ϊ0�ĵ㣬����Ӹ�ͼ��ɾ�����ٰ������ϲ����������ɾ�����������ɾ����ô˵�����ڻ�״�ṹ����û�����Ϊ0�ĵ㣬��ÿ��ɾ���ĵ��¼��һ��vector�����У����������

#### �������£�


```
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
//ͼ����������
using namespace std;
const int maxn = 1000;
int vv,ee;
struct node
{
    int to;
    int w;
    int next;
};
queue <int> qu;

node edge[maxn];
int head[maxn];
int indegree[maxn];
/*
@declare��
����һ�����У����������Ϊ0�Ľڵ�ŵ�������
����ýڵ㣬������������������������
�ٴν����и��½ڵ������Ϊ0�ĵ�������
*/
vector <int> vt;
void dfs()
{
    int cnt = 0;
    for(int i = 0 ; i < vv ; i++)
        if(indegree[i] == 0)
        qu.push(i), vt.push_back(i);

    while(!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for(int k = head[x]; k != -1 ; k = edge[k].next)
        {
            indegree[edge[k].to]--;
            if(indegree[edge[k].to] == 0)
            {
                qu.push(edge[k].to);
                vt.push_back(edge[k].to);
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int x, y,z ;
    cin >> vv >> ee;
    memset(head,-1,sizeof(head));
    memset(indegree,0,sizeof(indegree));
    for(int i = 0 ; i < ee; i++)
    {
        cin >> x >> y >> z;
        edge[i].to = y;
        edge[i].w = z;
        edge[i].next = head[x];
        head[x] = i;
        indegree[y]++;
    }
    dfs();
    for(int i = 0; i < vt.size(); i++)
        cout << vt[i] << " ";
    cout << endl;

    return 0;
}

/*
9 8
0 1 1
0 2 1
0 3 1
1 4 1
2 5 1
2 6 1
3 7 1
3 8 1
*/

```
