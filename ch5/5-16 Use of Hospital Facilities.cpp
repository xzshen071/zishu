#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdlib>				//malloc���������� 
#include<cstdio>
#include<sstream>
using namespace std;

const int maxk = 100 + 10;
const int maxn = 10 + 10;
const int maxm = 30 + 10;

//���� 
struct patient {
	string name;		//���� 
	int ot, rt;			//����ʱ�䣬�ָ�ʱ�� 
	int room, bed;		//����������Һͻָ��ұ�� 
	string r_b, r_e;	//�����ҿ�ʼʱ��ͽ���ʱ�� 
	string b_b, b_e; 	// �ָ��ҿ�ʼʱ��ͽ���ʱ�� 
};
struct place {
	int id;				//�����һ�ָ���id
	int st;				//��һ�������Һͻָ����ܰ��ò��˵�ʱ��ʱ�� 
	int ut;				//�����һ�ָ��ҵ�ʹ��ʱ�� 
	double u_rate;		//ʹ���� 
}; 
map<int, int> in_b_st;	//���ӳ�䲡�˿�ʼ����ָ��ҵ�ʱ��
map<int, int> p_r;		//���˱��ӳ�������ұ�� 

//stʱ���С��������ͬid��С���� 
bool cmp1(const place a, const place b) {
	if(a.st != b.st) return a.st < b.st;
	return a.id < b.id; 
}
bool cmp2(const int a, const int b) {
	if(in_b_st[a] != in_b_st[b]) return in_b_st[a] < in_b_st[b];
	return p_r[a] < p_r[b];
}
//id��С������ 
bool cmp3(const place a, const place b) {
	return a.id < b.id;
}

