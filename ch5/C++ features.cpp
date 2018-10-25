//C++特定的头文件 
#include<iostream>//提供输入输出流 
#include<algorithm>//提供常用的算法，如min 
//C++中可以使用流简化输入输出操作。标准输入输出流在头文件iostream中定义，存在于名称空间std中（可有多个名称空间）。如果使用using namespace std，可直接使用。 
using namespace std;
const int maxn=100+10;
//数组大小可以使用const声明的常数 
int A[maxn];
int main(){
	long long a,b;
	
	while(cin >> a >> b){
		cout<<min(a,b)<<"\n";
	}
	//若注释掉using namespace std，上面报错，下面这段程序与上面效果相同。 
	/*
	while(std::cin >> a >> b){
		std::cout<<std::min(a,b)<<"\n";
	}
	*/
	return 0;
} 
//C++相对与C多了bool类型 
