#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main(){
	
	int sum = 0;
	
	for(int a = 0 ; a <= 9 ; a++){
		for(int b = 0 ; b <= 9 ; b++){
			if(b == a && abs(b-a) == 1)continue;
				for(int c = 0 ; c <= 9 ; c++){
					if(c == b || c == a || abs(c-b) == 1)continue;
					for(int d = 0 ; d <= 9 ; d++){
						if(d == a || d == b || d == c || abs(d-a) == 1 || abs(d-e) == 1)continue;
						for(int e = 0 ; e <= 9 ; e++){
							if(e == a || e == b || e == c || e == d || abs(e-a) == 1 || abs(e-d) == 1 || abs(e-b) == 1)continue;
							for(int f = 0; f <= 9 ; f++){
								if(f == a || f == b || f == c || f == d || f == e || abs(f-a) == 1
								|| abs(f-b) == 1|| abs(f-c) == 1|| abs(f-e) == 1)continue;
								for(int g = 0 ; g <= 9 ; g++){
									if(g == a || g == b || g == c || g == d || g == e || g == f || abs(g-b) == 1
									|| abs(g-c) == 1|| abs(g-f) == 1)continue;
									for(int h = 0 ; h <= 9 ; h++){
										if(h == a || h == b || h == c || h == d || h == e || h == f || h == g
										|| abs(h-d) == 1|| abs(h-e) == 1)continue;
										for(int i = 0 ; i <= 9 ; i++){
											if(i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h
											|| abs(i-f) == 1|| abs(i-e) == 1|| abs(i-d) == 1|| abs(i-h) == 1)continue;
											for(int j = 0 ; j <= 9 ; j++){
												if(j == a || j == b || j == c || j == d || j == e || j == f || j == g || j == h
												|| j == i || abs(j-g) == 1|| abs(j-f) == 1|| abs(j-e) == 1|| abs(j-i) == 1)continue;
												sum++;
											}
										}
									}
								}
							}
						}
					}
			}
			
		}
	}
	
	cout << sum << endl;
	
	return 0;
} 

