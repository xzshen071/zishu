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
	
	//������д渡��������M x 2^E��M��β����E�ǽ��룬��󸡵����е�M��9������ʮ������16λ�����Ը��������ֻ�ܱ���16λС�� 
	//ö�ٴ��(����)��һ���������ʾ�ķ�Χ���Ϳ����ô˷��� 
	for(int m=0;m<=9;m++){
		for(int e=1;e<=30;e++){
			//b=1-2^(-1-i)��c=2^j-1��a*2^c=A*10^B����߲��ᳬ�����ұ߿��ܻᳬ������ 
			//����lg����lg(b)+c*lg(2)=lg(A)+B�����ݿ�ѧ��������0<=A<10����0<lg(A)<1��С����,B�������� 
			double b=1-pow(2,-1-m);
			double c=pow(2,e)-1;
			a[m][e]=log10(b)+c*log10(2);
			
		}
	} 

	string s;
	const double min_diff = 1e-5;								//�������(double���Ͳ���int�ͣ�double�ʹ������)
	while(cin >> s && s[0] != '0'){
		//����AeB��ȡ��A��B��Ȼ����
		double A;
		int B;
		//scanf("%s",s);//��������� 
		for(int i=0;i<s.size();i++){
			if(s[i]=='e')
				s[i]=' ';								//�����A��B����Ϊscanf��������' '����'\n'ʱ��ͣ���� 
			
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
				if(fabs(a[m][e] - tmp) < min_diff){		//�����==�ᵼ�´�������Ϊdoule�ʹ������
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
