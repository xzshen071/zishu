#include<stdio.h>
#include<math.h>
//#include<iostream>
//using namespace std;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//��n��Sp��Sq
	//int n,Sp,Sq;//���� 
	long long n,Sp,Sq;
	//ע��scanf��printf��Ҫ�������������ͣ������׵��´�����Ҳ����cin��cout�����ƣ�����ע���������ͣ� 
	while(scanf("%lld%lld%lld",&n,&Sp,&Sq) == 3) {
		//����Ŀ��A��B�����ֵӦΪ��Maxn*MaxSq�Ĵ�������20+10=30��ö�ٷ���⼴��
		long long A,B,minB,minA,k,mink;		//���߸�ֵ�ͱȽϵı����������һ�� 
		mink=pow(2,60); 
		for(A=0;A<32;A++){
			for(B=0;B<32;B++){
				//Q�������һ����ǰһ��Ԫ��ƫ����+���һ��Ԫ�صĴ�С 
				k=(((n-1)*Sp+(((n-1)*Sp)<<A))>>B)+Sq;//�������������+-*/�� 
				//printf("%d\n",k); 
				//�ж�������kҪ��n*SqҪ��(��������为��)�����ҵ���С��k 
				//n*Sq�����n��Sq����int�ͣ��õ���Ҳ��int�ͣ����ܻᳬ����Χ���������� 
				if(k>=n*Sq && k<mink){
					mink=k;
					minA=A;
					minB=B;
				}
			}
		} 
		printf("%lld %lld %lld\n",mink,minA,minB);
		//cout << mink << " " << minA << " " << minB << endl;	
	}
	return 0;
} 
