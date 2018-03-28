#include <bits/stdc++.h>

//find a solution : cnt = sqrt(m) * sqrt(n) and ji * ji = ji
//������ˣ�����������
 
using namespace std;

string strMultiply(string str1,string str2){
	string strResult = "";
	int len1 = str1.length();
	int len2 = str2.length();
	int num[500] = {0};
	int i = 0 , j = 0 ;
	for(i = 0; i <len1; i++){
		for(j = 0;j < len2; j++){
			num[len1-1-i+len2-1-j] += (str1[i]-'0') * (str2[j]-'0');//���ﵱʱд���˲������� i str1[i] str2[j] 
		}
	}
	for(i = 0 ; i < len1+len2; i++){
		if(num[i] >= 10){
			num[i+1] += num[i]/10;
			num[i] %= 10; 
		}
	}
	for(i = len1+len2-1; i>= 0; i--){
		if(num[i] != 0)break;	
	}
	
	for(j = i ; j >= 0; j--){
		strResult += num[j] + '0';
	}
	return strResult;	
} 

//��� pos �� 0 Ȼ�������Ƚ� 
int compare(string str1,string str2,int pos){
	int len1 = str1.length();
	int len2 = str2.length();
	if(len2 > len1 + pos)return 0;
	if(len2 < len1 + pos)return 1;
	int i = 0;
	for(i = 0; i < len2; i++){
		if(str1[i]-'0'>str2[i]-'0')return 1;
		if(str1[i]-'0'<str2[i]-'0')return 0;
	}
	return 0;
}
// ������Ƚϴ�Ļ������ܻ���ֲ��ó��ֵ� ���� �� /
 
string sqrtLarge(string str){
	int len = str.length();
	int i = 0, j = 0;
	string strResult = "";
	string str1 = "";
	
	if(0 == len % 2)  
    {         //Ϊż��λ  
        for(i = 0; i < len/2; i++)
        {  
            for(j = 0; j < 10; j++)  
            {  
                str1 = strResult;  
                str1 += j + '0';  
                if(1 == compare(strMultiply(str1, str1) , str , 2*(len/2-i-1)) )  
                {         //����str1������len/2-i-1��0������ƽ���Ժ�����2*(len/2-i-1)��  
                    strResult +=  j-1 + '0';
                    break;  
                }  
                if(9 == j) strResult += '9';  
            }  
        }  
    }
    else  
    {       //Ϊ����λ  
        for(i = 0; i < len/2+1; i++)  
        {  
            for(j = 0; j < 10; j++)  
            {  
                str1 = strResult;  
                str1 += j + '0';  
                if(1 == compare(strMultiply(str1, str1) , str , 2*(len/2-i)) )  
                {  
                    strResult +=  j-1 + '0';
                    break;  
                }  
                if(9 == j) strResult += '9';  
            }  
        }  
    }  
    return strResult;  
}

int main(){
	string str1;
	string str2;
//	string strResult;
	cin >> str1 >> str2;
	cout << strMultiply(sqrtLarge(str1),sqrtLarge(str2)) << endl;
		
	return 0;
} 
//test
//979 938
//930
