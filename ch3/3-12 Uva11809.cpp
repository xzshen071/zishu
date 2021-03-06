#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

const int maxn=35;
double a[maxn][maxn];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	//计算机中存浮点数则是M x 2^E，M是尾数，E是阶码，最大浮点数中的M是9，换成十进制是16位，所以浮点数最多只能保留16位小数 
	//枚举打表(反推)，一般给你结果表示的范围，就可以用此方法 
	for(int m=0;m<=9;m++){
		for(int e=1;e<=30;e++){
			//b=1-2^(-1-i)；c=2^j-1；a*2^c=A*10^B，左边不会超，但右边可能会超出上限 
			//改用lg，则lg(b)+c*lg(2)=lg(A)+B，根据科学记数法，0<=A<10，则0<lg(A)<1（小数）,B则是整数 
			double b=1-pow(2,-1-m);
			double c=pow(2,e)-1;
			a[m][e]=log10(b)+c*log10(2);
			
		}
	} 

	string s;
	const double min_diff = 1e-5;								//设置误差(double类型不像int型，double型存在误差)
	while(cin >> s && s[0] != '0'){
		//输入AeB，取出A，B，然后查表
		double A;
		int B;
		//scanf("%s",s);//先用数组存 
		for(int i=0;i<s.size();i++){
			if(s[i]=='e')
				s[i]=' ';								//方便读A和B，因为scanf函数读到' '或者'\n'时会停下来 
			
		}
		stringstream ss(s);
		ss >> A >> B;
		//cout << A << " " << B << endl;
		//if(A==0 && B==0)
			//break;
		double tmp=log10(A)+B;
		int m,e;
		int flag = 0;
		for(m=0;m<=9;m++){
			for(e=1;e<=30;e++){
				if(fabs(a[m][e] - tmp) < min_diff){		//如果用==会导致答案有误，因为doule型存在误差
					flag = 1;
					break;
				} 	
			}
			if(flag)
				break;
		}
		printf("%d %d\n",m,e);
		
	}
	
	return 0;
}
