/*
@theme:�ֵ���ѧϰ�ʼ� - Сд��ĸ26
@writer��pprp
@begin:18:30
@end:
@declare:
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int MAX = 26;
struct Trie
{
    Trie * next[MAX];//�ж����������
    int v;//��¼���˴��ж�����ͬ��ǰ׺
    bool isStr;
    Trie()
    {
        for(int i = 0 ; i < MAX; i++)
            next[i] = NULL;
        v = 0;
        isStr = 0;
    }
};

Trie * root = new Trie;

//����һ���µĵ���
void insertTrie(Trie*root, const char *s)
{
    if(root == NULL || *s == '\0')
        return;
    Trie* p = root;
    while(*s != '\0')
    {
        //if not exist...
        if(p->next[*s-'a'] == NULL)
        {
            Trie * tmp = new Trie;
            p->next[*s-'a'] = tmp;
            p = p->next[*s-'a'];
        }
        //if exist...
        else
        {
            p = p->next[*s-'a'];
        }
        s++;
    }
    p->isStr = true;
    p->v++;
}

//����ĳһ�ַ���
bool searchTrie(char * str)
{
    int len = strlen(str);
    Trie *p = root;
    for(int i = 0 ; i < len ; i++)
    {
        int id = str[i] - 'a';
        p = p->next[id];
        if(p == NULL)//not exist
            return 0;
    }
    if(p->isStr == true)
    {
        cout << "times:" << p->v << endl;
        return 1;
    }
    return 0;
}

//ɾ���ռ�
void delTrie(Trie * R)
{
    if(R == NULL)
        return;
    for(int i = 0 ; i < MAX ; i++)
    {
        if(R->next[i] != NULL)
            delTrie(R->next[i]);
    }
    free(R);
    return ;
}

int main()
{
    freopen("in.txt","r",stdin);
    int num;
    scanf("%d",&num);
    getchar();
    char s[1000];
    for(int i = 0 ; i < num ; i++)
    {
        scanf("%s",s);
        insertTrie(root,s);
    }
    int query;
    scanf("%d",&query);
    getchar();
    while(query--)
    {
        scanf("%s",s);
        if(searchTrie(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    delTrie(root);
    return 0;
}
