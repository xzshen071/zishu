#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;

map<int, pair<int, int> > notes;						//���ӳ�������Ϣ

//Ҫ�۸� 
struct cmp1{												
	bool operator() (const int a, const int b) const {
		if(notes[a].second == notes[b].second) return a > b;
		return notes[a].second < notes[b].second;
	}
};

//���۵�
struct cmp2{												
	bool operator() (const int a, const int b) const {
		if(notes[a].second == notes[b].second) return a > b;
		return notes[a].second > notes[b].second;
	}
}; 

//map<pair<int, int>, int> notes;						//������Ϣӳ���ţ�����������Ϣ��һ������զ�죩  
map<int, string> i_comd;								//���ӳ����һ����� 

priority_queue<int, vector<int >, cmp1> buy;			//������ȶ��У�Ҫ��Խ��Խ�ã����� 
priority_queue<int, vector<int >, cmp2> sell;			//�������ȶ��У�����Խ��Խ�ã����� 
vector<int> f;											//��¼Ҫɾ���Ķ��� 

map<string, map<int, int> > b_s_size;					//��Ҫ��Ϊ��ӳ���������ж���Ҫ������

void print_quote(string s); 
pair<int, int> take_front(string s);
void init() {
	while(!buy.empty()) buy.pop();
	while(!sell.empty()) sell.pop();
	f.clear();
	notes.clear();
	i_comd.clear();
	b_s_size.clear();
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, flag = 1;
	while(cin >> n) {
		if(flag) flag = 0; else cout << endl;
		getchar();
		init();
		for(int i = 1; i <= n; i++) {
			string line;
			getline(cin, line);
			stringstream ss(line);
			//cout << line << endl; 
		
			if(line[0] == 'B' || line[0] == 'S') {				//���������Ϣ 
				string s;
				int size, money;
				pair<int, int> s_m;
				ss >> s >> size >> money;
				//cout << s << size << money;
				 	
				s_m = make_pair(size, money);					//��С��Ǯ�Ķ�Ԫ��
				notes[i] = s_m;									//���ӳ��������Ϣ 
				i_comd[i] = s;									//���ӳ����һ����� 
				 
				//ӳ���������ж��ף�Ҫ����߻������ͣ�������
				if(b_s_size[s].count(money) == 0) b_s_size[s][money] = size;
				else b_s_size[s][money] += size; 
				
				if(s[0] == 'B') buy.push(i);
				else sell.push(i);
				
				print_quote(s);									//��ӡquote��Ϣ 
			}else {
				string s;
				int pos;
				ss >> s >> pos;				
				//cout << i_comd[pos][0] << endl;	
				
				vector<int>::iterator it = find(f.begin(), f.end(), pos); 
				if(it == f.end()) {								//û��ɾ������δ��ɵĶ��� 
					if(i_comd[pos][0] == 'B') {
						b_s_size[i_comd[pos]][notes[pos].second] -= notes[pos].first;
					}else {
						b_s_size[i_comd[pos]][notes[pos].second] -= notes[pos].first;
					} 	
					f.push_back(pos);							//˵����λ�õ�Ҫ��ɾ��				
				}
				
				print_quote(s);									//��ӡquote��Ϣ 
			} 
			/*
			//CANCEL����̫��ʱ�� 
			else {	
				string s;
				int pos;
				ss >> s >> pos;
				//cout << i_comd[pos][0] << endl;
				
				vector<int>::iterator it = find(f.begin(), f.end(), pos);
				if(it == f.end()) {								//�ж϶����Ƿ�ɾ�� 
					vector<int > v;
					if(i_comd[pos][0] == 'B') {					//ɾ����������� 
						while(buy.top() != pos){
							v.push_back(buy.top());
							buy.pop();
							//cout << "1" << endl;
						}	
						//cout << "1" << endl;
						b_s_size[i_comd[pos]][notes[buy.top()].second] -= notes[buy.top()].first;
						f.push_back(buy.top());
						buy.pop();								//ɾ����λ�õ���Ϣ
						for(int j = 0; j < v.size(); j++)
							buy.push(v[j]);
					}else {										//ɾ������������ 
						while(sell.top() != pos){
							v.push_back(sell.top());
							sell.pop();
							//cout << notes[sell.top()] << endl;
						}
						//cout << "1" << endl;
						b_s_size[i_comd[pos]][notes[sell.top()].second] -= notes[sell.top()].first;
						f.push_back(sell.top());
						sell.pop();								//ɾ����λ�õ���Ϣ
						for(int j = 0; j < v.size(); j++)
							sell.push(v[j]);					
					} 			
				}
				print_quote(s);									//��ӡquote��Ϣ  
			}
			*/
		}
		//cout << endl;
	}
	return 0;
}
//��ӡquote��Ϣ 
void print_quote(string s) {
	pair<int, int> tmp_b, tmp_s;
	//cout << "1" << endl;
	
	//�ж϶����Ƿ�� 
	if(buy.empty()) tmp_b = make_pair(0, 0);
	else {
		//cout << "1" << endl;
		tmp_b = take_front("BUY");
	}
	if(sell.empty()) tmp_s = make_pair(0, 99999);
	else tmp_s = take_front("SELL");
	//cout << tmp_b.second << " " << tmp_s.second << endl;
	//�ж��Ƿ�������
	if(tmp_b.first && tmp_s.first && tmp_b.second >= tmp_s.second) {														//�������� 
		//��ӡ"TRADE"
		//int tmp_money, tmp_size = tmp_b.first < tmp_s.first ? tmp_b.first : tmp_s.first;
		int tmp_money, tmp_size;
		if(s[0] == 'B') tmp_money = tmp_s.second;
		else tmp_money = tmp_b.second;
		cout << "TRADE "; 
		//cout <<  tmp_b.first << " " << tmp_s.first << endl;
		//�������ȶ���
		int p_b = buy.top();
		int p_s = sell.top();
		if(notes[p_b].first >= notes[p_s].first) {											//������������������� 
			//cout << "1" << endl;
			int left_s = notes[p_s].first;
			tmp_size = notes[p_s].first;

			b_s_size["SELL"][tmp_s.second] -= notes[p_s].first;								//x -= yΪ x = x -y��������������Ӧ����Ŀ
			f.push_back(sell.top());														//�������аѸ�������Ǯ��ȵ���Ϣȫ�����ӣ��Ҽ�¼��ɱ��
			sell.pop();					 	

			b_s_size["BUY"][tmp_b.second] -= notes[p_s].first;								//�����������Ӧ����Ŀ 
			left_s = notes[buy.top()].first - left_s; 										//˵����û�г����꣬�Զ�ͷ���д��� 
			if(left_s != 0) {
				pair<int, int> left = make_pair(left_s, notes[buy.top()].second);
				int pos = buy.top();
				notes[pos] = left;															//�ı���ӳ�������  
				buy.pop();
				buy.push(pos);
			}else {
				f.push_back(buy.top());	
				buy.pop();
			}
		}else {																				//������������������� 
			int left_s = notes[p_b].first;
			tmp_size = notes[p_b].first;
			
			b_s_size["BUY"][tmp_b.second] -= notes[p_b].first;								//�����������Ӧ����Ŀ 
			f.push_back(buy.top()); 														//������аѸ�������Ǯ��ȵ���Ϣȫ������
			buy.pop();		

			b_s_size["SELL"][tmp_s.second] -= notes[p_b].first;								//x -= yΪ x = x -y��������������Ӧ����Ŀ
			left_s = notes[sell.top()].first - left_s; 
			if(left_s != 0) {																//˵����û�г����꣬�Զ�ͷ���д��� 
				//cout << left_s << endll; 
				pair<int, int> left = make_pair(left_s, notes[sell.top()].second);
				int pos = sell.top();
				notes[pos] = left;															//�ı���ӳ�������  
				sell.pop();
				sell.push(pos);
			}else {
				f.push_back(sell.top()); 				
				sell.pop();
			} 			
		}
		//��ӡquote��Ϣ
		cout << tmp_size << " " << tmp_money << endl;
		print_quote(s);
	}else cout << "QUOTE " << tmp_b.first << " " << tmp_b.second << " - " << tmp_s.first << " " << tmp_s.second << endl;	//���������� 																								
}
//��ö�����Ϣ
pair<int, int> take_front(string s) {
	int money, size = 0; 
	vector<int>::iterator it;
	
	//��Ҫ�ų��Ѿ�ɾ���Ķ���
	if(s[0] == 'B') {	//������д���
		while(1) {
			it = find(f.begin(), f.end(), buy.top());
			if(it != f.end()) {
				//b_s_size[s][notes[buy.top()].second] -= notes[buy.top()].first;
				buy.pop();
				if(buy.empty()) break;
			}
			else break; 
			//cout << "1" << endl;
		}
		if(buy.empty()) { money = 0; size = 0;}
		else { money = notes[buy.top()].second; size = b_s_size[s][money];}
	}else {
		while(1) {
			it = find(f.begin(), f.end(), sell.top());
			if(it != f.end()) {
				//b_s_size[s][notes[sell.top()].second] -= notes[sell.top()].first;
				sell.pop();
				if(sell.empty()) break;
			}
			else break; 
		}
		if(sell.empty()) { money = 99999; size = 0;}
		else { money = notes[sell.top()].second; size = b_s_size[s][money];}		
	}
	
	pair<int, int> tmp = make_pair(size, money);
	return tmp;
}
/*
//��ö�����Ϣ���Ӻ���ʹ����ʱ�� 
pair<int, int> take_front(string s) {
	vector<int > v;
	int money, size = 0;
	if(s[0] == 'B') {	//������д��� 
		money = notes[buy.top()].second;
		//cout << money << endl;
		do {												//��˼�Ǯ�������� 
			v.push_back(buy.top());
			size += notes[buy.top()].first;
			buy.pop();
			//cout << "1" << endl;
			if(buy.empty()) break;
		}while(notes[buy.top()].second == money);
		//cout << "1" << endl;
		for(int i = 0; i < v.size(); i++) buy.push(v[i]);	//���������е���Ϣ���¼��� 
	}else {				//�������д��� 
		money = notes[sell.top()].second;
		do {												//��˼�Ǯ�������� 
			v.push_back(sell.top());
			size += notes[sell.top()].first;
			sell.pop();
			if(sell.empty()) break;
		}while(notes[sell.top()].second == money);
		//cout << "1" << endl;
		for(int i = 0; i < v.size(); i++) sell.push(v[i]);	//���������е���Ϣ���¼��� 
		
	}
	pair<int, int> tmp = make_pair(size, money);
	return tmp;
}
*/
