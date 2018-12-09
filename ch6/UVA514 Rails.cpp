#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
const int maxn = 1000 +5; 

int n;			//������� 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	string line;
	int flag_ci = 0;
	while(getline(cin, line)) {
		//cout << line << endl;
		//�ж϶�����ǵ������������ǳ����վ��˳�� 
		int flag = 0, seq[maxn];
		if(line[0] == '0') { cout << endl; continue;}   
		for(int i = 0; i < line.size(); i++) 
			if(line[i] == ' ') flag = 1;
		stringstream ss(line);
		if(flag == 0) { ss >> n; continue;}		//�ǵ�������
		else {									//�ǳ����վ��˳�� 
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

		//��ʼ�� 
		stack<int> stat;				//��ͣվ���Ķ�ջ
		vector<int> in;					//��վ����
		for(int i = 1; i <= n; i++) in.push_back(i);
		int now_p = 0;					//��δ��վǰ����ǰ��ĳ����� 
		/* 
		queue<int> in_q;				//��վ���У���ʱ�˲����ö�����,û�г�ʱ�����Ҹ���˳���ĸ��� 
		for(int i = 1; i <= n; i++) in_q.push(i);
		
		//�ж��Ƿ��������վ˳��
		int Ok = 1;
		for(int i = 0; i < n; i++) {
			//cout << "1" << endl;
			//�ȴӽ�վ�������ң��Ҳ������ҳ�վ��ջ 
			if(!in_q.empty() && seq[i] >= in_q.front()) {	//��վ�������ҵ� 
				//cout << "2" << endl;
				while(1){									//����do{}while(); 
					stat.push(in_q.front());
					in_q.pop();
					if(in_q.empty() || seq[i] < in_q.front()) break;	//�ö��е�ʱ�����ȱ��뿼�Ƕ��пյ������Ҫ��Ȼ�ر����������ѭ�� 
					//cout << "1" << endl;
				}
				stat.pop();									//����վ˳����λ�ĳ��ᵯ�� 
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
		 
		
		//�ж��Ƿ��������վ˳��
		int Ok = 1;
		for(int i = 0; i < n; i++) {
			//cout << "1" << endl;
			//�ȴӽ�վ�������ң��Ҳ������ҳ�վ��ջ 
			if(now_p < in.size() && seq[i] >= in[now_p]) {	//��վ�������ҵ� 
				//cout << "2" << endl;
				while(1){									//����do{}while(); 
					stat.push(in[now_p]);
					now_p++; 
					if(now_p >= in.size() || seq[i] < in[now_p]) break;	//�ö��е�ʱ�����ȱ��뿼�Ƕ��пյ������Ҫ��Ȼ�ر����������ѭ�� 
					//cout << "1" << endl;
				}
				stat.pop();									//����վ˳����λ�ĳ��ᵯ�� 
			}else if(seq[i] == stat.top()){	
				//cout << "3" << endl;									
				stat.pop();
			}else {
				//cout << "4" << endl;
				Ok = 0;
				break;
			}		
		} 
		 
		//��ӡ��� 
		if(flag_ci == 0) flag_ci = 1;
		else cout << endl; 
		if(Ok) cout << "Yes";
		else cout << "No";
		
	}
	return 0;
} 
