//C++�ض���ͷ�ļ� 
#include<iostream>//�ṩ��������� 
#include<algorithm>//�ṩ���õ��㷨����min 
//C++�п���ʹ���������������������׼�����������ͷ�ļ�iostream�ж��壬���������ƿռ�std�У����ж�����ƿռ䣩�����ʹ��using namespace std����ֱ��ʹ�á� 
using namespace std;
const int maxn=100+10;
//�����С����ʹ��const�����ĳ��� 
int A[maxn];
int main(){
	long long a,b;
	
	while(cin >> a >> b){
		cout<<min(a,b)<<"\n";
	}
	//��ע�͵�using namespace std�����汨��������γ���������Ч����ͬ�� 
	/*
	while(std::cin >> a >> b){
		std::cout<<std::min(a,b)<<"\n";
	}
	*/
	return 0;
} 
//C++�����C����bool���� 
