#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
const int maxn = 1000 +5; 

int n;			//车厢个数 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	string line;
	int flag_ci = 0;
	while(getline(cin, line)) {
		//cout << line << endl;
		//判断读入的是单个整数，还是车厢出站的顺序 
		int flag = 0, seq[maxn];
		if(line[0] == '0') { cout << endl; continue;}   
		for(int i = 0; i < line.size(); i++) 
			if(line[i] == ' ') flag = 1;
		stringstream ss(line);
		if(flag == 0) { ss >> n; continue;}		//是单个整数
		else {									//是车厢出站的顺序 
			for(int i = 0; i < n; i++) { 
				ss >> seq[i]; 
				//cout << "1" << endl;
			}
		}
		 
		/*
		//cout << n << endl;
		for(int i = 0; i < n; i++) cout << seq[i] << " ";
		cout << endl;			
		*/ 

		//初始化 
		stack<int> stat;				//火车停站处的堆栈
		vector<int> in;					//入站数组
		for(int i = 1; i <= n; i++) in.push_back(i);
		int now_p = 0;					//还未进站前的最前面的车厢编号 
		/* 
		queue<int> in_q;				//入站队列，超时了不能用队列了,没有超时，是我搞错了车厢的个数 
		for(int i = 1; i <= n; i++) in_q.push(i);
		
		//判断是否能满足出站顺序
		int Ok = 1;
		for(int i = 0; i < n; i++) {
			//cout << "1" << endl;
			//先从进站队列中找，找不到再找车站堆栈 
			if(!in_q.empty() && seq[i] >= in_q.front()) {	//进站队列能找到 
				//cout << "2" << endl;
				while(1){									//少用do{}while(); 
					stat.push(in_q.front());
					in_q.pop();
					if(in_q.empty() || seq[i] < in_q.front()) break;	//用队列的时候首先必须考虑队列空的情况，要不然特别容易造成死循环 
					//cout << "1" << endl;
				}
				stat.pop();									//将出站顺序首位的车厢弹出 
			}else if(seq[i] == stat.top()){	
				//cout << "3" << endl;									
				stat.pop();
			}else {
				//cout << "4" << endl;
				Ok = 0;
				break;
			}		
		} 
		*/
		 
		
		//判断是否能满足出站顺序
		int Ok = 1;
		for(int i = 0; i < n; i++) {
			//cout << "1" << endl;
			//先从进站队列中找，找不到再找车站堆栈 
			if(now_p < in.size() && seq[i] >= in[now_p]) {	//进站队列能找到 
				//cout << "2" << endl;
				while(1){									//少用do{}while(); 
					stat.push(in[now_p]);
					now_p++; 
					if(now_p >= in.size() || seq[i] < in[now_p]) break;	//用队列的时候首先必须考虑队列空的情况，要不然特别容易造成死循环 
					//cout << "1" << endl;
				}
				stat.pop();									//将出站顺序首位的车厢弹出 
			}else if(seq[i] == stat.top()){	
				//cout << "3" << endl;									
				stat.pop();
			}else {
				//cout << "4" << endl;
				Ok = 0;
				break;
			}		
		} 
		 
		//打印结果 
		if(flag_ci == 0) flag_ci = 1;
		else cout << endl; 
		if(Ok) cout << "Yes";
		else cout << "No";
		
	}
	return 0;
} 
