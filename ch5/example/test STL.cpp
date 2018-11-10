/*
	库不一定没有bug，使用之前测试库是一个好习惯。 
	
*/ 
//测试程序 
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cassert>//#include<assert.h>
#include<ctime>
using namespace std;
/*
int main(){
	int a[]={3,2,4};
	sort(a,a+3);
	cout << a[0] <<" " << a[1] << " " << a[2] <<"\n";
} 
*/
/*
	问题：测试程序太简单，说明不了问题。应该写一个更加通用的程序，随机生成很多整数，然后排序。
	生成随机数：
	1、核心函数时cstdlib中的rand()，它生成一个闭区间[0,RAND_MAX]内的均与的随机整数，其中RAND_MAX至少为32727（2^15-1），在不同环境可能不同；
	2、如何产生[0,n]之间的整数：
		(1)执行rand()后先除RAND_MAX，得到[0,1]之间的随机整数； 
		(2)扩大n倍后四舍五入得到[0,n]之间的均匀整数，当n很大的时候“精度”不好，但是对于普通应用，这样做已经足够满足要求了
	
	3、需要随机数的程序在一开始时一般会执行一次srand(time(NULL))，目的时初始化“随机数种子”，因为种子相同，计算出来的“随机数”序列总是相同；
	4、如果需要程序每次执行时使用一个不同的种子，只需在程序执行的开头条用一次srand（不要同一程序每次生成随机数之前都重新调用一次srand）； 
	
	5、srand(time(NULL))来自UTC时间1970年1月1日0点以来经过的“秒数”；因此每秒才变化一次，程序相隔是时间段可能会导致得到相同的随机数；
	6、解决办法：在测试程序的主函数中设置一个循环，做足够多的测试后再退出。
	
	7、不同的编译器编译出来的程序，即使是使用相同的参数调用srand也可能产生不同的司机序列 
*/ 
//随机程序
void fill_random_int(vector<int> &v,int cnt){
	//srand(time(NULL));//srand只执行了一次（答案正确） 
	v.clear();
	for(int i=0;i<cnt;i++){
		//srand(time(NULL));//每一次产生的随机数都相同，srand不能放在这，不需要每次用rand()都用一次srand() 
		v.push_back(rand());
	}

}
//用v作为返回值
vector<int> fill_random_int(int cnt){
	vector<int> v;
	for(int i=0;i<cnt;i++)
		v.push_back(rand());
	
	return v;//缺点：局部变量v中的元素需要逐个赋值给调用者 
} 
/*
	1、vector作为参数或者返回值的时候，应该尽量改成引用的方式传递参数，以避免不必要的值被复制；
	2、C++支持函数重载，但函数的参数类型（传递参数）必须不同（不能止呕返回值的类型不同）。 
	
*/
//测试sort函数 
void test_sort(vector<int> &v){//避免vector复制 
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++){
		//测试中常常使用 
		assert(v[i] <= v[i+1]);//assert宏，用法：assert(表达式)，作用是：当表达式为真时无变化，为假时强行终止程序，并且给出错误提示 
	}
	/*
		//可用下面的代码代替
		if((v[i] <= v[i+1]){
			printf("Error: v[i]>v[i+1]!\n");
			about();
		
		} 
	 
	*/ 
	
}
//主函数
int main(){
	//srand(time(NULL));//srand只执行了一次（答案正确） 
	
	vector<int> v;
	fill_random_int(v,10000000);
	test_sort(v);
	
/* 	
	//测试srand 
	for(int i=0;i<10;i++){
		printf("%d ",v[i]);
		 
	}
	printf("\n");
*/ 
	return 0;	
}
/*
	vector、map和set都很快：
		(1) vector的速度接近数组（但仍然有差距）； 
		(2) set和map的速度也远远超过了“用一个vector保存所有值，然后逐个元素进行查找”； 
		(3) set和map每次插入、查找和删除时间和元素个数的对数（log）呈线性关系；
		(4) 尽管如此，对于时间要求非常高的题目中，STL有时会成为性能瓶颈。 


*/
