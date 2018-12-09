#include<iostream>
#include<deque> 
#include<vector>
#include<map>
#include<string>
#include<sstream> 
#include<cctype>
using namespace std;

struct program {
	int ID;					//程序编号 
	int now_p;				//程序现在将要执行的语句 
	vector<string> s;
};
int lock_f = 0, flag_s = 0;
vector<program> p;			//程序
map<char, int> v_c;			//变量名对应的常数值，初值为0 
//函数声明 
int Judge_s(string s, int pos);
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int ci, flag_ci = 0; 	//事件数 
	cin >> ci;
	while(ci--) {
		int n, t1, t2, t3, t4, t5, Q;
		map<int, int> s_t;									//各个语句编号映射对应的时间，0为赋值，1为打印，2为lock，3为unlock，4为end 
		int flag = 1; 
		if(flag_ci == 0) flag_ci = 1;
		else cout << endl;
		 
		//存程序信息 
		cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;		//程序个数，赋值语句时间、打印语句时间、lock时间、unlock时间、end时间、每次程序允许执行的时间
		p.clear(); 
		for(int i = 1; i <= n; i++) {
			string line;
			program tmp_p;
			tmp_p.ID = i;
			tmp_p.now_p = 0;
			if(flag) {getchar(); flag = 0;}
			while(getline(cin, line)) {
				tmp_p.s.push_back(line); 
				if(line == "end") break;
			}
			p.push_back(tmp_p);
		}
		/*
		for(int i = 0; i < p.size(); i++) {
			cout << p[i].now_p << endl;
			for(int j = 0; j < p[i].s.size(); j++) cout << p[i].s[j] << endl;
		}
		*/
		//初始化
		v_c.clear();										//清空变量映射的常数 
		deque<int> ready, block;							//双端队列，准备和阻止队列 
		for(int i = 0; i < p.size(); i++) ready.push_back(i); 
		s_t[0] = t1; s_t[1] = t2; s_t[2] = t3; s_t[3] = t4; s_t[4] = t5;
		
		//执行程序
		while(ready.empty() == 0) {							//ready双端队列为空，则程序执行完毕 
			int p_p = ready.front();
			//cout << ready.front() << endl;
			ready.pop_front();
			int end_f = 0, block_f = 0;
			for(int i = Q; i > 0;) {						//执行特定时间的程序 
				int s_p = p[p_p].now_p;
				//cout << s_p << endl;
				int tmp_f = Judge_s(p[p_p].s[s_p], p_p);	//判断语句类型且对赋值和打印语句进行相应的操作，返回对应的编号 
				//cout << tmp_f << endl << endl;
				//执行相应的操作 
				if(tmp_f == 2) {							//lock 
					if(lock_f) {							//加入block队列
						block_f = 1;
						block.push_back(p_p);
						break; 
					}else lock_f = 1;	
				}else if(tmp_f == 3) {						//unlock 
					lock_f = 0;
					if(!block.empty()) {
						ready.push_front(block.front());		//将block队列队首加入ready队列队首 
						block.pop_front();		
					}
				}else if(tmp_f == 4){						//end
					end_f = 1;
					break;
				}
				i -= s_t[tmp_f];
				p[p_p].now_p++;								//执行到下一个语句 
			}
			//cout << end_f << " " << block_f << endl;
			if(end_f == 0 && block_f == 0)					//程序没有执行完且没有加入block队列 
				ready.push_back(p_p);				
		}

	}	
	
	return 0;
}
//判断语句类型且对赋值和打印语句进行相应的操作，返回对应的编号 
int Judge_s(string s, int pos) {
	int symbol; 
	//将赋值语句与其他语句分开判断 
	int flag = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '=') {flag = 0; break;}
	}
	//cout << s << endl;
	if(flag) {					//不是赋值语句			
		if(s[0] == 'p') {		//打印语句 
			symbol = 1;
			//if(flag_s == 0) flag_s = 1;
			//else cout << endl;
			if(v_c.count(s[6]) == 0) cout << p[pos].ID << ": 0" << endl;
			else cout << p[pos].ID << ": " << v_c[s[6]] << endl; 
		}else if(s[0] == 'l') { symbol = 2;
		}else if(s[0] == 'u') { symbol = 3;	
		}else symbol = 4;
	}else {
		symbol = 0;
		char var = s[0];		//变量名  
		for(int i = 0; i < s.size(); i++) 
			if(!isdigit(s[i])) 
				s[i] = ' '; 
		stringstream ss(s);
		int con;
		ss >> con;				//常数
		v_c[var] = con;	
	} 
	
	return symbol;
} 
