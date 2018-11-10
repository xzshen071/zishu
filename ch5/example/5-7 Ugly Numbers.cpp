/*
	1、用优先队列保存已经生成的丑数，因为对于任何丑数x，2x，3x，5x都是丑数，即优先队列弹出一个丑数，就对其进行乘2、3、5的操作；
	2、不过要注意一个丑数可能由多种方式生成，用集合set存生成的不重复的丑数（因为set会按从小到大排序）
	 
*/ 
#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;//丑数可能超过int的范围 
priority_queue<LL,vector<LL>,greater<LL> > pq;
set<LL> s; 
const int coeff[3]={2,3,5};//系数 

int main(){
	//初始化，输入第一个丑数，1
	pq.push(1);//stack、queue类型push，vector类型push_back() 
	s.insert(1);//set类型用insert()
	for(int i=1;;i++){//从1开始，因为丑数1算一个 
		LL x =pq.top(); pq.pop();//从优先队列弹出一个丑数
		if(i==1500){
			cout << "The 1500'th ugly number is "<< x << ".\n";
			break;
			
		}
		for(int j=0;j<3;j++){
			LL x2 =x*coeff[j];
			if(!s.count(x2)){ s.insert(x2); pq.push(x2);}//set里可以用set.count(x)知道某个元素的个数 
			
		} 
		
		
	}
	
	return 0;
	
} 
