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
	int rank;					//详细等级 
	double x1, y1, x2, y2;		//对角坐标 
	double c_x, c_y;			//中心坐标 
	double rate_l_w;			//长宽比 
	double r_d_x, r_d_y;		//右下角坐标 
	
};

//使set降序排序 
struct comp1{
    bool operator () (const double& x, const double& y) const{
		return x > y;	
    }
};

map<string, MAPS> name_m;					//地图名映射参数	
set<double, comp1> area;						//存面积 
map<double, vector<string> > s_name;		//面积映射地图名 

map<string, vector<string> > l_name;		//地名映射地图名 
//map<string, vector<double> > l_x_y;		//地名映射x,y坐标，vector数组里第一个位置为x，第二个位置为y 
map<string, pair<double, double> > l_x_y;
pair<double, double> Qpos;					//二元组，用.first和.second访问 

void print_fit( vector<string> v, string loc, int level); 
double dist( double x1, double y1, double x2, double y2);
 
//根据判断原则排序 
bool comp2(const string A, const string B){
	//距离地图中心最近 
	double d1 = dist( name_m[ A].x1, name_m[ A].y1, Qpos.first, Qpos.second);
	double d2 = dist( name_m[ B].x1, name_m[ B].y1, Qpos.first, Qpos.second);
	if (fabs(d1 - d2) > EPS) return d1 < d2; 
	//地图长宽比尽量接近0.75
	d1 = fabs( name_m[ A].rate_l_w - 0.75);  d2 = fabs( name_m[ B].rate_l_w - 0.75);
	if (fabs(d1 - d2) > EPS) return d1 < d2;
	//查询地名和地图右下角坐标距离最远
	d1 = dist( name_m[ A].r_d_x, name_m[ A].r_d_y, Qpos.first, Qpos.second);
	d2 = dist( name_m[ B].r_d_x, name_m[ B].r_d_y, Qpos.first, Qpos.second);
	if (fabs(d1 - d2) > EPS) return d1 < d2;
	//x坐标最小
	return name_m[ A].x1 < name_m[ B].x1;
} 
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string line;
	getline( cin, line);		//读MAPS 
	
	//处理MAPS指令 
	while( getline( cin, line) && line != "LOCATIONS"){
		stringstream ss( line); string name; double x1, y1, x2, y2; 
		ss >> name >> x1 >> y1 >> x2 >> y2;																//读入地图信息 
		//cout << line << endl;
		
		name_m[ name].x1 = x1; name_m[ name].y1 = y1; name_m[ name].x2 = x2; name_m[ name].y2 = y2;		//存对角坐标 
		name_m[ name].c_x = (x1 + x2) / 2; name_m[ name].c_y = (y1 + y2) / 2;							//存中心坐标 
		double l = abs(x1 - x2); double w = abs(y1 - y2); name_m[ name].rate_l_w = l / w;				//存长宽比 
		name_m[ name].r_d_x = max(x1, x2); name_m[ name].r_d_y = min(y1, y2);							//存右下角坐标 
		
		double s = l * w; s_name[ s].push_back( name); area.insert( s);									//对面积进行处理 
 		
	} 
	
	// 读入rank，可以不需要了，因为题目要求的详细等级是说地名在地图上的详细等级的排名 
	set<double>::iterator it; int r = 0; 
	for( it = area.begin(); it != area.end(); it++){
		r++;
		for( int i = 0; i < s_name[ *it].size(); i++){
			string tmp = s_name[ *it][ i]; 
			name_m[ tmp].rank = r;																		//存详细等级 

		}
		
	}
	/* 
	//测试结果 
	for( it = area.begin(); it != area.end(); it++){
		for( int i = 0; i < s_name[ *it].size(); i++){
			string tmp = s_name[ *it][ i]; 
			cout << tmp << " " << *it << " " << name_m[ tmp].rank << endl;													//地图名、面积、详细程度 
			//cout << name_m[ tmp].x1 << " " << name_m[ tmp].y1 << " " << name_m[ tmp].x2 << " " << name_m[ tmp].y2 << endl;
			//cout << name_m[ tmp].c_x << " " << name_m[ tmp].c_y << endl << name_m[ tmp].rate_l_w << endl;
			//cout << name_m[ tmp].r_d_x << " " << name_m[ tmp].r_d_y << endl;
			
		}
		
	}
	*/ 
	
	//处理LOCATIONS指令
	while( getline( cin, line) && line != "REQUESTS"){
		stringstream ss( line); string loc; double x, y; 
		ss >> loc >> x >> y;																						//读地名与其坐标 
		//l_x_y[ loc].push_back( x); l_x_y[ loc].push_back( y);														//地名映射x,y 
		l_x_y[ loc] = make_pair(x, y); l_name[loc];
		
		//将地名映射地图名，正好实现详细等级的排序 
		set<double>::iterator it; 
		for( it = area.begin(); it != area.end(); it++){
			for( int i = 0; i < s_name[ *it].size(); i++){
				MAPS m = name_m[ s_name[ *it][i]];																	//此面积对应的地图参数
				double min_x = min( m.x1, m.x2), max_x = m.r_d_x, min_y = m.r_d_y, max_y = max( m.y1, m.y2); 		//坐标边界点 
											
				if( x >= min_x && x <= max_x && y >= min_y && y <= max_y) l_name[ loc].push_back( s_name[ *it][i]);  //判断是否在图内	
				
			}
		
		}
		//cout << loc << " "; for( int i = 0; i < l_name[ loc].size(); i++) cout << l_name[ loc][i] << " "; cout << endl;
			
	} 
	
	//处理REQUESTS指令
	while( getline( cin, line) && line != "END"){
		stringstream ss( line); string loc; int level;
		ss >> loc >> level;
		
		if( l_name.count( loc) == 0) cout << loc << " at detail level " << level << " unknown location" << endl;					//地名不存在
		else if( l_name[ loc].size() == 0) cout << loc << " at detail level " << level << " no map contains that location" << endl;	//没有地图包含
		else{ 																														//在地图上 
			int num_r = 1;																			//详细等级
			vector<string> q_level;																	//存相同详细等级的地图名 
			vector<string> l_level;																	//存前一个详细等级的地图名 
			Qpos = l_x_y[ loc];
			
			for( int i = 0; i < l_name[ loc].size(); i++){
				MAPS now_m, pre_m; if( i != 0){ now_m = name_m[ l_name[ loc][ i]]; pre_m = name_m[ l_name[ loc][ i-1]];}
		
				if( i != 0 && now_m.rank != pre_m.rank) num_r++; 
				if( num_r == level){ q_level.push_back( l_name[ loc][ i]); }						//存详细等级相同的地图名
				if( num_r == level - 1){ l_level.push_back( l_name[ loc][ i]); } 					//存前一个详细等级相同的地图名
				
			}	
			//排序选出最合适的地图 
			sort(q_level.begin(), q_level.end(), comp2);
			sort(l_level.begin(), l_level.end(), comp2);
			
			if( q_level.size() >= 1) cout << loc << " at detail level " << level << " using " << q_level[0] << endl;				//存在匹配 
			else{
				cout << loc << " at detail level " << level << " no map at that detail level; " << "using " << l_level[0] << endl;									//不存在匹配 
		
			}
			
			
		}
		
		
	} 
	

	
	
	return 0;
} 
/*
//打印匹配的地名 
void print_fit( vector<string> v, string loc, int level){
	double x = l_x_y[ loc][0]; double y = l_x_y[ loc][1];
	double c_dist, r_d_dist; c_dist = r_d_dist = 9999999999.0;
	string result;
	
	//地图中心到查询地名的最小距离 
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
//求两点间距离 
double dist( double x1, double y1, double x2, double y2){
	return sqrt( pow( (x1 -x2), 2) + pow( (y1 - y2), 2));
	
	
}

