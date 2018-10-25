#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<int, vector<int> > goal;
int n;
vector<int> sou;  //存学生原校 
bool is_sucess(map<int, vector<int> > m);
int main(){
	while(cin >> n && n != 0){
		sou.clear();
		goal.clear();
		//存学生信息，原学校编号和目标学校
		for(int i = 0; i < n; i++) {
			int loc,tar;
			cin >> loc >> tar;
			sou.push_back(loc);
			
			goal[loc].push_back(tar);							//原校所有学生映射在一个vector数组中 
				
		} 
		
		//原学校信息去重 
		sort(sou.begin(),sou.end());							//先排序 
    	sou.erase(unique(sou.begin(), sou.end()), sou.end());	//去重且改变size()，保证输入的原校不重复 
    	/*
    	cout << sou.size() << endl;
    	for(int i = 0; i < sou.size(); i++) cout << sou[i] << " ";
    	cout << endl;
    	*/
    	
    	/*
    	//测试erase函数
		vector<int > a;
		a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
		a.push_back(4); a.push_back(3); a.push_back(2); a.push_back(1);
		vector<int>::iterator result = find(a.begin(), a.end(), 4);
		a.erase(result);
		cout << a.size() << endl;
		for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
		cout << endl;
		result = find(a.begin(), a.end(), 4);
		a.erase(result);
		cout << a.size() << endl;
		for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
		cout << endl;
		*/
		
		
		if(is_sucess( goal)) cout << "YES" << endl;
		else cout << "NO" << endl;
		
		
		
	}
	
	
	return 0;
} 

bool is_sucess(map<int, vector<int> > m){
	for(int i = 0; i < sou.size(); i++) {
		int s = sou[i];
		//cout << s << endl;
		for(int j = 0; j < m[s].size(); j++){
			int g = m[s][j];
			//cout << g << endl;
			vector<int>::iterator result = find(m[g].begin(), m[g].end(), s);	//查找目标学校是否有想去原校的学生 
			if(result == m[g].end()) return false;
			else m[g].erase(result);											//有则删除 
			
			
			
		}
		
	
	}
	 
	return true;
	
	
}