pair<int, string> to_hour(int minute);					//��minnut����Сʱ��ʾ 
string to_s(int a);										//��int��ת��Ϊstring�� 
//���⻹���Կ��������ȶ��� 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, m, t1, t2, t3, k;							//�����Ҹ������ָ��Ҹ������������ҵ��ָ���ʱ�䣬�Ӵ���һ�����������ҵ�׼��ʱ�䣬�Ӵ���һ�����˻ָ��ҵ�׼��ʱ�䣬���˸��� 
	string T;											//T����׼ʱ���������� 
	while(cin >> n >> m >> T >> t1 >> t2 >> t3 >> k) {
		//cout << "1" << endl;
		//cout << n << " " << m << " " << T  << " " << t1 << " " << t2 << " " << t3 << " " << k << endl; 
		//��ÿ������Ӧ�ô�ӡ����Ϣ 
		vector<int> pat[maxk];	
		//��ʼ�������Ҳ�������Ŵ�1��ʼ
		vector<place> in_r;
		place room[n + 1];
		for(int i = 1; i <= n; i++) { room[i].id = i; room[i].st = room[i].ut = 0; in_r.push_back(room[i]);}		
		//for(int i = 1; i <= n; i++) { cout << room[i].id << endl;}	
		
		//���������ݣ���Ŵ�1��ʼ 
		patient p[k + 1];
		for(int i = 1; i <= k; i++) { 
			getchar();
			getline(cin, p[i].name); 
			//cout << p[i].name << " ";
			cin >> p[i].ot >> p[i].rt;
			//cout << p[i].ot << " " << p[i].rt << endl;
		}
		//cout << "1" << endl;
		//���˽���������
		in_b_st.clear();
		p_r.clear();
		vector<int> in_b_i;			//����Ҫ�Դ�����������򣬱�ʾ���˽���ָ���ʱ�ı��˳�� 
		for(int i = 1; i <= k; i++) {
			sort(in_r.begin(), in_r.end(), cmp1);																//��������������С��ʼʱ������������ڵ�һλ��������ͬ����id��С����
			//cout << in_r[0].id << endl; 
			
			//�˲��˽������������λ��������
			pat[i].push_back(in_r[0].id); pat[i].push_back(in_r[0].st);	pat[i].push_back(in_r[0].st + p[i].ot);	//�ڴ˲��˴洢��Ϣ������������id��������ʼʱ�䣬��������ʱ�� 
			in_b_st[i] = in_r[0].st + p[i].ot + t1;																//���˱��ӳ�����ָ��ҵ�ʱ��ʱ�� 
			in_b_i.push_back(i);
			p_r[i] = in_r[0].id;																				//���˱��ӳ�������ұ��																	 
			
			//�ı���λ�����ҵĲ��� 
			in_r[0].st = in_r[0].st + p[i].ot + t2;																//�´ο���ʱ��ʱ�� 
			in_r[0].ut += p[i].ot; 																				//��¼ʹ��ʱ��
		} 
		/*
		for(int i = 1; i <= k; i++) {
			for(int j = 0; j < pat[i].size(); j++)
				cout << pat[i][j] << " ";
			cout << endl;
		}
		for(int i = 0; i < n; i++) cout << in_r[i].id << " " << in_r[i].ut << endl;
		for(int i = 1; i <= k; i++) cout << i << " " << in_b_st[i] << endl;
		sort(in_b_i.begin(), in_b_i.end(), cmp2);
		for(int i = 0; i < in_b_i.size(); i++) cout << in_b_i[i] << " " << in_b_st[in_b_i[i]] << endl;
		*/
		//cout << "1" << endl;
		//���˽���ָ���
		//for(int i = 0; i < in_b_i.size(); i++) cout << in_b_i[i] << " " << in_b_st[in_b_i[i]] << " " << p_r[in_b_i[i]] << endl;
		//cout << endl;
		sort(in_b_i.begin(), in_b_i.end(), cmp2);				//����Ⱥ����ָ��ҵĲ���˳�� 
		//for(int i = 0; i < in_b_i.size(); i++) cout << in_b_i[i] << " " << in_b_st[in_b_i[i]] << " " << p_r[in_b_i[i]] << endl;
		vector<place> a_bed;									//����õĻָ��Ҵ�λ
		int b_id = 1;											//��ָ���id 
		int max_t = 0;											//��¼���ѵ��ʱ�䣬��������ʹ���� 
		for(int i = 0; i < k; i++) {
			int num = in_b_i[i];								//���˱�� 
			//sort(a_bed.begin(), a_bed.end(), cmp3);			//�Կ��õĻָ���λ�������� 
			//Ѱ��id��С�Ŀ��ûָ��Ҵ�λ 		
			int pos = -1;
			for(int j = 0; j < a_bed.size(); j++) {
				//cout << a_bed[j].st << endl;
				if(a_bed[j].st <= (in_b_st[num] - t1)) {		//��λ���´ο���ʱ��С�ڵ��ڲ��˵ĸս���������ʱ�� 
					pos = j;									//���ô�λ��λ�� 
					break; 
				}
			} 
			
			//�������ΰ�˳���a_bed��ѡ�ָ���
			if(pos == -1) {										//�����λ�ջ�����Ҫ�Ŷ� 
				//�����´�λ���˲����� 
				place tmp;										
				tmp.id = b_id;									//���ô�λid 
				tmp.st = in_b_st[num] + p[num].rt + t3;			//��λ�´ο���ʹ�õ�ʱ��								
				tmp.ut = p[num].rt;								//�˴�λ��ʹ��ʱ��
				a_bed.push_back(tmp);							//�����ʹ�ô�λ�Ķ��� 
				
				pat[num].push_back(b_id);						//��¼�˲��˽���Ĵ�λ��� 
				pat[num].push_back(in_b_st[num]);				//����ָ���ʱ�� 
				pat[num].push_back(in_b_st[num] + p[num].rt);	//�뿪�ָ���ʱ�� 
				b_id++; 										//������һ���µĴ�λ�Ĵ�λ�� 
			}else {												//posλ�ô��Ĵ�λ����
				//���´�λ�ô��Ĵ�λ��Ϣ
				a_bed[pos].st = in_b_st[num] + p[num].rt + t3;	//��λ�´ο���ʹ�õ�ʱ�� 
				a_bed[pos].ut += p[num].rt;						//�˴�λ���ۼ�ʹ��ʱ��	 
				
				pat[num].push_back(a_bed[pos].id); 				//��¼�˲��˽���Ĵ�λ���
				pat[num].push_back(in_b_st[num]);				//����ָ���ʱ�� 
				pat[num].push_back(in_b_st[num] + p[num].rt);	//�뿪�ָ���ʱ�� 
			}
			max_t = max(max_t, in_b_st[num] + p[num].rt);		//���һ�����˽�����ʱ�� 
		}
		//for(int i = 0; i < a_bed.size(); i++) cout << a_bed[i].id << " " << a_bed[i].st << " " << a_bed[i].ut << endl;
		/* 
		for(int i = 1; i <= k; i++) {
			for(int j = 0; j < pat[i].size(); j++)
				cout << pat[i][j] << " ";
			cout << endl;
		}		
		*/ 
		//cout << "1" << endl;
		//Ϊ��ӡ��׼�� 
		int init_t;
		//����ʼʱ��ת��Ϊint�ͣ�����Ӽ� 
		if(T[0] == '0') init_t = atoi(T.substr(1).c_str());		
		else init_t = atoi(T.c_str());
		pair<int, string> h_m;	
		string hour;	
		for(int i = 1; i <= k; i++) {
			p[i].room = pat[i][0];
			
			h_m = to_hour(pat[i][1]);
			//cout << h_m.first << " " << h_m.second << endl;
			p[i].r_b = to_s(init_t + h_m.first) + ":" + h_m.second;
			h_m = to_hour(pat[i][2]);
			p[i].r_e = to_s(init_t + h_m.first) + ":" + h_m.second;
			
			p[i].bed = pat[i][3];
			
			h_m = to_hour(pat[i][4]);
			p[i].b_b = to_s(init_t + h_m.first) + ":" + h_m.second;
			h_m = to_hour(pat[i][5]);
			p[i].b_e = to_s(init_t + h_m.first) + ":" + h_m.second; 
			 
		}
		/*
		for(int i = 1; i <= k; i++) {
			cout << p[i].name << " " << p[i].room << " " << p[i].r_b << " " << p[i].r_e << " " << p[i].bed << " " << p[i].b_b << " " << p[i].b_e << endl;
		}
		*/
		//cout << max_t << endl;
		//�ֱ���������Һͻָ��ҵ�ʹ���� 
		sort(in_r.begin(), in_r.end(), cmp3); 
		for(int i = 0; i < n; i++) { 
			if(max_t == 0)
				in_r[i].u_rate = 0.00;
			else
				in_r[i].u_rate = 100.0 * in_r[i].ut / max_t;
			//cout << in_r[i].id << " " << in_r[i].ut; printf(" %.2f\n", in_r[i].u_rate);
		} 
		//cout << "1" << endl;
		for(int i = 0; i < m; i++) {
			if((i + 1) < b_id ) {	//b_idֵָ���ǽ���������һλ��λ��id
				if(max_t != 0)
					a_bed[i].u_rate = 100.0 * a_bed[i].ut / max_t;
				else
					a_bed[i].u_rate = 0.0;
				//cout << a_bed[i].id << " " << a_bed[i].ut; printf(" %.2f\n", a_bed[i].u_rate);
			}else {
				place tmp;
				tmp.ut = 0;
				tmp.u_rate = 0.0;
				a_bed.push_back(tmp);
			}
			//cout << "1" << endl;

		}
		//cout << "1" << endl;
		//��ӡ 
		printf(" Patient          Operating Room          Recovery Room\n");
    	printf(" #  Name     Room#  Begin   End      Bed#  Begin    End\n");
    	printf(" ------------------------------------------------------\n");
    	for(int i = 1; i <= k; i++)
        	printf("%2d  %-9s %2d  %6s  %6s    %3d  %6s  %6s\n", i, p[i].name.c_str(), p[i].room, p[i].r_b.c_str(), p[i].r_e.c_str(), p[i].bed, p[i].b_b.c_str(), p[i].b_e.c_str());
    	printf("\n");
    	printf("Facility Utilization\n");
    	printf("Type  # Minutes  % Used\n");
    	printf("-------------------------\n"); 
		for(int i = 0; i < n; i++) printf("Room %2d %7d %7.2f\n", i + 1, in_r[i].ut, in_r[i].u_rate);
    	for(int i = 0; i < m; i++) printf("Bed  %2d %7d %7.2f\n", i + 1, a_bed[i].ut, a_bed[i].u_rate);
    	cout << endl;
    	
	}
	return 0;
}
//��minnut����Сʱ��ʾ 
pair<int, string> to_hour(int minute) {
	pair<int, string> h_m;
	int h;
	string m;
	h = minute / 60;
	m = to_s(minute % 60);
	if(m.size() == 1) m = "0" + m;
	
	h_m = make_pair(h, m);
	return h_m;
}
//��int��ת��Ϊstring�� 
string to_s(int a) {
	stringstream ss;
	ss << a;
	string s = ss.str();
	
	return s;
}
