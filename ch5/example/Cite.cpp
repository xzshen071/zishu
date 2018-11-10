#include<iostream>
using namespace std;
//交换 
//在参数名之前加一个&，就表示这个参数按照传引用的方式传递，而不是C语言里的传值方式传递，这样在函数内改变参数的值，也会修改到函数的实参 
void swap2(int& a,int& b ){
	int t=a;
	a=b;
	b=t;
} 
int main(){
	int a=3,b=4;
	swap2(a,b);
	cout<<a<<' '<<b<<"\n";
	
	
	return 0;

}
//gcc调制没法运行
//C++中的引用就是变量的“别名”，它可以在一定程度上代替C中的指针。例如，可以用“传引用”的方式让函数内直接修改参数 
