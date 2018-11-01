#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;

map<int, pair<int, int> > notes;										//编号映射买家信息

//要价高 
struct cmp1{												
	bool operator() (const int a, const int b) const {
		if(notes[a].second == notes[b].second) return a > b;
		return notes[a].second < notes[b].second;
	}
};

//出价低
struct cmp2{												
	bool operator() (const int a, const int b) const {
		if(notes[a].second == notes[b].second) return a > b;
		return notes[a].second > notes[b].second;
	}
}; 

//map<pair<int, int>, int> notes;										//买卖信息映射编号，可能买卖信息会一样啊（咋办）  
map<int, string> i_comd;												//编号映射买家或卖家 

priority_queue<int, vector<int >, cmp1> buy;							//买家优先队列，要价越高越好，存编号 
priority_queue<int, vector<int >, cmp2> sell;							//卖家优先队列，出价越低越好，存编号 
vector<int> f;															//记录已经完成的订单 

void print_quote(string s); 
pair<int, int> take_front(string s);
void init() {
	while(!buy.empty()) buy.pop();
	while(!sell.empty()) sell.pop();
	f.clear();
	notes.clear();
	i_comd.clear();
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	while(cin >> n){
		getchar();
		init();
		for(int i = 1; i <= n; i++) {
			string line;
			getline(cin, line);
			stringstream ss(line);
			//cout << line << endl; 
		
			if(line[0] == 'B' || line[0] == 'S') {			//买或者卖信息 
				string s;
				int size, money;
				pair<int, int> s_m;
				ss >> s >> size >> money;
				//cout << s << size << money;
				 
				s_m = make_pair(size, money);				//大小和钱的二元组
				notes[i] = s_m;								//编号映射买卖信息 
				i_comd[i] = s;								//编号映射买家或卖家 
				 
				if(s[0] == 'B') buy.push(i);
				else sell.push(i);
				
				print_quote(s);								//打印quote信息 
			}else {
				string s;
				int pos;
				ss >> s >> pos;
				//cout << i_comd[pos][0] << endl;
				
				vector<int>::iterator it = find(f.begin(), f.end(), pos);
				if(it == f.end()) {								//判断订单是否删除 
					vector<int > v;
					if(i_comd[pos][0] == 'B') {					//删除的是买队列 
						while(buy.top() != pos){
							v.push_back(buy.top());
							buy.pop();
							//cout << "1" << endl;
						}	
						//cout << "1" << endl;
						f.push_back(buy.top());
						buy.pop();								//删除此位置的信息
						for(int j = 0; j < v.size(); j++)
							buy.push(v[j]);
					}else {										//删除的是卖队列 
						while(sell.top() != pos){
							v.push_back(sell.top());
							sell.pop();
							//cout << notes[sell.top()] << endl;
						}
						//cout << "1" << endl;
						f.push_back(sell.top());
						sell.pop();								//删除此位置的信息
						for(int j = 0; j < v.size(); j++)
							sell.push(v[j]);					
					} 			
				}
				print_quote(s);								//打印quote信息  
			}
		}
	}
	return 0;
}
//打印quote信息 
void print_quote(string s) {
	pair<int, int> tmp_b, tmp_s;
	//cout << "1" << endl;
	
	//判断队列是否空 
	if(buy.empty()) tmp_b = make_pair(0, 0);
	else {
		//cout << "1" << endl;
		tmp_b = take_front("BUY");
	}
	if(sell.empty()) tmp_s = make_pair(0, 99999);
	else tmp_s = take_front("SELL");
	//cout << tmp_b.second << " " << tmp_s.second << endl;
	//判断是否发生交易
	if(tmp_b.first && tmp_s.first && tmp_b.second >= tmp_s.second) {										//发生交易 
		//打印"TRADE"
		int tmp_money, tmp_size = tmp_b.first < tmp_s.first ? tmp_b.first : tmp_s.first;
		if(s[0] == 'B') tmp_money = tmp_s.second;
		else tmp_money = tmp_b.second;
		cout << "TRADE " << tmp_size << " " << tmp_money << endl;
		//cout <<  tmp_b.first << " " << tmp_s.first << endl;
		//更新优先队列
		if(tmp_b.first >= tmp_s.first) {																	//买的数量大于卖的数量 
			//cout << "1" << endl;
			int left_s;
			while(notes[sell.top()].second == tmp_s.second) {												//卖出队列把跟卖出的钱相等的信息全部出队，且记录完成编号
				f.push_back(sell.top()); 
				sell.pop();
				if(sell.empty()) break;
			}			 
			
			for(left_s = tmp_s.first; left_s >= notes[buy.top()].first; ) {									//买队列，留队首最后进行处理
				left_s -= notes[buy.top()].first; 
				f.push_back(buy.top()); 
				buy.pop();	
			}	
			if(left_s && notes[buy.top()].second == tmp_b.second) {												//说明还没有出列完，对队头进行处理 
				left_s = notes[buy.top()].first - left_s; 
				pair<int, int> left = make_pair(left_s, notes[buy.top()].second);
				int pos = buy.top();
				notes[pos] = left;																			//改变编号映射的内容  
				buy.pop();
				buy.push(pos);
			}  		
		}else {																								//卖的数量大于买的数量 
			int left_s;
			//cout << buy.top().first << " " << buy.top().second << endl;
			while(notes[buy.top()].second == tmp_b.second) {												//买出队列把跟卖出的钱相等的信息全部出队
				f.push_back(buy.top()); 
				buy.pop();
				if(buy.empty()) break;
			}				
			//cout << buy.top().first << " " << buy.top().second << endl;
			//cout << tmp_b.first << endl;
			//cout << sell.top().first << endl;
			//cout << "1" << endl;
			for(left_s = tmp_b.first; left_s >= notes[sell.top()].first; ) {										//卖队列，留队首最后进行处理
				//cout << "1" << endl;
				left_s -= notes[sell.top()].first; 
				f.push_back(sell.top());
				sell.pop();
			}	
			//cout << left_s << endl;
			//cout << sell.top().first << endl;
			if(left_s && notes[sell.top()].second == tmp_s.second) {												//说明还没有出列完，对队头进行处理 
				left_s = notes[sell.top()].first - left_s;
				//cout << left_s << endl; 
				pair<int, int> left = make_pair(left_s, notes[sell.top()].second);
				int pos = sell.top();
				notes[pos] = left;																					//改变编号映射的内容  
				sell.pop();
				sell.push(pos);
			}  			
		}
		//打印quote信息
		print_quote(s);
	}else cout << "QUOTE " << tmp_b.first << " " << tmp_b.second << " - " << tmp_s.first << " " << tmp_s.second << endl;	//不发生交易 																								
}
//获得队列信息 
pair<int, int> take_front(string s) {
	vector<int > v;
	int money, size = 0;
	if(s[0] == 'B') {	//对买队列处理 
		money = notes[buy.top()].second;
		//cout << money << endl;
		do {												//求此价钱的总数量 
			v.push_back(buy.top());
			size += notes[buy.top()].first;
			buy.pop();
			//cout << "1" << endl;
			if(buy.empty()) break;
		}while(notes[buy.top()].second == money);
		//cout << "1" << endl;
		for(int i = 0; i < v.size(); i++) buy.push(v[i]);	//将弹出队列的信息重新加入 
	}else {				//对卖队列处理 
		money = notes[sell.top()].second;
		do {												//求此价钱的总数量 
			v.push_back(sell.top());
			size += notes[sell.top()].first;
			sell.pop();
			if(sell.empty()) break;
		}while(notes[sell.top()].second == money);
		//cout << "1" << endl;
		for(int i = 0; i < v.size(); i++) sell.push(v[i]);	//将弹出队列的信息重新加入 
		
	}
	pair<int, int> tmp = make_pair(size, money);
	return tmp;
}
