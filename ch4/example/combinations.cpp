#include<stdio.h>
#include<math.h>
//��������� 
//��д����׳˵��Ӻ���
/* 
//������� 
long long jiecheng(unsigned int n){
	long long result=1;//����
	//��׳� 
	for(int i=1;i<=n;i++){
		result*=i; 
		
	} 
	return result;
} 
long long zuheshu(unsigned int n,unsigned int m){
	printf("%ld\n",jiecheng(n));//����� 
	printf("%ld\n",jiecheng(m)); 
	printf("%ld\n",jiecheng(n-m));//Ҳ����� 
	return jiecheng(n)/(jiecheng(m)*jiecheng(n-m));
	
}
*/
//���򣬶Ը��Ӷȶ���ʽ���л�����ʱ�����ܼ��������������ܱ����м�Ľ����� 
long long zuheshu(unsigned int n,unsigned int m){
	long long result=1;
	if(m<n-m) 
		m=n-m;//���ϴ����Ľ׳ˣ����ܷ����
	//n!/m!=n*(n-1)*...*(m+2)*(m+1)
	for(int i=m+1;i<=n;i++) 
		result*=i;
	//(n!/m!)/(n-m)!����m=n-m������n-m=m���պ��滻
	for(int j=n-m;j>0;j--)
		result/=j;
	return result; 
} 

 
int main(){
	printf("%ld\n",zuheshu(25,12));
	return 0;
}
