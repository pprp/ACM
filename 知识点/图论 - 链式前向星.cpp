#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
struct node
{
    int to;
    int w;
    int next;
};
int head[maxn];
node e[maxn];

int main()
{
    int vv, ee;
    int x, y, z;
    cin >> vv >> ee;
    memset(head,-1,sizeof(head));
    for(int i = 0 ; i < ee; i++)
    {
        //i�ǵڼ�����
        cin >> x >> y >> z;
        e[i].to = y;
        e[i].w = z;
        //��i������һ��ָ�����x��ָ��ı�
        e[i].next = head[x];
        //���xָ���i����
        head[x] = i;
    }
    for(int i = 0 ; i < vv; i++)
        cout << head[i] << ' ';
    cout << endl;
    for(int i = 0 ; i < ee; i++)
    {
        cout << i << ":" << e[i].to << " " << e[i].w << " " << e[i].next << endl;
    }
    for(int i = 0 ; i < vv; i++)
        for(int k = head[i]; k != -1 ; k = e[k].next)
            cout << "op:" << k << " ed:" << e[k].to << " w:" << e[k].w << endl;
    return 0;
}
