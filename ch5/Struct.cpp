#include<iostream>
using namespace std;

//������C������typedef������ֱ���ýṹ����ֱ����Point 
struct Point{
	int x,y;
	/* 
	1���ڽṹ���ж��壬ֻ�к�������û�з���ֵ�������ĺ����ǹ��캯���� 
	2������Point�Ǻ���ֵ�����캯������������ʱ���ã�int x=0,int y=0˵��x=0,y=0ʱĬ��ֵ����û��ָ�����ǵ�ֵ����Ĭ��Ϊ0��
	3��:x(x),y(y)�Ǽ�д����������Ա����x��ʼ��Ϊ����x����Ա����y��ʼ������y���˺����൱��
	Point(int x=0,int y=0){
		this->x=x;//(*this).x��thisָ��ǰ�����ָ�� 
		this->y=y; 
		
	}
	4���ṹ������ж�����캯��	 
	*/
	Point(int x=0,int y=0):x(x),y(y){}
}; 
//Ϊ����ṹ�嶨��ӷ�������ʵ�����õ����캯��������������a+b����ʽ���������ṹ��a��b��"��"�� 
Point operator + (const Point& A,const Point& B){
	return Point(A.x+B.x,A.y+B.y);
}
//��������ṹ����������ʽ��Ȼ�������cout << p�����һ��Point�ṹ��p�� 
ostream& operator << (ostream &out,const Point& p){
	out << "(" << p.x << "," << p.y << ")";
	return out; 
} 

int main(){
	//�ṹ����Ĺ��캯��״̬��a:Point(0,0); b:Point(1,2)
	Point a,b(1,2);
	a.x=3;
	cout << a+b << "\n";
	
	
	return 0;
}

//�Ľ�sum���� 
/*
ԭ����sum������
int sum(int *begin,int *end){
	int *p=begin;//beginΪָ�룬��ֵ��ָ��p 
	int ans=0;
	for(int *p=begin;p!=end;p++){
		ans+=*p;
	
	}
	return ans;

} 
ȱ�㣺ֻ�ܼ�����������ĺͣ�������doube����ĺͣ���������Point���� 

*/ 
/* 
//�Ľ�
#include<iostream>
using namespace std;
//����һ��ģ�壬����������͵ı������� 
template<typename T>
T sum(T *begin,T *end){
	T *p=begin;
	T ans=0;
	for(T *p=begin;p!=end;p++){
		ans=ans+*p;//��ô����ԭ����Point�ṹ��ֻ�����ˡ�+����û�ж��塰+=�� 
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
//��template<typename T>ģ�崦��ṹ��Point�в�ͬ���͵ı���
template<typename T>
struct Point{
	T x,y;
	Point(T x=0,T y=0):x(x),y(y){}
}; 
//ע����Point<T> 
template<typename T>
Point<T> operator + (const Point<T>& A,const Point<T>& B){
	return Point<T>(A.x+B.x,A.y+B.y);
}
//��������Ĳ��ֶ�Ҫ�� 
template<typename T>
ostream& operator << (ostream &out,const Point<T>& p){
	out << "(" << p.x << "," << p.y << ")";
	return out; 
}
//��ʱ����ͬʱʹ��int��doule�͵�Point��
int main(){
	Point<int> a(1,2),b(3,4);
	Point<double> c(1.1,2.2),d(3.3,4.4);
	cout << a+b << " " << c+d << "\n"; 
	return 0;  
	
} 
*/

