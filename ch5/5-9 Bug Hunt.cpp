#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<sstream> 
#include<stack>
#include<cstdlib>
using namespace std;

struct arr{
	int span;					//数组下标范围 
	map<int,int> index;			//下标对应的值 
	
};

map<string, arr> a;				//数组名称映射数组结构 
int is_bug( stack<string> s); 
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	string line;
	while( getline(cin,line)){
		if(line[0] == '.') break; 
		
		int row_bug = 1;
		int flag1 = 1;		//判断是否是第一次读入语句 
		int flag2 = 1;		//判断是否已经出现bug，即使出现了bug还是得把后序得代码读入完 
		a.clear();
		do{
			//cout << line <<endl;
			
			if(flag1) flag1 = 0;
			else if(line[0] == '.') break;		
			//判断是赋值语句还是定义
			int symbol = 1, num_l = 1;		//获得表达式里的元素个数，方便压栈 
			for( int i = 0; i < line.size(); i++){
				if( line[i] == '['){ line[i] = ' '; num_l++;}
				else if( line[i] == ']'){ line[i] = ' ';}
				else if( line[i] == '='){ symbol = 0; num_l++;}
			
			} 
			//cout << line << endl;
			
			stringstream ss(line);
			
			if( symbol){	//定义数组 
				string s;
				int lens;
				ss >> s >> lens;
				a[s].span = lens;
				
				//cout << a[s].span << endl;
				
			}else{			//赋值 
				//cout << num_l << endl;
				
				string s;
				stack<string> zhan;
				
				for( int i = 0; i < num_l; i++){ 
					ss >> s; 
					if(s[0] == '='){	//因为等号和右边得字符连在一起，需要分开 
						zhan.push("=");
						zhan.push(s.substr(1));
					}else 
						zhan.push(s); 
				}		
				/* 
				for( int i = 0; !zhan.empty(); i++){ cout << zhan.top() << " "; zhan.pop();}				
				cout << endl;
				*/ 
				
				//is_bug(zhan);
				if( flag2 && is_bug(zhan) ) { cout << row_bug << endl; flag2 = 0;}	//未初始化变量，下标越界 
				
				
			} 
			row_bug++;

			
		}while( getline(cin,line));
		if(flag2) cout << "0" << endl;												//没有bug则输出0 
		
	}
	
	return 0;
} 
int is_bug( stack<string> s){
	int value;
	int pos = atoi(s.top().c_str());
	//cout << pos << endl;
	
	s.pop();
	
	while(s.size() != 1){
		if( s.top() == "="){
			value = pos; 					//记录等号右边的值 
			s.pop(); 						//弹出等号 
			
			pos = atoi(s.top().c_str());	
			//cout << pos << endl;
			s.pop();
			
			if(s.size() == 1) break;
		}
	
		string name = s.top();
		//cout << name << " " << a[name].span << " " << a[name].index.count(pos) << endl;
		
		if( pos >= a[name].span || a[name].index.count(pos) == 0) { 	//未初始化变量，下标越界 
			//cout << "done1" << endl; 
			return 1;
		}	
		
		pos = a[name].index[pos]; 												
		s.pop();

	}
	//记录栈最后一个元素 
	string name = s.top();
	s.pop(); 
	//cout << pos << endl;
	
	if( pos >= a[name].span) { 
		//cout << "done2" << endl; 
		return 1;
	}
	
	a[name].index[pos] = value;
	//cout << value << endl;
	
	return 0;
	
}
