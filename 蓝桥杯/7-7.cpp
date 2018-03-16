//#include <iostream>
//
//using namespace std;
//
//struct node
//{
//	int zhengshu;
//	int up,down;
//	void yuefen(){
//		int t = gcd(i,j);
//		up /= t;
//		down /= t;
//	}
//	node(int i, int j){
//		int t = gcd(i,j);
//		up = i/t;
//		down = j/t;
//		getzhengshu();
//	}	
//	void getzhengshu(){
//		while(up > down){
//			zhengshu++;
//			up -= down;
//		}
//	}
//	void output()
//	{
//		if(zhengshu != 0 && up != 0)
//		cout << zhengshu << " " << up << "/" << down << endl;
//		else if(zhengshu == 0)
//		cout << up << "/" << down << endl;
//		else if(zhengshu != 0 && up == 0)
//		cout << zhengshu << endl;
//	}	
//	int gcd(int l, int r){
//		return r == 0 ? l : gcd(r%l,l);
//	}
//	void add(node tt){
//		down = down*tt.down;
//		up = up * tt.down + down * tt.up;
//		yuefen();
//		getzhengshu();
//		output();
//	}
//	void sub(node tt){
//		down= down * tt.down;
//		up = up*tt.down - down * tt.up;
//		yuefen();
//		getzhengshu();
//		output();
//	}
//}
//
//char target[1000];
//
//int main(){
//	int n;
//	cin >> n;
//	cin >> target;
//	int len = strlen(target);
//	int aa,bb;
//	for(int i = 0 ; i < len ; i++){
//		
//	}
//	
//	
//	return 0;
//}



#include <stdio.h>
#include <iostream>

using namespace std;

long long gcd(long long a,long long b)//�����Լ����
{
	return b == 0 ? a : gcd(b,a%b); 
}

int main()
{
    int N;
    long long lcp;//���Լ�¼��С������
    long long a,b,c,d;
    int i = 1;
    scanf("%d",&N);
    scanf("%lld/%lld",&a,&b);
    int t0 = gcd(a,b);
    if(a)
    {
        a /= t0;
        b /= t0;
    }

    while(i < N)
    {
        scanf("%lld/%lld",&c,&d);
        lcp = b / gcd(b,d) * d;//ͨ�����Լ�������������ĸ����С������
        a = a * lcp / b + c * lcp / d;//ͨ�ֺ���Ӻ�
        b = lcp;
        int t0 = gcd(a,b);
        if(t0 != 0)//��������С������֮�����ʽ�任����
        {
            a = a / t0;
            b = b / t0;
        }
        i++;
    }
    if(a && a/b == 0)/// ��������Ϊ0 �� a��Ϊ 0
        printf("%lld/%lld\n",a%b,b);
    else if(a%b == 0)/// С������Ϊ0
        printf("%lld\n",a/b);
    else
        printf("%lld %lld/%lld\n",a/b,a%b,b);
    return 0;
}

