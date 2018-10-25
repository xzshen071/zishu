#include<stdio.h>
#include<math.h>
#include<string.h>


int main(){
	//循环小数
	int a,b,rem,i;
	scanf("%d%d",&a,&b);
	int tmp=a/b;//整数部分
	printf("%d.",tmp);
	//把第一个余数算出来 
	a%=b;
	rem=a;
	a*=10;
	printf("%d",a/b);
	a%=b;
	for(i=1;a!=rem;i++){//除法模拟 
		a*=10;
		printf("%d",a/b);
		a%=b;
			
	}
	printf("\n%d\n",i);
	
	return 0;
}


