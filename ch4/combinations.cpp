#include<stdio.h>
#include<math.h>
//计算组合数 
//编写计算阶乘的子函数
/* 
//结果不对 
long long jiecheng(unsigned int n){
	long long result=1;//存结果
	//算阶乘 
	for(int i=1;i<=n;i++){
		result*=i; 
		
	} 
	return result;
} 
long long zuheshu(unsigned int n,unsigned int m){
	printf("%ld\n",jiecheng(n));//溢出了 
	printf("%ld\n",jiecheng(m)); 
	printf("%ld\n",jiecheng(n-m));//也溢出了 
	return jiecheng(n)/(jiecheng(m)*jiecheng(n-m));
	
}
*/
//化简，对复杂度额表达式进行化间有时不仅能减少运算量，还能避免中间的结果溢出 
long long zuheshu(unsigned int n,unsigned int m){
	long long result=1;
	if(m<n-m) 
		m=n-m;//除较大数的阶乘，更能防溢出
	//n!/m!=n*(n-1)*...*(m+2)*(m+1)
	for(int i=m+1;i<=n;i++) 
		result*=i;
	//(n!/m!)/(n-m)!，若m=n-m，则是n-m=m，刚好替换
	for(int j=n-m;j>0;j--)
		result/=j;
	return result; 
} 

 
int main(){
	printf("%ld\n",zuheshu(25,12));
	return 0;
}
