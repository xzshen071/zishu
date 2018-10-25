//题目操作的对象是集合，然后集合里面可以包括集合，但是这样不行，只能拿编号代替集合，这就要确定某个集合对应着哪一个编号，知道编号也得确定对应的是那个集合 
#include<iostream>
#include<vector>
#include<set>
#include<map> 
#include<stack> 
#include<string>
#include<algorithm>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;

 
typedef set<int> Set;
map<Set,int> IDcache;//把集合映射为ID
vector<Set> Setcache;//根据ID取集合 
//查找给定集合x的ID。如果找不到，分配一个新ID
int ID(Set x){
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);//添加新集合 
	return IDcache[x]=Setcache.size()-1;	
	
} 
int main(){
	stack<int> s;//题目中的栈
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string op;
		cin >> op;
		if(op[0]=='P') s.push(ID(Set()));
		else if(op[0]=='D') s.push(s.top());
		else{
			Set x1=Setcache[s.top()]; s.pop();
			Set x2=Setcache[s.top()]; s.pop();
			Set x;
			if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
			if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
			if(op[0]=='A'){ x=x2; x.insert(ID(x1)); }
			s.push(ID(x));
			
		}
		cout << Setcache[s.top()].size() << endl;
		
	} 
	
	
	
	return 0;
}
