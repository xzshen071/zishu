/*
	1�������ȶ��б����Ѿ����ɵĳ�������Ϊ�����κγ���x��2x��3x��5x���ǳ����������ȶ��е���һ���������Ͷ�����г�2��3��5�Ĳ�����
	2������Ҫע��һ�����������ɶ��ַ�ʽ���ɣ��ü���set�����ɵĲ��ظ��ĳ�������Ϊset�ᰴ��С��������
	 
*/ 
#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;//�������ܳ���int�ķ�Χ 
priority_queue<LL,vector<LL>,greater<LL> > pq;
set<LL> s; 
const int coeff[3]={2,3,5};//ϵ�� 

int main(){
	//��ʼ���������һ��������1
	pq.push(1);//stack��queue����push��vector����push_back() 
	s.insert(1);//set������insert()
	for(int i=1;;i++){//��1��ʼ����Ϊ����1��һ�� 
		LL x =pq.top(); pq.pop();//�����ȶ��е���һ������
		if(i==1500){
			cout << "The 1500'th ugly number is "<< x << ".\n";
			break;
			
		}
		for(int j=0;j<3;j++){
			LL x2 =x*coeff[j];
			if(!s.count(x2)){ s.insert(x2); pq.push(x2);}//set�������set.count(x)֪��ĳ��Ԫ�صĸ��� 
			
		} 
		
		
	}
	
	return 0;
	
} 
