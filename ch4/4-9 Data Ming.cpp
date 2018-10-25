#include<stdio.h>
#include<math.h>
int main(){
	//读n，Sp，Sq
	//int n,Sp,Sq;//出错 
	long long n,Sp,Sq;
	scanf("%d%d%d",&n,&Sp,&Sq); 
	//由题目，A与B的最大值应为：Maxn*MaxSq的次数，即20+10=30，枚举法求解即可
	int A,B,minB,minA;
	unsigned long long k,mink=pow(2,60); 
	//printf("%lld\n",mink);
	for(A=0;A<31;A++){
		for(B=0;B<31;B++){
			//Q数组最后一个的前一个元素偏移量+最后一个元素的大小 
			k=(((n-1)*Sp+(((n-1)*Sp)<<A))>>B)+Sq;//左右移运算符比+-*/低 
			//printf("%d\n",k); 
			//判断条件：k要比n*Sq要大(可能溢出变负数)，和找到最小的k 
			//n*Sq，如果n和Sq都是int型，得到的也是int型，可能会超出范围，产生错误 
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
