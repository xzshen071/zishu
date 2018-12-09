#include<iostream>
#include<deque> 
#include<vector>
#include<map>
#include<string>
#include<sstream> 
#include<cctype>
using namespace std;

struct program {
	int ID;					//������ 
	int now_p;				//�������ڽ�Ҫִ�е���� 
	vector<string> s;
};
int lock_f = 0, flag_s = 0;
vector<program> p;			//����
map<char, int> v_c;			//��������Ӧ�ĳ���ֵ����ֵΪ0 
//�������� 
int Judge_s(string s, int pos);
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int ci, flag_ci = 0; 	//�¼��� 
	cin >> ci;
	while(ci--) {
		int n, t1, t2, t3, t4, t5, Q;
		map<int, int> s_t;									//���������ӳ���Ӧ��ʱ�䣬0Ϊ��ֵ��1Ϊ��ӡ��2Ϊlock��3Ϊunlock��4Ϊend 
		int flag = 1; 
		if(flag_ci == 0) flag_ci = 1;
		else cout << endl;
		 
		//�������Ϣ 
		cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;		//�����������ֵ���ʱ�䡢��ӡ���ʱ�䡢lockʱ�䡢unlockʱ�䡢endʱ�䡢ÿ�γ�������ִ�е�ʱ��
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
		//��ʼ��
		v_c.clear();										//��ձ���ӳ��ĳ��� 
		deque<int> ready, block;							//˫�˶��У�׼������ֹ���� 
		for(int i = 0; i < p.size(); i++) ready.push_back(i); 
		s_t[0] = t1; s_t[1] = t2; s_t[2] = t3; s_t[3] = t4; s_t[4] = t5;
		
		//ִ�г���
		while(ready.empty() == 0) {							//ready˫�˶���Ϊ�գ������ִ����� 
			int p_p = ready.front();
			//cout << ready.front() << endl;
			ready.pop_front();
			int end_f = 0, block_f = 0;
			for(int i = Q; i > 0;) {						//ִ���ض�ʱ��ĳ��� 
				int s_p = p[p_p].now_p;
				//cout << s_p << endl;
				int tmp_f = Judge_s(p[p_p].s[s_p], p_p);	//�ж���������ҶԸ�ֵ�ʹ�ӡ��������Ӧ�Ĳ��������ض�Ӧ�ı�� 
				//cout << tmp_f << endl << endl;
				//ִ����Ӧ�Ĳ��� 
				if(tmp_f == 2) {							//lock 
					if(lock_f) {							//����block����
						block_f = 1;
						block.push_back(p_p);
						break; 
					}else lock_f = 1;	
				}else if(tmp_f == 3) {						//unlock 
					lock_f = 0;
					if(!block.empty()) {
						ready.push_front(block.front());		//��block���ж��׼���ready���ж��� 
						block.pop_front();		
					}
				}else if(tmp_f == 4){						//end
					end_f = 1;
					break;
				}
				i -= s_t[tmp_f];
				p[p_p].now_p++;								//ִ�е���һ����� 
			}
			//cout << end_f << " " << block_f << endl;
			if(end_f == 0 && block_f == 0)					//����û��ִ������û�м���block���� 
				ready.push_back(p_p);				
		}

	}	
	
	return 0;
}
//�ж���������ҶԸ�ֵ�ʹ�ӡ��������Ӧ�Ĳ��������ض�Ӧ�ı�� 
int Judge_s(string s, int pos) {
	int symbol; 
	//����ֵ������������ֿ��ж� 
	int flag = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '=') {flag = 0; break;}
	}
	//cout << s << endl;
	if(flag) {					//���Ǹ�ֵ���			
		if(s[0] == 'p') {		//��ӡ��� 
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
		char var = s[0];		//������  
		for(int i = 0; i < s.size(); i++) 
			if(!isdigit(s[i])) 
				s[i] = ' '; 
		stringstream ss(s);
		int con;
		ss >> con;				//����
		v_c[var] = con;	
	} 
	
	return symbol;
} 
