#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<cmath>
#include<cstring>
#include<algorithm>			
using namespace std;
const double EPS = 1e-7;

struct MAPS{
	int rank;					//��ϸ�ȼ� 
	double x1, y1, x2, y2;		//�Խ����� 
	double c_x, c_y;			//�������� 
	double rate_l_w;			//����� 
	double r_d_x, r_d_y;		//���½����� 
	
};

//ʹset�������� 
struct comp1{
    bool operator () (const double& x, const double& y) const{
		return x > y;	
    }
};

map<string, MAPS> name_m;					//��ͼ��ӳ�����	
set<double, comp1> area;						//����� 
map<double, vector<string> > s_name;		//���ӳ���ͼ�� 

map<string, vector<string> > l_name;		//����ӳ���ͼ�� 
//map<string, vector<double> > l_x_y;		//����ӳ��x,y���꣬vector�������һ��λ��Ϊx���ڶ���λ��Ϊy 
map<string, pair<double, double> > l_x_y;
pair<double, double> Qpos;					//��Ԫ�飬��.first��.second���� 

void print_fit( vector<string> v, string loc, int level); 
double dist( double x1, double y1, double x2, double y2);
 
//�����ж�ԭ������ 
bool comp2(const string A, const string B){
	//�����ͼ������� 
	double d1 = dist( name_m[ A].x1, name_m[ A].y1, Qpos.first, Qpos.second);
	double d2 = dist( name_m[ B].x1, name_m[ B].y1, Qpos.first, Qpos.second);
	if (fabs(d1 - d2) > EPS) return d1 < d2; 
	//��ͼ����Ⱦ����ӽ�0.75
	d1 = fabs( name_m[ A].rate_l_w - 0.75);  d2 = fabs( name_m[ B].rate_l_w - 0.75);
	if (fabs(d1 - d2) > EPS) return d1 < d2;
	//��ѯ�����͵�ͼ���½����������Զ
	d1 = dist( name_m[ A].r_d_x, name_m[ A].r_d_y, Qpos.first, Qpos.second);
	d2 = dist( name_m[ B].r_d_x, name_m[ B].r_d_y, Qpos.first, Qpos.second);
	if (fabs(d1 - d2) > EPS) return d1 < d2;
	//x������С
	return name_m[ A].x1 < name_m[ B].x1;
} 
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string line;
	getline( cin, line);		//��MAPS 
	
	//����MAPSָ�� 
	while( getline( cin, line) && line != "LOCATIONS"){
		stringstream ss( line); string name; double x1, y1, x2, y2; 
		ss >> name >> x1 >> y1 >> x2 >> y2;																//�����ͼ��Ϣ 
		//cout << line << endl;
		
		name_m[ name].x1 = x1; name_m[ name].y1 = y1; name_m[ name].x2 = x2; name_m[ name].y2 = y2;		//��Խ����� 
		name_m[ name].c_x = (x1 + x2) / 2; name_m[ name].c_y = (y1 + y2) / 2;							//���������� 
		double l = abs(x1 - x2); double w = abs(y1 - y2); name_m[ name].rate_l_w = l / w;				//�泤��� 
		name_m[ name].r_d_x = max(x1, x2); name_m[ name].r_d_y = min(y1, y2);							//�����½����� 
		
		double s = l * w; s_name[ s].push_back( name); area.insert( s);									//��������д��� 
 		
	} 
	
	// ����rank�����Բ���Ҫ�ˣ���Ϊ��ĿҪ�����ϸ�ȼ���˵�����ڵ�ͼ�ϵ���ϸ�ȼ������� 
	set<double>::iterator it; int r = 0; 
	for( it = area.begin(); it != area.end(); it++){
		r++;
		for( int i = 0; i < s_name[ *it].size(); i++){
			string tmp = s_name[ *it][ i]; 
			name_m[ tmp].rank = r;																		//����ϸ�ȼ� 

		}
		
	}
	/* 
	//���Խ�� 
	for( it = area.begin(); it != area.end(); it++){
		for( int i = 0; i < s_name[ *it].size(); i++){
			string tmp = s_name[ *it][ i]; 
			cout << tmp << " " << *it << " " << name_m[ tmp].rank << endl;													//��ͼ�����������ϸ�̶� 
			//cout << name_m[ tmp].x1 << " " << name_m[ tmp].y1 << " " << name_m[ tmp].x2 << " " << name_m[ tmp].y2 << endl;
			//cout << name_m[ tmp].c_x << " " << name_m[ tmp].c_y << endl << name_m[ tmp].rate_l_w << endl;
			//cout << name_m[ tmp].r_d_x << " " << name_m[ tmp].r_d_y << endl;
			
		}
		
	}
	*/ 
	
	//����LOCATIONSָ��
	while( getline( cin, line) && line != "REQUESTS"){
		stringstream ss( line); string loc; double x, y; 
		ss >> loc >> x >> y;																						//�������������� 
		//l_x_y[ loc].push_back( x); l_x_y[ loc].push_back( y);														//����ӳ��x,y 
		l_x_y[ loc] = make_pair(x, y); l_name[loc];
		
		//������ӳ���ͼ��������ʵ����ϸ�ȼ������� 
		set<double>::iterator it; 
		for( it = area.begin(); it != area.end(); it++){
			for( int i = 0; i < s_name[ *it].size(); i++){
				MAPS m = name_m[ s_name[ *it][i]];																	//�������Ӧ�ĵ�ͼ����
				double min_x = min( m.x1, m.x2), max_x = m.r_d_x, min_y = m.r_d_y, max_y = max( m.y1, m.y2); 		//����߽�� 
											
				if( x >= min_x && x <= max_x && y >= min_y && y <= max_y) l_name[ loc].push_back( s_name[ *it][i]);  //�ж��Ƿ���ͼ��	
				
			}
		
		}
		//cout << loc << " "; for( int i = 0; i < l_name[ loc].size(); i++) cout << l_name[ loc][i] << " "; cout << endl;
			
	} 
	
	//����REQUESTSָ��
	while( getline( cin, line) && line != "END"){
		stringstream ss( line); string loc; int level;
		ss >> loc >> level;
		
		if( l_name.count( loc) == 0) cout << loc << " at detail level " << level << " unknown location" << endl;					//����������
		else if( l_name[ loc].size() == 0) cout << loc << " at detail level " << level << " no map contains that location" << endl;	//û�е�ͼ����
		else{ 																														//�ڵ�ͼ�� 
			int num_r = 1;																			//��ϸ�ȼ�
			vector<string> q_level;																	//����ͬ��ϸ�ȼ��ĵ�ͼ�� 
			vector<string> l_level;																	//��ǰһ����ϸ�ȼ��ĵ�ͼ�� 
			Qpos = l_x_y[ loc];
			
			for( int i = 0; i < l_name[ loc].size(); i++){
				MAPS now_m, pre_m; if( i != 0){ now_m = name_m[ l_name[ loc][ i]]; pre_m = name_m[ l_name[ loc][ i-1]];}
		
				if( i != 0 && now_m.rank != pre_m.rank) num_r++; 
				if( num_r == level){ q_level.push_back( l_name[ loc][ i]); }						//����ϸ�ȼ���ͬ�ĵ�ͼ��
				if( num_r == level - 1){ l_level.push_back( l_name[ loc][ i]); } 					//��ǰһ����ϸ�ȼ���ͬ�ĵ�ͼ��
				
			}	
			//����ѡ������ʵĵ�ͼ 
			sort(q_level.begin(), q_level.end(), comp2);
			sort(l_level.begin(), l_level.end(), comp2);
			
			if( q_level.size() >= 1) cout << loc << " at detail level " << level << " using " << q_level[0] << endl;				//����ƥ�� 
			else{
				cout << loc << " at detail level " << level << " no map at that detail level; " << "using " << l_level[0] << endl;									//������ƥ�� 
		
			}
			
			
		}
		
		
	} 
	

	
	
	return 0;
} 
/*
//��ӡƥ��ĵ��� 
void print_fit( vector<string> v, string loc, int level){
	double x = l_x_y[ loc][0]; double y = l_x_y[ loc][1];
	double c_dist, r_d_dist; c_dist = r_d_dist = 9999999999.0;
	string result;
	
	//��ͼ���ĵ���ѯ��������С���� 
	int num_c = 1;
	for( int i = 0; i < v.size(); i++){
		double d = dist( x, y, name_m[ v[i]].c_x, name_m[ v[i]].c_y);
		if( d == c_dist){ num_c++;} 
		if( d < c_dist){ c_dist = d; result = v[i];} 
		
	}
	if( num_c == 1) cout << loc << " at detail level " << level << " using " << result << endl;
	else
	
	
}
*/ 
//���������� 
double dist( double x1, double y1, double x2, double y2){
	return sqrt( pow( (x1 -x2), 2) + pow( (y1 - y2), 2));
	
	
}

