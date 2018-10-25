#include<stdio.h>
/* 
//参数交换 
void swap(int a,int b){
	int t=a;
	a=b;
	b=t;
	
	return;
} 
int main(){
	int a=3,b=4;
	swap(a,b);
	printf("%d %d\n",a,b);
	
	return 0;
} 
//结果：3 4
/* 
结论：
1、实参和形参：swap(a,b)中因为a=3,b=4,所以3，4是实参，而函数声明中的a,b是形参（调用实参给形参） 
2、两个函数中有相同的变量不会混淆，因为都是局部变量
3、局部变量和全局变量：局部变量的空间是临时分配的，函数执行完毕时，空间会被释放（调用完swap函数，函数中的a,b变量被释放）；
   全局变量声明在函数外，可以在任何时候，被任何函数访问。（谨慎使用）
 
*/
 //用指针进行传递，则可以改变变量的值，因为指针指向变量的地址（每个变量第一个字节的地址） 
 //*a代表“a指向的变量”，而不仅是“a指向的变量所拥有的值”，例如*a=*a+1，就是a指向的变量自增1，可以写成(*a)++，但不能是*a++，因为++优先级>*  
void swap(int* a,int* b){//int* a是指向int型变量的指针。a=&b是指把变量b的地址存在指针a中 。注意：不能滥用指针，容易出现各种奇怪的错误 
	int t=*a;
	*a=*b;
	*b=t;
	return; 
}
//在进行gdb调试的时候，要运行程序，才能由栈帧的信息，我们是运行到return，所以栈帧的信息指的是此时此刻的信息 
int main(){
	int a=3,b=4;
	swap(&a,&b);//变量名前加&，得到的则是变量的地址
	printf("%d %d\n",a,b);
	
	//int* t=0;
	//*t=10;
	//printf("&d\n",*t);//没有输出，说明*t不能写，则指针赋值得是一个确定的值，如果它是只读的会导致程序奔溃 
	return 0;
}
