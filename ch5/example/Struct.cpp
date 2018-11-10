#include<iostream>
using namespace std;

//不用像C语言用typedef，可以直接用结构体名直接是Point 
struct Point{
	int x,y;
	/* 
	1、在结构体中定义，只有函数名，没有返回值，这样的函数是构造函数。 
	2、其中Point是函数值，构造函数在声明变量时调用；int x=0,int y=0说明x=0,y=0时默认值，即没有指明它们的值，则默认为0。
	3、:x(x),y(y)是简单写法，即将成员变量x初始化为参数x，成员变量y初始化参数y。此函数相当于
	Point(int x=0,int y=0){
		this->x=x;//(*this).x，this指向当前对象的指针 
		this->y=y; 
		
	}
	4、结构体可以有多个构造函数	 
	*/
	Point(int x=0,int y=0):x(x),y(y){}
}; 
//为这个结构体定义加法，并在实现中用到构造函数，这样可以用a+b的形式计算两个结构体a和b的"和"。 
Point operator + (const Point& A,const Point& B){
	return Point(A.x+B.x,A.y+B.y);
}
//定义这个结构体的流输出方式，然后可以用cout << p来输出一个Point结构体p。 
ostream& operator << (ostream &out,const Point& p){
	out << "(" << p.x << "," << p.y << ")";
	return out; 
} 

int main(){
	//结构体里的构造函数状态：a:Point(0,0); b:Point(1,2)
	Point a,b(1,2);
	a.x=3;
	cout << a+b << "\n";
	
	
	return 0;
}

//改进sum函数 
/*
原来的sum函数：
int sum(int *begin,int *end){
	int *p=begin;//begin为指针，赋值给指针p 
	int ans=0;
	for(int *p=begin;p!=end;p++){
		ans+=*p;
	
	}
	return ans;

} 
缺点：只能计算整数数组的和，不能求doube数组的和，更不能求Point数组 

*/ 
/* 
//改进
#include<iostream>
using namespace std;
//这是一个模板，方便各种类型的变量处理 
template<typename T>
T sum(T *begin,T *end){
	T *p=begin;
	T ans=0;
	for(T *p=begin;p!=end;p++){
		ans=ans+*p;//这么做的原因是Point结构体只定义了“+”，没有定义“+=” 
	}
	return ans;
} 
int main(){
	double a[]={1.1,2.2,3.3,4.4};
	cout << sum(a,a+4) << "\n";
	Point b[]={Point(1,2),Point(3,4),Point(5,6),Point(7,8)};
	cout << sum(b,b+4) << "\n";
	return 0;
	
} 
*/ 

/*
//用template<typename T>模板处理结构体Point中不同类型的变量
template<typename T>
struct Point{
	T x,y;
	Point(T x=0,T y=0):x(x),y(y){}
}; 
//注意是Point<T> 
template<typename T>
Point<T> operator + (const Point<T>& A,const Point<T>& B){
	return Point<T>(A.x+B.x,A.y+B.y);
}
//定义操作的部分都要用 
template<typename T>
ostream& operator << (ostream &out,const Point<T>& p){
	out << "(" << p.x << "," << p.y << ")";
	return out; 
}
//此时可以同时使用int、doule型的Point了
int main(){
	Point<int> a(1,2),b(3,4);
	Point<double> c(1.1,2.2),d(3.3,4.4);
	cout << a+b << " " << c+d << "\n"; 
	return 0;  
	
} 
*/

