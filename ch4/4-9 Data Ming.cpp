#include<stdio.h>
#include<math.h>
int main(){
	//��n��Sp��Sq
	//int n,Sp,Sq;//���� 
	long long n,Sp,Sq;
	scanf("%d%d%d",&n,&Sp,&Sq); 
	//����Ŀ��A��B�����ֵӦΪ��Maxn*MaxSq�Ĵ�������20+10=30��ö�ٷ���⼴��
	int A,B,minB,minA;
	unsigned long long k,mink=pow(2,60); 
	//printf("%lld\n",mink);
	for(A=0;A<31;A++){
		for(B=0;B<31;B++){
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
	printf("%d %d %d\n",mink,minA,minB);
	
	
	return 0;
} 
