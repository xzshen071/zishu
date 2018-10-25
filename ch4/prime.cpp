#include<stdio.h>
#include<math.h> 
//素数只能被1和自己整除
/* 
//也可返回int类型，0和1分别代表false与true 
bool Is_prime(int n){
	//要考虑n如果为1时的特殊情况
	if(n==1)
		return false; 
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
					
		}

	}
	return true;

	
} 
*/ 
//书上的程序
/* 
//n太大时勿用
//原因n如果接近int类型的最大值，那么i++后，i*i可能会超出int类型的最大值，变成负数，导致程序运行错误 
int Is_prime(int n){
	if(n=1)
		return 0;
	//为什么这考虑平方根：（可以减少运算量） 
	//因为如果它不是质数，那么它一定可以表示成两个数（除了1和它本身）相乘，这两个数必然有一个小于等于它的平方根。只要找到小于或等于的那个就行了 
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
} 
*/ 
//改进 
//如果输入的参数是long long型的不能很快的计算出答案，得用其他方式 
int Is_prime(int n){
	if(n=1)
		return 0;
	//那么就让他不计算i*i就行
	int m=floor(sqrt(n)+0.5);//sqrt(n)后是浮点数，浮点数不准确，得通过四舍五入避免浮点误差 
	for(int i=2;i<=m;i++)
		if(n%i==0)
			return 0;
	return 1;
} 

int main(){
	if(Is_prime(2147483647))
		printf("Yes\n");
	else 
		printf("No\n");	
	return 0;
} 
