#include<stdio.h>
#include<math.h>
//#include<iostream>
//using namespace std;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//读n，Sp，Sq
	//int n,Sp,Sq;//出错 
	long long n,Sp,Sq;
	//注意scanf和printf需要输入和输出的类型，很容易导致错误，这也就是cin和cout的优势（不用注意数据类型） 
	while(scanf("%lld%lld%lld",&n,&Sp,&Sq) == 3) {
		//由题目，A与B的最大值应为：Maxn*MaxSq的次数，即20+10=30，枚举法求解即可
		long long A,B,minB,minA,k,mink;		//两边赋值和比较的变量类型最好一样 
		mink=pow(2,60); 
		for(A=0;A<32;A++){
			for(B=0;B<32;B++){
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
		printf("%lld %lld %lld\n",mink,minA,minB);
		//cout << mink << " " << minA << " " << minB << endl;	
	}
	return 0;
} 
