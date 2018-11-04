#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdlib>				//malloc函数在里面 
#include<cstdio>
#include<sstream>
using namespace std;

const int maxk = 100 + 10;
const int maxn = 10 + 10;
const int maxm = 30 + 10;

//病人 
struct patient {
	string name;		//名字 
	int ot, rt;			//手术时间，恢复时间 
	int room, bed;		//进入的手术室和恢复室编号 
	string r_b, r_e;	//手术室开始时间和结束时间 
	string b_b, b_e; 	// 恢复室开始时间和结束时间 
};
struct place {
	int id;				//手术室或恢复室id
	int st;				//下一次手术室和恢复室能安置病人的时间时刻 
	int ut;				//手术室或恢复室的使用时间 
	double u_rate;		//使用率 
}; 
map<int, int> in_b_st;	//编号映射病人开始进入恢复室的时间
map<int, int> p_r;		//病人编号映射手术室编号 

//st时间从小到大，若相同id从小到大 
bool cmp1(const place a, const place b) {
	if(a.st != b.st) return a.st < b.st;
	return a.id < b.id; 
}
bool cmp2(const int a, const int b) {
	if(in_b_st[a] != in_b_st[b]) return in_b_st[a] < in_b_st[b];
	return p_r[a] < p_r[b];
}
//id从小到大排 
bool cmp3(const place a, const place b) {
	return a.id < b.id;
}

pair<int, string> to_hour(int minute);					//把minnut化成小时表示 
string to_s(int a);										//把int型转换为string型 
//本题还可以考虑用优先队列 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, m, t1, t2, t3, k;							//手术室个数，恢复室个数，从手术室到恢复室时间，接待下一个病人手术室的准备时间，接待下一个病人恢复室的准备时间，病人个数 
	string T;											//T点钟准时开放手术室 
	while(cin >> n >> m >> T >> t1 >> t2 >> t3 >> k) {
		//cout << "1" << endl;
		//cout << n << " " << m << " " << T  << " " << t1 << " " << t2 << " " << t3 << " " << k << endl; 
		//存每个病人应该打印的信息 
		vector<int> pat[maxk];	
		//初始化手术室参数，编号从1开始
		vector<place> in_r;
		place room[n + 1];
		for(int i = 1; i <= n; i++) { room[i].id = i; room[i].st = room[i].ut = 0; in_r.push_back(room[i]);}		
		//for(int i = 1; i <= n; i++) { cout << room[i].id << endl;}	
		
		//读病人数据，编号从1开始 
		patient p[k + 1];
		for(int i = 1; i <= k; i++) { 
			getchar();
			getline(cin, p[i].name); 
			//cout << p[i].name << " ";
			cin >> p[i].ot >> p[i].rt;
			//cout << p[i].ot << " " << p[i].rt << endl;
		}
		//cout << "1" << endl;
		//病人进入手术室
		in_b_st.clear();
		p_r.clear();
		vector<int> in_b_i;			//后序要对此数组进行排序，表示病人进入恢复室时的编号顺序 
		for(int i = 1; i <= k; i++) {
			sort(in_r.begin(), in_r.end(), cmp1);																//对手术室排序，最小开始时间的手术室排在第一位，若是相同则按照id大小排序
			//cout << in_r[0].id << endl; 
			
			//此病人进入排序后在首位的手术室
			pat[i].push_back(in_r[0].id); pat[i].push_back(in_r[0].st);	pat[i].push_back(in_r[0].st + p[i].ot);	//在此病人存储信息处插入手术室id、手术开始时间，手术结束时间 
			in_b_st[i] = in_r[0].st + p[i].ot + t1;																//病人编号映射进入恢复室的时间时刻 
			in_b_i.push_back(i);
			p_r[i] = in_r[0].id;																				//病人编号映射手术室编号																	 
			
			//改变首位手术室的参数 
			in_r[0].st = in_r[0].st + p[i].ot + t2;																//下次可用时间时刻 
			in_r[0].ut += p[i].ot; 																				//记录使用时间
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
		//病人进入恢复室
		//for(int i = 0; i < in_b_i.size(); i++) cout << in_b_i[i] << " " << in_b_st[in_b_i[i]] << " " << p_r[in_b_i[i]] << endl;
		//cout << endl;
		sort(in_b_i.begin(), in_b_i.end(), cmp2);				//获得先后进入恢复室的病人顺序 
		//for(int i = 0; i < in_b_i.size(); i++) cout << in_b_i[i] << " " << in_b_st[in_b_i[i]] << " " << p_r[in_b_i[i]] << endl;
		vector<place> a_bed;									//存可用的恢复室床位
		int b_id = 1;											//存恢复室id 
		int max_t = 0;											//记录花费的最长时间，用来计算使用率 
		for(int i = 0; i < k; i++) {
			int num = in_b_i[i];								//病人编号 
			//sort(a_bed.begin(), a_bed.end(), cmp3);			//对可用的恢复床位进行排序 
			//寻找id最小的可用恢复室床位 		
			int pos = -1;
			for(int j = 0; j < a_bed.size(); j++) {
				//cout << a_bed[j].st << endl;
				if(a_bed[j].st <= (in_b_st[num] - t1)) {		//床位的下次可用时刻小于等于病人的刚结束手术的时刻 
					pos = j;									//可用床位的位置 
					break; 
				}
			} 
			
			//病人依次按顺序从a_bed挑选恢复室
			if(pos == -1) {										//如果床位空或者需要排队 
				//创建新床位给此病人用 
				place tmp;										
				tmp.id = b_id;									//设置床位id 
				tmp.st = in_b_st[num] + p[num].rt + t3;			//床位下次可以使用的时刻								
				tmp.ut = p[num].rt;								//此床位的使用时间
				a_bed.push_back(tmp);							//插入可使用床位的队列 
				
				pat[num].push_back(b_id);						//记录此病人进入的床位编号 
				pat[num].push_back(in_b_st[num]);				//进入恢复室时间 
				pat[num].push_back(in_b_st[num] + p[num].rt);	//离开恢复室时间 
				b_id++; 										//创建下一个新的床位的床位好 
			}else {												//pos位置处的床位可用
				//更新此位置处的床位信息
				a_bed[pos].st = in_b_st[num] + p[num].rt + t3;	//床位下次可以使用的时刻 
				a_bed[pos].ut += p[num].rt;						//此床位的累计使用时间	 
				
				pat[num].push_back(a_bed[pos].id); 				//记录此病人进入的床位编号
				pat[num].push_back(in_b_st[num]);				//进入恢复室时间 
				pat[num].push_back(in_b_st[num] + p[num].rt);	//离开恢复室时间 
			}
			max_t = max(max_t, in_b_st[num] + p[num].rt);		//最后一个病人结束的时间 
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
		//为打印做准备 
		int init_t;
		//将初始时间转换为int型，方便加减 
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
		//分别计算手术室和恢复室的使用率 
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
			if((i + 1) < b_id ) {	//b_id值指的是将创建的下一位床位的id
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
		//打印 
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
//把minnut化成小时表示 
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
//把int型转换为string型 
string to_s(int a) {
	stringstream ss;
	ss << a;
	string s = ss.str();
	
	return s;
}
